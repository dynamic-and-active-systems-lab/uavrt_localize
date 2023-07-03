//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: median.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:32:45
//

// Include Files
#include "median.h"
#include "quickselect.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &x
//                double y[2]
// Return Type  : void
//
namespace coder {
void median(const ::coder::array<double, 2U> &x, double y[2])
{
  array<double, 1U> xv;
  int a__6;
  int k;
  int loop_ub;
  int n;
  int vlen;
  y[0] = 0.0;
  y[1] = 0.0;
  loop_ub = x.size(1);
  n = x.size(1);
  for (int j{0}; j < 2; j++) {
    xv.set_size(x.size(1));
    for (k = 0; k < loop_ub; k++) {
      xv[k] = x[j + (k << 1)];
    }
    vlen = 0;
    for (k = 0; k < n; k++) {
      if (!std::isnan(xv[k])) {
        vlen++;
        if (vlen < k + 1) {
          xv[vlen - 1] = xv[k];
        }
      }
    }
    if (vlen <= 4) {
      if (vlen == 0) {
        y[j] = rtNaN;
      } else if (vlen == 1) {
        y[j] = xv[0];
      } else if (vlen == 2) {
        if (((xv[0] < 0.0) != (xv[1] < 0.0)) || std::isinf(xv[0])) {
          y[j] = (xv[0] + xv[1]) / 2.0;
        } else {
          y[j] = xv[0] + (xv[1] - xv[0]) / 2.0;
        }
      } else if (vlen == 3) {
        if (xv[0] < xv[1]) {
          if (xv[1] < xv[2]) {
            a__6 = 1;
          } else if (xv[0] < xv[2]) {
            a__6 = 2;
          } else {
            a__6 = 0;
          }
        } else if (xv[0] < xv[2]) {
          a__6 = 0;
        } else if (xv[1] < xv[2]) {
          a__6 = 2;
        } else {
          a__6 = 1;
        }
        y[j] = xv[a__6];
      } else {
        if (xv[0] < xv[1]) {
          if (xv[1] < xv[2]) {
            k = 0;
            a__6 = 1;
            vlen = 2;
          } else if (xv[0] < xv[2]) {
            k = 0;
            a__6 = 2;
            vlen = 1;
          } else {
            k = 2;
            a__6 = 0;
            vlen = 1;
          }
        } else if (xv[0] < xv[2]) {
          k = 1;
          a__6 = 0;
          vlen = 2;
        } else if (xv[1] < xv[2]) {
          k = 1;
          a__6 = 2;
          vlen = 0;
        } else {
          k = 2;
          a__6 = 1;
          vlen = 0;
        }
        if (xv[k] < xv[3]) {
          if (xv[3] < xv[vlen]) {
            if (((xv[a__6] < 0.0) != (xv[3] < 0.0)) || std::isinf(xv[a__6])) {
              y[j] = (xv[a__6] + xv[3]) / 2.0;
            } else {
              y[j] = xv[a__6] + (xv[3] - xv[a__6]) / 2.0;
            }
          } else if (((xv[a__6] < 0.0) != (xv[vlen] < 0.0)) ||
                     std::isinf(xv[a__6])) {
            y[j] = (xv[a__6] + xv[vlen]) / 2.0;
          } else {
            y[j] = xv[a__6] + (xv[vlen] - xv[a__6]) / 2.0;
          }
        } else if (((xv[k] < 0.0) != (xv[a__6] < 0.0)) || std::isinf(xv[k])) {
          y[j] = (xv[k] + xv[a__6]) / 2.0;
        } else {
          y[j] = xv[k] + (xv[a__6] - xv[k]) / 2.0;
        }
      }
    } else {
      int midm1;
      midm1 = vlen >> 1;
      if ((vlen & 1) == 0) {
        double m;
        m = internal::quickselect(xv, midm1 + 1, vlen, k, a__6);
        y[j] = m;
        if (midm1 < k) {
          double b;
          b = internal::quickselect(xv, midm1, a__6 - 1, k, vlen);
          if (((m < 0.0) != (b < 0.0)) || std::isinf(m)) {
            y[j] = (m + b) / 2.0;
          } else {
            y[j] = m + (b - m) / 2.0;
          }
        }
      } else {
        y[j] = internal::quickselect(xv, midm1 + 1, vlen, k, a__6);
      }
    }
  }
}

} // namespace coder

//
// File trailer for median.cpp
//
// [EOF]
//
