//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: strcmp.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:32:45
//

// Include Files
#include "strcmp.h"
#include "localize_data.h"
#include "localize_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<cell_wrap_4, 1U> &a
//                ::coder::array<boolean_T, 1U> &b_bool
// Return Type  : void
//
namespace coder {
namespace internal {
void b_strcmp(const ::coder::array<cell_wrap_4, 1U> &a,
              ::coder::array<boolean_T, 1U> &b_bool)
{
  int nb;
  b_bool.set_size(a.size(0));
  nb = a.size(0);
  for (int k{0}; k < nb; k++) {
    b_bool[k] = false;
    if (a[k].f1.size(1) == 14) {
      int kstr;
      kstr = 0;
      int exitg1;
      do {
        exitg1 = 0;
        if (kstr < 14) {
          if (a[k].f1[kstr] != cv[kstr]) {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool[k] = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for strcmp.cpp
//
// [EOF]
//
