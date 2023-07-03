//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: cotd.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:32:45
//

// Include Files
#include "cotd.h"
#include "localize_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : ::coder::array<double, 1U> &x
// Return Type  : void
//
namespace coder {
void b_cotd(::coder::array<double, 1U> &x)
{
  int nx;
  nx = x.size(0);
  for (int k{0}; k < nx; k++) {
    double b_x;
    b_x = x[k];
    if (std::isinf(b_x) || std::isnan(b_x)) {
      b_x = rtNaN;
    } else {
      double absx;
      signed char n;
      b_x = rt_remd_snf(b_x, 360.0);
      absx = std::abs(b_x);
      if (absx > 180.0) {
        if (b_x > 0.0) {
          b_x -= 360.0;
        } else {
          b_x += 360.0;
        }
        absx = std::abs(b_x);
      }
      if (absx <= 45.0) {
        b_x *= 0.017453292519943295;
        n = 0;
      } else if (absx <= 135.0) {
        if (b_x > 0.0) {
          b_x = 0.017453292519943295 * (b_x - 90.0);
          n = 1;
        } else {
          b_x = 0.017453292519943295 * (b_x + 90.0);
          n = -1;
        }
      } else if (b_x > 0.0) {
        b_x = 0.017453292519943295 * (b_x - 180.0);
        n = 2;
      } else {
        b_x = 0.017453292519943295 * (b_x + 180.0);
        n = -2;
      }
      b_x = std::tan(b_x);
      if ((n == 1) || (n == -1)) {
        absx = 1.0 / b_x;
        b_x = -(1.0 / b_x);
        if (std::isinf(b_x) && (n == 1)) {
          b_x = absx;
        }
      }
    }
    x[k] = 1.0 / b_x;
  }
}

} // namespace coder

//
// File trailer for cotd.cpp
//
// [EOF]
//
