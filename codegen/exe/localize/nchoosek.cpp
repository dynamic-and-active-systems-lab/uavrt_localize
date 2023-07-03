//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: nchoosek.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:32:45
//

// Include Files
#include "nchoosek.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : double n
//                double k
// Return Type  : double
//
namespace coder {
double nCk(double n, double k)
{
  double y;
  if (std::isinf(n) || std::isnan(n) || (std::isinf(k) || std::isnan(k))) {
    y = rtNaN;
  } else if (k > 1000.0) {
    y = rtInf;
  } else {
    double maxRelErr;
    int i;
    maxRelErr = 0.0;
    y = n;
    i = static_cast<int>(k - 1.0);
    for (int j{0}; j < i; j++) {
      y *= ((n - (static_cast<double>(j) + 2.0)) + 1.0) /
           (static_cast<double>(j) + 2.0);
      if (!(y < 1.125899906842624E+15)) {
        maxRelErr += 4.4408920985006262E-16;
      }
      y = std::round(y);
    }
    if ((maxRelErr != 0.0) && (y <= 3.6893488147419103E+19)) {
      unsigned long b_i;
      unsigned long b_k;
      unsigned long b_n;
      unsigned long yint;
      boolean_T exitg1;
      maxRelErr = std::round(n);
      if (maxRelErr < 1.8446744073709552E+19) {
        if (maxRelErr >= 0.0) {
          b_n = static_cast<unsigned long>(maxRelErr);
        } else {
          b_n = 0UL;
        }
      } else if (maxRelErr >= 1.8446744073709552E+19) {
        b_n = MAX_uint64_T;
      } else {
        b_n = 0UL;
      }
      maxRelErr = std::round(k);
      if (maxRelErr < 1.8446744073709552E+19) {
        if (maxRelErr >= 0.0) {
          b_k = static_cast<unsigned long>(maxRelErr);
        } else {
          b_k = 0UL;
        }
      } else {
        b_k = 0UL;
      }
      yint = 1UL;
      b_i = 1UL;
      exitg1 = false;
      while ((!exitg1) && (b_i <= b_k)) {
        unsigned long u;
        unsigned long u1;
        if (b_i == 0UL) {
          u = MAX_uint64_T;
        } else {
          u = yint / b_i;
        }
        if (b_n == 0UL) {
          u1 = MAX_uint64_T;
        } else {
          u1 = MAX_uint64_T / b_n;
        }
        if (u >= u1) {
          yint = MAX_uint64_T;
          exitg1 = true;
        } else {
          if (b_i == 0UL) {
            u1 = MAX_uint64_T;
          } else {
            if (b_i == 0UL) {
              u1 = MAX_uint64_T;
            } else {
              u1 = yint / b_i;
            }
            u1 = (yint - u1 * b_i) * b_n / b_i;
          }
          yint = u * b_n + u1;
          b_n--;
          b_i++;
        }
      }
      y = static_cast<double>(yint);
    }
  }
  return y;
}

} // namespace coder

//
// File trailer for nchoosek.cpp
//
// [EOF]
//
