//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ftell.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:18:22
//

// Include Files
#include "ftell.h"
#include "fileManager.h"
#include "localize_data.h"
#include "rt_nonfinite.h"
#include <cstdio>

// Function Definitions
//
// Arguments    : double fileID
// Return Type  : double
//
namespace coder {
double b_ftell(double fileID)
{
  std::FILE *filestar;
  double position;
  boolean_T a;
  filestar = internal::getfilestar(fileID, a);
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = nullptr;
  }
  if (filestar == nullptr) {
    position = -1.0;
  } else {
    long position_t;
    position_t = std::ftell(filestar);
    position = (double)position_t;
  }
  return position;
}

} // namespace coder

//
// File trailer for ftell.cpp
//
// [EOF]
//
