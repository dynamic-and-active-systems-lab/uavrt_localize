//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: cospiAndSinpi.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:18:22
//

// Include Files
#include "cospiAndSinpi.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : double x
//                double &s
// Return Type  : double
//
namespace coder {
namespace internal {
namespace scalar {
double cospiAndSinpi(double x, double &s)
{
  double c;
  boolean_T negateSinpi;
  if (x < 0.0) {
    x = -x;
    negateSinpi = true;
  } else {
    negateSinpi = false;
  }
  if (x < 0.25) {
    c = std::cos(x * 3.1415926535897931);
    s = std::sin(x * 3.1415926535897931);
  } else if (x < 0.75) {
    double theta;
    theta = (0.5 - x) * 3.1415926535897931;
    c = std::sin(theta);
    s = std::cos(theta);
  } else if (x < 1.25) {
    double theta;
    theta = (1.0 - x) * 3.1415926535897931;
    c = -std::cos(theta);
    s = std::sin(theta);
  } else {
    double theta;
    theta = (x - 1.5) * 3.1415926535897931;
    c = std::sin(theta);
    s = -std::cos(theta);
  }
  if (negateSinpi) {
    s = -s;
  }
  return c;
}

} // namespace scalar
} // namespace internal
} // namespace coder

//
// File trailer for cospiAndSinpi.cpp
//
// [EOF]
//
