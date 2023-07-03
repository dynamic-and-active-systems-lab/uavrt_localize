//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: angdiff.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:32:45
//

// Include Files
#include "angdiff.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : double x
//                double y
// Return Type  : double
//
namespace coder {
double angdiff(double x, double y)
{
  double delta;
  delta = y - x;
  if (std::abs(delta) > 3.1415926535897931) {
    double thetaWrap;
    if (std::isnan(delta + 3.1415926535897931) ||
        std::isinf(delta + 3.1415926535897931)) {
      thetaWrap = rtNaN;
    } else if (delta + 3.1415926535897931 == 0.0) {
      thetaWrap = 0.0;
    } else {
      boolean_T rEQ0;
      thetaWrap = std::fmod(delta + 3.1415926535897931, 6.2831853071795862);
      rEQ0 = (thetaWrap == 0.0);
      if (!rEQ0) {
        double q;
        q = std::abs((delta + 3.1415926535897931) / 6.2831853071795862);
        rEQ0 =
            !(std::abs(q - std::floor(q + 0.5)) > 2.2204460492503131E-16 * q);
      }
      if (rEQ0) {
        thetaWrap = 0.0;
      } else if (delta + 3.1415926535897931 < 0.0) {
        thetaWrap += 6.2831853071795862;
      }
    }
    if ((thetaWrap == 0.0) && (delta + 3.1415926535897931 > 0.0)) {
      thetaWrap = 6.2831853071795862;
    }
    delta = thetaWrap - 3.1415926535897931;
  }
  return delta;
}

} // namespace coder

//
// File trailer for angdiff.cpp
//
// [EOF]
//
