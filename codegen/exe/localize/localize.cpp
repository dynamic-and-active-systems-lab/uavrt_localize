//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: localize.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:32:45
//

// Include Files
#include "localize.h"
#include "angdiff.h"
#include "combineVectorElements.h"
#include "cosd.h"
#include "div.h"
#include "fileManager.h"
#include "localize_data.h"
#include "localize_initialize.h"
#include "localize_internal_types.h"
#include "localize_rtwutil.h"
#include "localizefrombearings.h"
#include "norm.h"
#include "readbearingcsv.h"
#include "rt_nonfinite.h"
#include "sind.h"
#include "strcmp.h"
#include "table.h"
#include "unique.h"
#include "vincentydistance.h"
#include "vincentyendpoint.h"
#include "coder_array.h"
#include "coder_platform.h"
#include <cmath>
#include <cstdio>
#include <cstring>

// Function Definitions
//
// LOCALIZE Estimates radio tag positions based on bearing files
//    This function determines tag positions based on bearing files that
//    contain the bearing to the tag and the lat/lons where those bearings
//    were measured. Calling functions pass the path to the bearing file
//    The output file contains three estimmated positions based on the 'MLE',
//    'RMR', or 'MEST' methods are described in the Length 1981 pape.
//    Methods implemented here are from:
//    Lenth, Russell. On Finding the Source of a Signal. Technometeric.
//    Vol. 23, No. 2, 1981.
//
//    MLE:  Maximum likely hood esitmator
//    RMR:  Repeated median regression
//    MEST: M-estimation with Andrews psi function with c = 1.5
//
//    Bearing file definitions can be found in the bearing_file_standard.txt
//    document.
//
// Arguments    : const coder::array<char, 2U> &bearingFilePath
// Return Type  : double
//
double localize(const coder::array<char, 2U> &bearingFilePath)
{
  static const char b_cv[13]{'p', 'o', 's', 'i', 't', 'i', 'o',
                             'n', 's', '.', 'c', 's', 'v'};
  std::FILE *f;
  coder::table b_bearingTable;
  coder::table bearingTable;
  coder::array<double, 2U> tagPositions_lat;
  coder::array<double, 2U> tagPositions_lon;
  coder::array<double, 1U> X;
  coder::array<double, 1U> Y;
  coder::array<double, 1U> a__1;
  coder::array<double, 1U> b_si;
  coder::array<double, 1U> b_theta_i;
  coder::array<double, 1U> ci_str;
  coder::array<double, 1U> si;
  coder::array<double, 1U> si_str;
  coder::array<double, 1U> theta_i;
  coder::array<double, 1U> xEast_m;
  coder::array<double, 1U> yNorth_m;
  coder::array<double, 1U> zi;
  coder::array<int, 2U> match_out;
  coder::array<int, 2U> matches;
  coder::array<unsigned int, 2U> sepInds;
  coder::array<unsigned int, 1U> tagIDs;
  coder::array<char, 2U> b_bearingFilePath;
  coder::array<boolean_T, 1U> r;
  coder::array<boolean_T, 1U> x;
  double pos[2002];
  double tagPosition_m[2];
  double result;
  double theSignEast;
  double theSignNorth;
  int b_loop_ub;
  int num_bears;
  int r1;
  boolean_T y;
  if (!isInitialized_localize) {
    localize_initialize();
  }
  //  INPUTS:
  // bearingFilepath - a char array of the path to the bearing file
  //  OUTPUTS:
  // return    -    a 0 if the function executed properly or -1 if it failed
  //
  // --------------------------------------------------------------------------
  //  Author: Michael Shafer
  //  Date: 2023-06-12
  // --------------------------------------------------------------------------
  readbearingcsv(bearingFilePath, bearingTable);
  coder::internal::b_strcmp(bearingTable.data.f2, x);
  y = (x.size(0) != 0);
  if (y) {
    boolean_T exitg1;
    r1 = 0;
    exitg1 = false;
    while ((!exitg1) && (r1 <= x.size(0) - 1)) {
      if (!x[r1]) {
        y = false;
        exitg1 = true;
      } else {
        r1++;
      }
    }
  }
  if (y) {
    std::printf("UAV-RT: Bearing file not found.");
    std::fflush(stdout);
    result = -1.0;
  } else {
    int i;
    int i1;
    int loop_ub;
    int r2;
    unsigned int u;
    signed char fileid;
    char pattern;
    // nBearings = size(bearingTable, 1);
    bearingTable.sortrows(b_bearingTable);
    coder::unique_vector(b_bearingTable.data.f1, tagIDs);
    tagPositions_lat.set_size(tagIDs.size(0), 3);
    r2 = tagIDs.size(0) * 3;
    tagPositions_lon.set_size(tagIDs.size(0), 3);
    for (i = 0; i < r2; i++) {
      tagPositions_lat[i] = 0.0;
      tagPositions_lon[i] = 0.0;
    }
    i = tagIDs.size(0);
    for (int b_i{0}; b_i < i; b_i++) {
      loop_ub = b_bearingTable.data.f1.size(0);
      x.set_size(b_bearingTable.data.f1.size(0));
      for (i1 = 0; i1 < loop_ub; i1++) {
        x[i1] = (tagIDs[b_i] == b_bearingTable.data.f1[i1]);
      }
      b_bearingTable.parenReference(x, bearingTable);
      if (bearingTable.data.f1.size(0) > 1) {
        double A[4];
        double tempOriginLat;
        double tempOriginLon;
        int c_i;
        tempOriginLat = coder::combineVectorElements(bearingTable.data.f5) /
                        static_cast<double>(bearingTable.data.f5.size(0));
        tempOriginLon = coder::combineVectorElements(bearingTable.data.f6) /
                        static_cast<double>(bearingTable.data.f6.size(0));
        // LATLON2EASTNORTH Convert listings of latitudes and longitudes to a
        // cartesian grid of east-north in meters.
        //    This functions will provide a the position in meters of the
        //    lat/lon positions provided as the second set of inputs relative
        //    the single lat/lon primary position entry based on the Vicenty
        //    distance equation.
        //
        // INPUTS:
        //    lat1 - 1 x 1 latitude of origin
        //    lon1 - 1 x 1 longitude of origin
        //    lat2 - n x 1 latitude vector of positions to measure to
        //    lon2 - n x 1 longitude vector of positions to measure to
        //
        // OUTPUTS:
        //    xEast_m     - n x 1 Position in meters East of the lat/lon2
        //    entries
        //                  from the origin position
        //    yNorth_m    - n x 1 Position in meters North of the lat/lon2
        //    entries
        //                  from the origin position
        //    range_m     - n x 1 range in meters of the lat/lon2 entries
        //                  from the origin position
        //    bearing_deg - n x 1 bearing angle degrees off true North of the
        //                  lat/lon2 entries from the origin position
        //
        // --------------------------------------------------------------------------
        //  Author: Michael Shafer
        //  Date: 2023-06-12
        // --------------------------------------------------------------------------
        xEast_m.set_size(bearingTable.data.f5.size(0));
        loop_ub = bearingTable.data.f5.size(0);
        yNorth_m.set_size(bearingTable.data.f5.size(0));
        for (i1 = 0; i1 < loop_ub; i1++) {
          xEast_m[i1] = 0.0;
          yNorth_m[i1] = 0.0;
        }
        if (bearingTable.data.f5.size(0) != bearingTable.data.f6.size(0)) {
          std::printf("UAV-RT: Secondary latitudes must have name number of "
                      "elements as secondary longitudes.");
          std::fflush(stdout);
        } else {
          i1 = bearingTable.data.f5.size(0);
          xEast_m.set_size(bearingTable.data.f5.size(0));
          yNorth_m.set_size(bearingTable.data.f5.size(0));
          for (c_i = 0; c_i < i1; c_i++) {
            // X east
            theSignEast =
                coder::angdiff(tempOriginLon, bearingTable.data.f6[c_i]);
            if (!std::isnan(theSignEast)) {
              if (theSignEast < 0.0) {
                theSignEast = -1.0;
              } else {
                theSignEast = (theSignEast > 0.0);
              }
            }
            theSignNorth =
                coder::angdiff(tempOriginLat, bearingTable.data.f5[c_i]);
            if (!std::isnan(theSignNorth)) {
              if (theSignNorth < 0.0) {
                theSignNorth = -1.0;
              } else {
                theSignNorth = (theSignNorth > 0.0);
              }
            }
            xEast_m[c_i] =
                theSignEast * vincentydistance(tempOriginLat, tempOriginLon,
                                               tempOriginLat,
                                               bearingTable.data.f6[c_i]);
            yNorth_m[c_i] =
                theSignNorth * vincentydistance(tempOriginLat, tempOriginLon,
                                                bearingTable.data.f5[c_i],
                                                tempOriginLon);
            // range1  = sqrt( xEast^2 + yNorth^2 );
            // bearing_deg = 180/pi * atan2(xEast, yNorth);
            // Calculate bearing from 1 to 2
            theSignEast = bearingTable.data.f5[c_i];
            coder::b_cosd(theSignEast);
            theSignNorth = bearingTable.data.f6[c_i] - tempOriginLon;
            theSignEast = theSignNorth;
            coder::b_sind(theSignEast);
            theSignEast = tempOriginLat;
            coder::b_cosd(theSignEast);
            theSignEast = bearingTable.data.f5[c_i];
            coder::b_sind(theSignEast);
            theSignEast = tempOriginLat;
            coder::b_sind(theSignEast);
            coder::b_cosd(theSignNorth);
            // rangecheck = (range1-range)/range
          }
        }
        //  figure
        //  plot(0,0,'g*','Markersize',20); hold on
        //  for j = 1:numel(xEast_m)
        //      plot(xEast_m(j),yNorth_m(j),'r.','Markersize',20); hold on
        //  end
        //  axis equal
        //
        // quiver(xEast_m, yNorth_m, sind(measuredBearings),
        // cosd(measuredBearings));
        X.set_size(xEast_m.size(0));
        loop_ub = xEast_m.size(0);
        Y.set_size(yNorth_m.size(0));
        for (i1 = 0; i1 < loop_ub; i1++) {
          X[i1] = xEast_m[i1];
          Y[i1] = yNorth_m[i1];
        }
        theta_i.set_size(bearingTable.data.f3.size(0));
        loop_ub = bearingTable.data.f3.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          theta_i[i1] = bearingTable.data.f3[i1];
        }
        // LOCALIZE estimates a location based on a series of bearing estimates
        // using localization methods presented in Lenth's 1972 paper cited
        // below. The methods include MLE with, repeated median regression, and
        // an M-estimator. The outputs is an x-y vector of estimated position
        // found through the method requested. NOTE: Lenth uses X (East) and Y
        // (North) position and bearing angles as compass headings, which are
        // positive CW from North. This program stays consistent with this
        // notation and the X and Y positions, should be the East and North
        // positions from which the bearings were measured. This may conflict
        // with the frames used by the program calling localize. If the X-North
        // Y-East coordinate frame is used, x and y positions entered to this
        // function can simply be switched, and the output positions should also
        // then be switched.
        //  INPUTS:
        // X           -    n x 1 vector of x-location where pulse_sig was
        // measured.
        //                        X here is distance East "
        // Y           -    n x 1 vector of y-location where pulse_sig was
        // measured T           -    n x 1 vector of bearing angles in DEGREES
        // from North with
        //                        positive in CW direction. Standard compass
        //                        bearing.
        // method      -    a char array of selected method:
        //                    Options are 'MLE', 'RMR', or 'MEST'
        //  OUTPUTS:
        // position    -    1 x 2 estimate of [x,y] location of signal origin
        // Methods implemented here are from
        // Lenth, Russell. On Finding the Source of a Signal. Technometeric.
        // Vol. 23, No. 2, 1981. MLE: Maximum likely hood esitmator RMR:
        // Repeated median regression MEST: M-estimation with Andrews psi
        // function with c = 1.5 Make sure these are all column vectors
        if ((xEast_m.size(0) == yNorth_m.size(0)) &&
            (xEast_m.size(0) == bearingTable.data.f3.size(0))) {
          // Eliminate any that have NaN X, Y, or T values.
          if (xEast_m.size(0) == 1) {
            i1 = yNorth_m.size(0);
          } else {
            i1 = xEast_m.size(0);
          }
          if ((xEast_m.size(0) == yNorth_m.size(0)) &&
              (i1 == bearingTable.data.f3.size(0))) {
            r.set_size(xEast_m.size(0));
            loop_ub = xEast_m.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r[i1] =
                  ((!std::isnan(xEast_m[i1])) && (!std::isnan(yNorth_m[i1])) &&
                   (!std::isnan(bearingTable.data.f3[i1])));
            }
          } else {
            b_binary_expand_op(r, xEast_m, yNorth_m, bearingTable);
          }
          r1 = r.size(0) - 1;
          r2 = 0;
          for (c_i = 0; c_i <= r1; c_i++) {
            if (r[c_i]) {
              r2++;
            }
          }
          X.set_size(r2);
          r2 = 0;
          for (c_i = 0; c_i <= r1; c_i++) {
            if (r[c_i]) {
              X[r2] = xEast_m[c_i];
              r2++;
            }
          }
          r2 = 0;
          for (c_i = 0; c_i <= r1; c_i++) {
            if (r[c_i]) {
              r2++;
            }
          }
          Y.set_size(r2);
          r2 = 0;
          for (c_i = 0; c_i <= r1; c_i++) {
            if (r[c_i]) {
              Y[r2] = yNorth_m[c_i];
              r2++;
            }
          }
          r2 = 0;
          for (c_i = 0; c_i <= r1; c_i++) {
            if (r[c_i]) {
              r2++;
            }
          }
          theta_i.set_size(r2);
          r2 = 0;
          for (c_i = 0; c_i <= r1; c_i++) {
            if (r[c_i]) {
              theta_i[r2] = bearingTable.data.f3[c_i];
              r2++;
            }
          }
          num_bears = 0;
          for (c_i = 0; c_i <= r1; c_i++) {
            if (r[c_i]) {
              num_bears++;
            }
          }
        } else {
          // Check to see that vectors are same length
        }
        // Standardize the shape of all the input vectors
        X.set_size(num_bears);
        Y.set_size(num_bears);
        theta_i.set_size(num_bears);
        //  %Prep some variables that will be needed for RMR
        //  if strcmp(method,'RMR')
        //      %Create the element selection vectors
        //      %This creates the list of all combintations
        //      bc = nchoosek(1:num_bears,2);
        //      bcA = bc(:,1);
        //      bcB = bc(:,2);
        //      %Generate the positions and angles of the different selected
        //      elements for %comparison: A vs B. XA = X(bcA); XB = X(bcB); YA =
        //      Y(bcA); YB = Y(bcB); TA = T(bcA); TB = T(bcB); %Find the
        //      intersection points for all the A and B lines X_int = (YA - YB +
        //      XB.*cotd(TB) - XA.*cotd(TA))./(cotd(TB)-cotd(TA)); Y_int =
        //      cotd(TA).*X_int+YA-XA.*cotd(TA); %Some test cases had a few NaN
        //      locations, so only track those that have no %NaNs either X_int
        //      and Y_int. We redefine everything here to rid the record %of
        //      those points. valid_pos_msk = ~isnan(X_int)&~isnan(Y_int); X_int
        //      = X_int(valid_pos_msk); Y_int = Y_int(valid_pos_msk);
        //  end
        //  MAXIMUM LIKELYHOOD ESTIMATOR
        for (i1 = 0; i1 < num_bears; i1++) {
          theta_i[i1] = 0.017453292519943295 * (90.0 - theta_i[i1]);
        }
        // On page 1, paragraph of the Lenth paper.
        //  Lenth says x is E and y is N, but we use x N and y E,
        si.set_size(theta_i.size(0));
        loop_ub = theta_i.size(0);
        for (r1 = 0; r1 < loop_ub; r1++) {
          si[r1] = std::sin(theta_i[r1]);
          theta_i[r1] = std::cos(theta_i[r1]);
        }
        if ((si.size(0) == num_bears) && (theta_i.size(0) == num_bears)) {
          zi.set_size(si.size(0));
          loop_ub = si.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            zi[i1] = si[i1] * X[i1] - theta_i[i1] * Y[i1];
          }
        } else {
          binary_expand_op(zi, si, X, theta_i, Y);
        }
        std::memset(&pos[0], 0, 2002U * sizeof(double));
        if (theta_i.size(0) == si.size(0)) {
          a__1.set_size(theta_i.size(0));
          loop_ub = theta_i.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            a__1[i1] = theta_i[i1] * si[i1];
          }
        } else {
          times(a__1, theta_i, si);
        }
        b_si.set_size(si.size(0));
        loop_ub = si.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_si[i1] = si[i1] * si[i1];
        }
        theSignNorth = coder::combineVectorElements(b_si);
        b_theta_i.set_size(theta_i.size(0));
        loop_ub = theta_i.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_theta_i[i1] = theta_i[i1] * theta_i[i1];
        }
        A[0] = theSignNorth;
        theSignEast = -coder::combineVectorElements(a__1);
        A[2] = theSignEast;
        A[1] = theSignEast;
        A[3] = coder::combineVectorElements(b_theta_i);
        if ((si.size(0) == zi.size(0)) && (theta_i.size(0) == zi.size(0))) {
          b_si.set_size(si.size(0));
          loop_ub = si.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_si[i1] = si[i1] * zi[i1];
          }
          b_theta_i.set_size(theta_i.size(0));
          loop_ub = theta_i.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_theta_i[i1] = theta_i[i1] * zi[i1];
          }
          tagPosition_m[0] = coder::combineVectorElements(b_si);
          tagPosition_m[1] = -coder::combineVectorElements(b_theta_i);
        } else {
          binary_expand_op(tagPosition_m, si, zi, theta_i);
        }
        if (std::abs(theSignEast) > std::abs(theSignNorth)) {
          r1 = 1;
          r2 = 0;
        } else {
          r1 = 0;
          r2 = 1;
        }
        theSignEast = A[r2] / A[r1];
        theSignNorth = A[r1 + 2];
        pos[1] = (tagPosition_m[r2] - tagPosition_m[r1] * theSignEast) /
                 (A[r2 + 2] - theSignEast * theSignNorth);
        pos[0] = (tagPosition_m[r1] - pos[1] * theSignNorth) / A[r1];
        c_i = 1;
        theSignEast = 1.0;
        while ((theSignEast > 0.001) && (c_i <= 1000)) {
          double b_pos[2];
          r2 = (c_i - 1) << 1;
          theSignEast = pos[r2];
          ci_str.set_size(X.size(0));
          loop_ub = X.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            ci_str[i1] = theSignEast - X[i1];
          }
          theSignEast = pos[r2 + 1];
          si_str.set_size(Y.size(0));
          loop_ub = Y.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            si_str[i1] = theSignEast - Y[i1];
          }
          if (ci_str.size(0) == si_str.size(0)) {
            a__1.set_size(ci_str.size(0));
            loop_ub = ci_str.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              theSignEast = ci_str[i1];
              theSignNorth = si_str[i1];
              a__1[i1] =
                  theSignEast * theSignEast + theSignNorth * theSignNorth;
            }
          } else {
            binary_expand_op(a__1, ci_str, si_str);
          }
          r2 = a__1.size(0);
          for (r1 = 0; r1 < r2; r1++) {
            a__1[r1] = std::sqrt(a__1[r1]);
          }
          loop_ub = a__1.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            theSignEast = a__1[i1];
            a__1[i1] = rt_powd_snf(theSignEast, 3.0);
          }
          if (si_str.size(0) == a__1.size(0)) {
            loop_ub = si_str.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              si_str[i1] = si_str[i1] / a__1[i1];
            }
          } else {
            rdivide(si_str, a__1);
          }
          if (ci_str.size(0) == a__1.size(0)) {
            loop_ub = ci_str.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              ci_str[i1] = ci_str[i1] / a__1[i1];
            }
          } else {
            rdivide(ci_str, a__1);
          }
          if ((si.size(0) == si_str.size(0)) &&
              (theta_i.size(0) == si_str.size(0)) &&
              (si.size(0) == ci_str.size(0)) &&
              (theta_i.size(0) == ci_str.size(0))) {
            b_si.set_size(si.size(0));
            loop_ub = si.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_si[i1] = si[i1] * si_str[i1];
            }
            b_theta_i.set_size(theta_i.size(0));
            loop_ub = theta_i.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_theta_i[i1] = theta_i[i1] * si_str[i1];
            }
            theSignNorth = coder::combineVectorElements(b_si);
            theSignEast = coder::combineVectorElements(b_theta_i);
            b_si.set_size(si.size(0));
            loop_ub = si.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_si[i1] = si[i1] * ci_str[i1];
            }
            b_theta_i.set_size(theta_i.size(0));
            loop_ub = theta_i.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_theta_i[i1] = theta_i[i1] * ci_str[i1];
            }
            A[0] = theSignNorth;
            A[2] = -theSignEast;
            A[1] = -coder::combineVectorElements(b_si);
            A[3] = coder::combineVectorElements(b_theta_i);
          } else {
            binary_expand_op(A, si, si_str, theta_i, ci_str);
          }
          if ((si_str.size(0) == zi.size(0)) &&
              (ci_str.size(0) == zi.size(0))) {
            loop_ub = si_str.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              si_str[i1] = si_str[i1] * zi[i1];
            }
            loop_ub = ci_str.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              ci_str[i1] = ci_str[i1] * zi[i1];
            }
            tagPosition_m[0] = coder::combineVectorElements(si_str);
            tagPosition_m[1] = -coder::combineVectorElements(ci_str);
          } else {
            binary_expand_op(tagPosition_m, si_str, zi, ci_str);
          }
          if (std::abs(A[1]) > std::abs(A[0])) {
            r1 = 1;
            r2 = 0;
          } else {
            r1 = 0;
            r2 = 1;
          }
          theSignEast = A[r2] / A[r1];
          loop_ub = c_i << 1;
          theSignNorth = A[r1 + 2];
          pos[loop_ub + 1] =
              (tagPosition_m[r2] - tagPosition_m[r1] * theSignEast) /
              (A[r2 + 2] - theSignEast * theSignNorth);
          pos[loop_ub] =
              (tagPosition_m[r1] - pos[loop_ub + 1] * theSignNorth) / A[r1];
          c_i++;
          r2 = (c_i - 1) << 1;
          r1 = (c_i - 2) << 1;
          b_pos[0] = pos[r2] - pos[r1];
          b_pos[1] = pos[r2 + 1] - pos[r1 + 1];
          theSignEast = coder::b_norm(b_pos);
        }
        if (c_i == 1000) {
          tagPosition_m[0] = rtNaN;
          tagPosition_m[1] = rtNaN;
        } else {
          r2 = (c_i - 1) << 1;
          tagPosition_m[0] = pos[r2];
          tagPosition_m[1] = pos[r2 + 1];
        }
        // disp(['loc_error_MLE = ',num2str(norm(pos_MLE))])
        //  REPEATED MEDIAN REGRESSION
        // plot(tagPosition_m(1),tagPosition_m(2),'k.','Markersize',20); hold on
        tagPositions_lat[b_i] = vincentyendpoint(
            tempOriginLat, tempOriginLon,
            57.295779513082323 *
                rt_atan2d_snf(tagPosition_m[0], tagPosition_m[1]),
            coder::b_norm(tagPosition_m), &tagPositions_lon[b_i]);
        si_str.set_size(xEast_m.size(0));
        loop_ub = xEast_m.size(0) - 1;
        for (i1 = 0; i1 <= loop_ub; i1++) {
          si_str[i1] = xEast_m[i1];
        }
        X.set_size(yNorth_m.size(0));
        loop_ub = yNorth_m.size(0) - 1;
        for (i1 = 0; i1 <= loop_ub; i1++) {
          X[i1] = yNorth_m[i1];
        }
        Y.set_size(bearingTable.data.f3.size(0));
        loop_ub = bearingTable.data.f3.size(0) - 1;
        for (i1 = 0; i1 <= loop_ub; i1++) {
          Y[i1] = bearingTable.data.f3[i1];
        }
        localizefrombearings(si_str, X, Y, tagPosition_m);
        // plot(tagPosition_m(1),tagPosition_m(2),'k.','Markersize',20); hold on
        tagPositions_lat[b_i + tagPositions_lat.size(0)] = vincentyendpoint(
            tempOriginLat, tempOriginLon,
            57.295779513082323 *
                rt_atan2d_snf(tagPosition_m[0], tagPosition_m[1]),
            coder::b_norm(tagPosition_m),
            &tagPositions_lon[b_i + tagPositions_lon.size(0)]);
        b_localizefrombearings(xEast_m, yNorth_m, bearingTable.data.f3,
                               tagPosition_m);
        // plot(tagPosition_m(1),tagPosition_m(2),'k.','Markersize',20); hold on
        tagPositions_lat[b_i + tagPositions_lat.size(0) * 2] = vincentyendpoint(
            tempOriginLat, tempOriginLon,
            57.295779513082323 *
                rt_atan2d_snf(tagPosition_m[0], tagPosition_m[1]),
            coder::b_norm(tagPosition_m),
            &tagPositions_lon[b_i + tagPositions_lon.size(0) * 2]);
      } else {
        tagPositions_lat[b_i] = rtNaN;
        tagPositions_lon[b_i] = rtNaN;
        tagPositions_lat[b_i + tagPositions_lat.size(0)] = rtNaN;
        tagPositions_lon[b_i + tagPositions_lon.size(0)] = rtNaN;
        tagPositions_lat[b_i + tagPositions_lat.size(0) * 2] = rtNaN;
        tagPositions_lon[b_i + tagPositions_lon.size(0) * 2] = rtNaN;
      }
    }
    y = coderIsPC();
    if (y) {
      pattern = '\\';
    } else {
      pattern = '/';
    }
    if (bearingFilePath.size(1) == 0) {
      sepInds.set_size(1, 0);
    } else {
      r2 = bearingFilePath.size(1);
      matches.set_size(1, bearingFilePath.size(1));
      r1 = 0;
      for (int b_i{0}; b_i < r2; b_i++) {
        if (bearingFilePath[b_i] == pattern) {
          matches[r1] = b_i + 1;
          r1++;
        }
      }
      match_out.set_size(1, r1);
      for (int b_i{0}; b_i < r1; b_i++) {
        match_out[b_i] = matches[b_i];
      }
      sepInds.set_size(1, match_out.size(1));
      loop_ub = match_out.size(1);
      for (i = 0; i < loop_ub; i++) {
        sepInds[i] = static_cast<unsigned int>(match_out[i]);
      }
    }
    u = sepInds[sepInds.size(1) - 1];
    if (u + 1U > static_cast<unsigned int>(bearingFilePath.size(1))) {
      i = 0;
      i1 = 0;
    } else {
      i = static_cast<int>(u);
      i1 = bearingFilePath.size(1);
    }
    if (static_cast<int>(u) - 1 < 1) {
      loop_ub = 1;
    } else {
      loop_ub = static_cast<int>(u);
    }
    y = coderIsPC();
    b_bearingFilePath.set_size(1, loop_ub + 13);
    for (r1 = 0; r1 <= loop_ub - 2; r1++) {
      b_bearingFilePath[r1] = bearingFilePath[r1];
    }
    if (y) {
      b_bearingFilePath[loop_ub - 1] = '\\';
    } else {
      b_bearingFilePath[loop_ub - 1] = '/';
    }
    for (r1 = 0; r1 < 13; r1++) {
      b_bearingFilePath[r1 + loop_ub] = b_cv[r1];
    }
    fileid = coder::internal::cfopen(b_bearingFilePath, "wb");
    if (fileid == -1) {
      std::printf("UAV-RT: Error creating the positions csv file.");
      std::fflush(stdout);
      result = -1.0;
    } else {
      //  for i = 1:nTags
      //      fprintf(fid, total_fspec, tagIDs(i),...
      //                                bearingFileName,...
      //                                tagPositions_lat(i), ...
      //                                tagPositions_lon(i));
      //  end
      r1 = tagIDs.size(0);
      if (tagIDs.size(0) - 1 >= 0) {
        num_bears = i1 - i;
        b_loop_ub = num_bears;
      }
      for (int b_i{0}; b_i < r1; b_i++) {
        b_bearingFilePath.set_size(1, num_bears + 1);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          b_bearingFilePath[i1] = bearingFilePath[i + i1];
        }
        b_bearingFilePath[num_bears] = '\x00';
        f = coder::internal::getfilestar(static_cast<double>(fileid), y);
        if (!(f == nullptr)) {
          std::fprintf(f, "%u,%s,", tagIDs[b_i], &b_bearingFilePath[0]);
          if (y) {
            std::fflush(f);
          }
        }
        f = coder::internal::getfilestar(static_cast<double>(fileid), y);
        if (!(f == nullptr)) {
          std::fprintf(f, "%f,%f,", tagPositions_lat[b_i],
                       tagPositions_lon[b_i]);
          if (y) {
            std::fflush(f);
          }
        }
        f = coder::internal::getfilestar(static_cast<double>(fileid), y);
        if (!(f == nullptr)) {
          std::fprintf(f, "%f,%f,",
                       tagPositions_lat[b_i + tagPositions_lat.size(0)],
                       tagPositions_lon[b_i + tagPositions_lon.size(0)]);
          if (y) {
            std::fflush(f);
          }
        }
        f = coder::internal::getfilestar(static_cast<double>(fileid), y);
        if (!(f == nullptr)) {
          std::fprintf(f, "%f,%f,",
                       tagPositions_lat[b_i + tagPositions_lat.size(0) * 2],
                       tagPositions_lon[b_i + tagPositions_lon.size(0) * 2]);
          if (y) {
            std::fflush(f);
          }
        }
        f = coder::internal::getfilestar(static_cast<double>(fileid), y);
        if (!(f == nullptr)) {
          std::fprintf(f, "\n");
          if (y) {
            std::fflush(f);
          }
        }
      }
      coder::internal::cfclose(static_cast<double>(fileid));
      result = 0.0;
    }
  }
  return result;
}

//
// File trailer for localize.cpp
//
// [EOF]
//
