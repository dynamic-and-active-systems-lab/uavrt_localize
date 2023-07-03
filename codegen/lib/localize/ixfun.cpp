//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ixfun.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:18:22
//

// Include Files
#include "ixfun.h"
#include "localize_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &a
//                const ::coder::array<double, 1U> &b
//                ::coder::array<double, 1U> &c
// Return Type  : void
//
namespace coder {
namespace internal {
void expand_atan2(const ::coder::array<double, 1U> &a,
                  const ::coder::array<double, 1U> &b,
                  ::coder::array<double, 1U> &c)
{
  int u0;
  int u1;
  u0 = a.size(0);
  u1 = b.size(0);
  if (u0 <= u1) {
    u1 = u0;
  }
  if (b.size(0) == 1) {
    u0 = a.size(0);
  } else if (a.size(0) == 1) {
    u0 = b.size(0);
  } else {
    u0 = u1;
  }
  c.set_size(u0);
  if (u0 != 0) {
    boolean_T b1;
    boolean_T b_b;
    b_b = (a.size(0) != 1);
    b1 = (b.size(0) != 1);
    u0--;
    for (u1 = 0; u1 <= u0; u1++) {
      c[u1] = rt_atan2d_snf(a[b_b * u1], b[b1 * u1]);
    }
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for ixfun.cpp
//
// [EOF]
//
