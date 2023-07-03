//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: readbearingcsv.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:18:22
//

// Include Files
#include "readbearingcsv.h"
#include "anonymous_function.h"
#include "fgetl.h"
#include "fileManager.h"
#include "ftell.h"
#include "localize_data.h"
#include "localize_internal_types.h"
#include "onCleanup.h"
#include "rowNamesDim.h"
#include "rt_nonfinite.h"
#include "str2double.h"
#include "table.h"
#include "varNamesDim.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cmath>
#include <cstdio>

// Function Definitions
//
// READBEARINGCSV Reads in a bearing csv file and outputs the file as a
// MATLAB table.
//    This function reads a bearing csv file and converts the file to a
//    MATLAB table wit the following headings:
//
//    1 - TagID
//    2 - Filename of parent pulse file
//    3 - Bearing angle in degrees
//    4 - Tau value
//    5 - lat in deg
//    6 - lon in deg
//    7 - alt AGL in m
//    8 - alt ASL in m
//    9 - start time of bearing measurements in s
//    10 - end time of bearing measurements in s
//
// INPUTS:
//    filePath - char array of the path to the file
//
// OUPUTS:
//    tableOut - Matlab table with the columns specified above.
//
// --------------------------------------------------------------------------
//  Author: Michael Shafer
//  Date: 2023-06-12
// --------------------------------------------------------------------------
// --------------------------------------------------------------------------
//
// Arguments    : const coder::array<char, 2U> &filePath
//                coder::table &tableOut
// Return Type  : void
//
void readbearingcsv(const coder::array<char, 2U> &filePath,
                    coder::table &tableOut)
{
  int wherefrom;
  std::FILE *filestar;
  coder::onCleanup x;
  coder::array<double, 2U> alt_AGL_inds;
  coder::array<double, 2U> alt_ASL_inds;
  coder::array<double, 2U> bearing_inds;
  coder::array<double, 2U> lat_inds;
  coder::array<double, 2U> lineLocs;
  coder::array<double, 2U> lon_inds;
  coder::array<double, 2U> parentFileName_inds;
  coder::array<double, 2U> tau_inds;
  coder::array<double, 2U> time_end_inds;
  coder::array<double, 2U> time_start_inds;
  coder::array<unsigned int, 2U> commaInds;
  coder::array<int, 2U> matches;
  coder::array<int, 2U> tagID_inds;
  coder::array<char, 2U> b_lineStr;
  coder::array<char, 2U> lineStr;
  cell_wrap_4 r;
  signed char fileid;
  boolean_T a;
  fileid = coder::internal::cfopen(filePath, "rb");
  if (fileid != -1) {
    double b_i;
    double d;
    int i;
    int match_idx;
    int text_len;
    signed char b_fileid;
    // nLines = countlines(filePath);
    // GETTEXTFILELINELOCS returns the locations in the a text file of the
    // beginning of each line. Empty lines are not included in the listing.
    //
    // INPUTS:
    //    fname - char array of file path to be read
    // OUTPUTS:
    //    lineLocRecord - 1 x n vector of locations of lines with text
    //
    // --------------------------------------------------------------------------
    //  Author: Michael Shafer
    //  Date: 2023-06-12
    // --------------------------------------------------------------------------
    b_fileid = coder::internal::cfopen(filePath, "rb");
    x.task.workspace.fid = b_fileid;
    x.matlabCodegenIsDeleted = false;
    lineLocs.set_size(1, 0);
    b_i = 1.0;
    int exitg1;
    do {
      exitg1 = 0;
      filestar = coder::internal::getfilestar(static_cast<double>(b_fileid), a);
      if (filestar == nullptr) {
        i = 0;
      } else {
        int st;
        st = std::feof(filestar);
        i = ((int)st != 0);
      }
      if (i == 0) {
        d = coder::b_ftell(static_cast<double>(b_fileid));
        i = lineLocs.size(1);
        lineLocs.set_size(1, lineLocs.size(1) + 1);
        lineLocs[i] = d;
        coder::fgetl(static_cast<double>(b_fileid), lineStr);
        if (lineStr.size(1) == 0) {
          match_idx = static_cast<int>(b_i);
          text_len = lineLocs.size(1) - 1;
          for (int c_i{match_idx}; c_i <= text_len; c_i++) {
            lineLocs[c_i - 1] = lineLocs[c_i];
          }
          if (lineLocs.size(1) - 1 < 1) {
            i = 0;
          } else {
            i = lineLocs.size(1) - 1;
          }
          lineLocs.set_size(lineLocs.size(0), i);
        } else {
          b_i++;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);
    x.matlabCodegenDestructor();
    // Initialize for coder
    // while ~feof(fid)
    i = lineLocs.size(1);
    tableOut.data.f1.set_size(lineLocs.size(1));
    tableOut.data.f2.set_size(lineLocs.size(1));
    tableOut.data.f3.set_size(lineLocs.size(1));
    tableOut.data.f4.set_size(lineLocs.size(1));
    tableOut.data.f5.set_size(lineLocs.size(1));
    tableOut.data.f6.set_size(lineLocs.size(1));
    tableOut.data.f7.set_size(lineLocs.size(1));
    tableOut.data.f8.set_size(lineLocs.size(1));
    tableOut.data.f9.set_size(lineLocs.size(1));
    tableOut.data.f10.set_size(lineLocs.size(1));
    if (i - 1 >= 0) {
      wherefrom = SEEK_SET;
    }
    for (int d_i{0}; d_i < i; d_i++) {
      creal_T b_x;
      unsigned int u;
      d = lineLocs[d_i];
      if ((!std::isinf(d)) && (!std::isnan(d)) && (std::floor(d) == d)) {
        filestar = coder::internal::getfilestar(static_cast<double>(fileid), a);
        if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
          filestar = nullptr;
        }
        if (!(filestar == nullptr)) {
          std::fseek(filestar, (long int)d, wherefrom);
        }
      }
      coder::fgetl(static_cast<double>(fileid), lineStr);
      if (lineStr.size(1) == 0) {
        commaInds.set_size(1, 0);
      } else {
        text_len = lineStr.size(1);
        matches.set_size(1, lineStr.size(1));
        match_idx = 0;
        for (int c_i{0}; c_i < text_len; c_i++) {
          if (lineStr[c_i] == ',') {
            matches[match_idx] = c_i + 1;
            match_idx++;
          }
        }
        tagID_inds.set_size(1, match_idx);
        for (int c_i{0}; c_i < match_idx; c_i++) {
          tagID_inds[c_i] = matches[c_i];
        }
        commaInds.set_size(1, tagID_inds.size(1));
        match_idx = tagID_inds.size(1);
        for (text_len = 0; text_len < match_idx; text_len++) {
          commaInds[text_len] = static_cast<unsigned int>(tagID_inds[text_len]);
        }
      }
      if (static_cast<int>(commaInds[0]) - 1 < 1) {
        tagID_inds.set_size(1, 0);
      } else {
        match_idx = static_cast<int>(commaInds[0]) - 2;
        tagID_inds.set_size(1, match_idx + 1);
        for (text_len = 0; text_len <= match_idx; text_len++) {
          tagID_inds[text_len] = text_len + 1;
        }
      }
      if (static_cast<unsigned int>(static_cast<int>(commaInds[1]) - 1) <
          commaInds[0] + 1U) {
        parentFileName_inds.set_size(1, 0);
      } else {
        d = static_cast<double>(commaInds[0]) + 1.0;
        match_idx =
            static_cast<int>((static_cast<double>(commaInds[1]) - 1.0) - d);
        parentFileName_inds.set_size(1, match_idx + 1);
        for (text_len = 0; text_len <= match_idx; text_len++) {
          parentFileName_inds[text_len] = d + static_cast<double>(text_len);
        }
      }
      if (static_cast<unsigned int>(static_cast<int>(commaInds[2]) - 1) <
          commaInds[1] + 1U) {
        bearing_inds.set_size(1, 0);
      } else {
        d = static_cast<double>(commaInds[1]) + 1.0;
        match_idx =
            static_cast<int>((static_cast<double>(commaInds[2]) - 1.0) - d);
        bearing_inds.set_size(1, match_idx + 1);
        for (text_len = 0; text_len <= match_idx; text_len++) {
          bearing_inds[text_len] = d + static_cast<double>(text_len);
        }
      }
      if (static_cast<unsigned int>(static_cast<int>(commaInds[3]) - 1) <
          commaInds[2] + 1U) {
        tau_inds.set_size(1, 0);
      } else {
        d = static_cast<double>(commaInds[2]) + 1.0;
        match_idx =
            static_cast<int>((static_cast<double>(commaInds[3]) - 1.0) - d);
        tau_inds.set_size(1, match_idx + 1);
        for (text_len = 0; text_len <= match_idx; text_len++) {
          tau_inds[text_len] = d + static_cast<double>(text_len);
        }
      }
      if (static_cast<unsigned int>(static_cast<int>(commaInds[4]) - 1) <
          commaInds[3] + 1U) {
        lat_inds.set_size(1, 0);
      } else {
        d = static_cast<double>(commaInds[3]) + 1.0;
        match_idx =
            static_cast<int>((static_cast<double>(commaInds[4]) - 1.0) - d);
        lat_inds.set_size(1, match_idx + 1);
        for (text_len = 0; text_len <= match_idx; text_len++) {
          lat_inds[text_len] = d + static_cast<double>(text_len);
        }
      }
      if (static_cast<unsigned int>(static_cast<int>(commaInds[5]) - 1) <
          commaInds[4] + 1U) {
        lon_inds.set_size(1, 0);
      } else {
        d = static_cast<double>(commaInds[4]) + 1.0;
        match_idx =
            static_cast<int>((static_cast<double>(commaInds[5]) - 1.0) - d);
        lon_inds.set_size(1, match_idx + 1);
        for (text_len = 0; text_len <= match_idx; text_len++) {
          lon_inds[text_len] = d + static_cast<double>(text_len);
        }
      }
      if (static_cast<unsigned int>(static_cast<int>(commaInds[6]) - 1) <
          commaInds[5] + 1U) {
        alt_AGL_inds.set_size(1, 0);
      } else {
        d = static_cast<double>(commaInds[5]) + 1.0;
        match_idx =
            static_cast<int>((static_cast<double>(commaInds[6]) - 1.0) - d);
        alt_AGL_inds.set_size(1, match_idx + 1);
        for (text_len = 0; text_len <= match_idx; text_len++) {
          alt_AGL_inds[text_len] = d + static_cast<double>(text_len);
        }
      }
      if (static_cast<unsigned int>(static_cast<int>(commaInds[7]) - 1) <
          commaInds[6] + 1U) {
        alt_ASL_inds.set_size(1, 0);
      } else {
        d = static_cast<double>(commaInds[6]) + 1.0;
        match_idx =
            static_cast<int>((static_cast<double>(commaInds[7]) - 1.0) - d);
        alt_ASL_inds.set_size(1, match_idx + 1);
        for (text_len = 0; text_len <= match_idx; text_len++) {
          alt_ASL_inds[text_len] = d + static_cast<double>(text_len);
        }
      }
      if (static_cast<unsigned int>(static_cast<int>(commaInds[8]) - 1) <
          commaInds[7] + 1U) {
        time_start_inds.set_size(1, 0);
      } else {
        d = static_cast<double>(commaInds[7]) + 1.0;
        match_idx =
            static_cast<int>((static_cast<double>(commaInds[8]) - 1.0) - d);
        time_start_inds.set_size(1, match_idx + 1);
        for (text_len = 0; text_len <= match_idx; text_len++) {
          time_start_inds[text_len] = d + static_cast<double>(text_len);
        }
      }
      if (static_cast<unsigned int>(lineStr.size(1)) < commaInds[8] + 1U) {
        time_end_inds.set_size(1, 0);
      } else {
        u = commaInds[8] + 1U;
        match_idx = lineStr.size(1) - static_cast<int>(u);
        time_end_inds.set_size(1, match_idx + 1);
        for (text_len = 0; text_len <= match_idx; text_len++) {
          time_end_inds[text_len] = u + static_cast<unsigned int>(text_len);
        }
      }
      b_lineStr.set_size(1, tagID_inds.size(1));
      match_idx = tagID_inds.size(1);
      for (text_len = 0; text_len < match_idx; text_len++) {
        b_lineStr[text_len] = lineStr[tagID_inds[text_len] - 1];
      }
      b_x = coder::internal::str2double(b_lineStr);
      d = std::round(b_x.re);
      if (d < 4.294967296E+9) {
        if (d >= 0.0) {
          u = static_cast<unsigned int>(d);
        } else {
          u = 0U;
        }
      } else if (d >= 4.294967296E+9) {
        u = MAX_uint32_T;
      } else {
        u = 0U;
      }
      tableOut.data.f1[d_i] = u;
      tableOut.data.f2[d_i].f1.set_size(1, parentFileName_inds.size(1));
      match_idx = parentFileName_inds.size(1);
      for (text_len = 0; text_len < match_idx; text_len++) {
        tableOut.data.f2[d_i].f1[text_len] =
            lineStr[static_cast<int>(parentFileName_inds[text_len]) - 1];
      }
      b_lineStr.set_size(1, bearing_inds.size(1));
      match_idx = bearing_inds.size(1);
      for (text_len = 0; text_len < match_idx; text_len++) {
        b_lineStr[text_len] =
            lineStr[static_cast<int>(bearing_inds[text_len]) - 1];
      }
      b_x = coder::internal::str2double(b_lineStr);
      tableOut.data.f3[d_i] = b_x.re;
      b_lineStr.set_size(1, tau_inds.size(1));
      match_idx = tau_inds.size(1);
      for (text_len = 0; text_len < match_idx; text_len++) {
        b_lineStr[text_len] = lineStr[static_cast<int>(tau_inds[text_len]) - 1];
      }
      b_x = coder::internal::str2double(b_lineStr);
      tableOut.data.f4[d_i] = b_x.re;
      b_lineStr.set_size(1, lat_inds.size(1));
      match_idx = lat_inds.size(1);
      for (text_len = 0; text_len < match_idx; text_len++) {
        b_lineStr[text_len] = lineStr[static_cast<int>(lat_inds[text_len]) - 1];
      }
      b_x = coder::internal::str2double(b_lineStr);
      tableOut.data.f5[d_i] = b_x.re;
      b_lineStr.set_size(1, lon_inds.size(1));
      match_idx = lon_inds.size(1);
      for (text_len = 0; text_len < match_idx; text_len++) {
        b_lineStr[text_len] = lineStr[static_cast<int>(lon_inds[text_len]) - 1];
      }
      b_x = coder::internal::str2double(b_lineStr);
      tableOut.data.f6[d_i] = b_x.re;
      b_lineStr.set_size(1, alt_AGL_inds.size(1));
      match_idx = alt_AGL_inds.size(1);
      for (text_len = 0; text_len < match_idx; text_len++) {
        b_lineStr[text_len] =
            lineStr[static_cast<int>(alt_AGL_inds[text_len]) - 1];
      }
      b_x = coder::internal::str2double(b_lineStr);
      tableOut.data.f7[d_i] = b_x.re;
      b_lineStr.set_size(1, alt_ASL_inds.size(1));
      match_idx = alt_ASL_inds.size(1);
      for (text_len = 0; text_len < match_idx; text_len++) {
        b_lineStr[text_len] =
            lineStr[static_cast<int>(alt_ASL_inds[text_len]) - 1];
      }
      b_x = coder::internal::str2double(b_lineStr);
      tableOut.data.f8[d_i] = b_x.re;
      b_lineStr.set_size(1, time_start_inds.size(1));
      match_idx = time_start_inds.size(1);
      for (text_len = 0; text_len < match_idx; text_len++) {
        b_lineStr[text_len] =
            lineStr[static_cast<int>(time_start_inds[text_len]) - 1];
      }
      b_x = coder::internal::str2double(b_lineStr);
      tableOut.data.f9[d_i] = b_x.re;
      b_lineStr.set_size(1, time_end_inds.size(1));
      match_idx = time_end_inds.size(1);
      for (text_len = 0; text_len < match_idx; text_len++) {
        b_lineStr[text_len] =
            lineStr[static_cast<int>(time_end_inds[text_len]) - 1];
      }
      b_x = coder::internal::str2double(b_lineStr);
      tableOut.data.f10[d_i] = b_x.re;
      // i = i+1;
    }
  } else {
    std::printf("UAV-RT: Error opening the bearing csv file.");
    std::fflush(stdout);
    tableOut.data.f1.set_size(1);
    tableOut.data.f1[0] = 0U;
    r.f1.set_size(1, 14);
    for (int i{0}; i < 14; i++) {
      r.f1[i] = cv[i];
    }
    tableOut.data.f2.set_size(1);
    tableOut.data.f2[0] = r;
    tableOut.data.f3.set_size(1);
    tableOut.data.f3[0] = rtNaN;
    tableOut.data.f4.set_size(1);
    tableOut.data.f4[0] = rtNaN;
    tableOut.data.f5.set_size(1);
    tableOut.data.f5[0] = rtNaN;
    tableOut.data.f6.set_size(1);
    tableOut.data.f6[0] = rtNaN;
    tableOut.data.f7.set_size(1);
    tableOut.data.f7[0] = rtNaN;
    tableOut.data.f8.set_size(1);
    tableOut.data.f8[0] = rtNaN;
    tableOut.data.f9.set_size(1);
    tableOut.data.f9[0] = rtNaN;
    tableOut.data.f10.set_size(1);
    tableOut.data.f10[0] = rtNaN;
  }
  tableOut.arrayProps.Description.size[0] = 1;
  tableOut.arrayProps.Description.size[1] = 0;
  tableOut.rowDim.length = tableOut.data.f1.size(0);
  coder::matlab::internal::coder::tabular::b_private::varNamesDim::createLike(
      tableOut.varDim);
}

//
// File trailer for readbearingcsv.cpp
//
// [EOF]
//
