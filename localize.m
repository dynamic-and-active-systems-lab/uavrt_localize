function [result] = localize(bearingFilePath)
%LOCALIZE Estimates radio tag positions based on bearing files 
%   This function determines tag positions based on bearing files that
%   contain the bearing to the tag and the lat/lons where those bearings
%   were measured. Calling functions pass the path to the bearing file
%   The output file contains three estimmated positions based on the 'MLE', 
%   'RMR', or 'MEST' methods are described in the Length 1981 pape.
%   Methods implemented here are from:
%   Lenth, Russell. On Finding the Source of a Signal. Technometeric. 
%   Vol. 23, No. 2, 1981. 
%
%   MLE:  Maximum likely hood esitmator
%   RMR:  Repeated median regression
%   MEST: M-estimation with Andrews psi function with c = 1.5
%   
%   Bearing file definitions can be found in the bearing_file_standard.txt
%   document.

% INPUTS:
%bearingFilepath - a char array of the path to the bearing file

% OUTPUTS:
%return    -    a 0 if the function executed properly or -1 if it failed
%
%--------------------------------------------------------------------------
% Author: Michael Shafer
% Date: 2023-06-12
%--------------------------------------------------------------------------
%--------------------------------------------------------------------------

[bearingTable] = readbearingcsv(bearingFilePath);

if strcmp(bearingTable.parentFileName, 'File not found') 
    fprintf('UAV-RT: Bearing file not found.')
    result = -1;
    return
end
    
%nBearings = size(bearingTable, 1);

bearingTable = sortrows(bearingTable,{'tagID','time_start_s'});

tagIDs = unique(bearingTable.tagID);

nTags = numel(tagIDs);

currLat = 0;

currLon = 0;

tempOriginLat = 0;

tempOriginLon = 0;

tagPosition_m = zeros(2,1);

methods = {'MLE', 'RMR' ,'MEST'};

nMethods = numel(methods);

tagPositions_lat = zeros(nTags, nMethods);

tagPositions_lon = zeros(nTags, nMethods);

for i = 1:nTags
    currTagID = tagIDs(i);

    rowsOfCurrTagLogic = (currTagID == bearingTable.tagID);

    subTable = bearingTable(rowsOfCurrTagLogic, :);
    
    measuredBearings = subTable.bearing;

    nCurrBearings = size(subTable, 1);

    if nCurrBearings > 1
        currLat = subTable.latitude_deg;

        currLon = subTable.longitude_deg;

        tempOriginLat = mean(currLat, "all");

        tempOriginLon = mean(currLon, "all");
    
        [xEast_m , yNorth_m, ~, ~] = ...
            latlon2eastnorth(tempOriginLat, tempOriginLon,...
            currLat, currLon);

        % figure
        % plot(0,0,'g*','Markersize',20); hold on
        % for j = 1:numel(xEast_m)
        %     plot(xEast_m(j),yNorth_m(j),'r.','Markersize',20); hold on
        % end
        % axis equal
        % 
        %quiver(xEast_m, yNorth_m, sind(measuredBearings), cosd(measuredBearings));
        
        for j = 1:nMethods
            tagPosition_m = localizefrombearings(xEast_m, yNorth_m, measuredBearings, methods{j});
            %plot(tagPosition_m(1),tagPosition_m(2),'k.','Markersize',20); hold on

            tagRange_m = norm(tagPosition_m);

            tagBearing_deg = 180/pi*atan2(tagPosition_m(1), tagPosition_m(2));

            [tagPositions_lat(i, j), tagPositions_lon(i, j)] = vincentyendpoint(tempOriginLat, tempOriginLon, tagBearing_deg, tagRange_m);
        end

    else
        tagPositions_lat(i, : ) = NaN;

        tagPositions_lon(i, :) = NaN;
    end
end

tag_id_fspec = '%u';
parentFileName_fspec = '%s';
latitude_fspec = '%f';
longitude_fspec = '%f';

d = ',';

info_fspec = [tag_id_fspec, d, ...
               parentFileName_fspec, d];

latlon_fspec = [ latitude_fspec, d, longitude_fspec, d];

sepInds = strfind(bearingFilePath, filesep);

bearingFileName = bearingFilePath(sepInds(end)+1:end);

bearingFileDirectory = bearingFilePath(1:sepInds(end)-1);

positionFilePath = [bearingFileDirectory, filesep, 'positions.csv'];

fid = fopen(positionFilePath,'w');

if fid == -1
    fprintf('UAV-RT: Error creating the positions csv file.')
    result = -1;
    return
end

% for i = 1:nTags
%     fprintf(fid, total_fspec, tagIDs(i),...
%                               bearingFileName,...
%                               tagPositions_lat(i), ...
%                               tagPositions_lon(i));
% end

for i = 1:nTags
    fprintf(fid, info_fspec, tagIDs(i),...
                              bearingFileName);
    for j = 1:nMethods
    fprintf(fid, latlon_fspec,tagPositions_lat(i, j), ...
                              tagPositions_lon(i, j));
    end
    fprintf(fid,'\n');
end

fclose(fid);

result = 0;