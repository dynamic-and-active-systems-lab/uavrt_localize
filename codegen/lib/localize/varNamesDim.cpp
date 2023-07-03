//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: varNamesDim.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:18:22
//

// Include Files
#include "varNamesDim.h"
#include "rt_nonfinite.h"
#include "coder_bounded_array.h"

// Function Definitions
//
// Arguments    : varNamesDim &newobj
// Return Type  : void
//
namespace coder {
namespace matlab {
namespace internal {
namespace coder {
namespace tabular {
namespace b_private {
void varNamesDim::createLike(varNamesDim &newobj)
{
  newobj.hasUnits = false;
  newobj.units[0].f1.size[0] = 1;
  newobj.units[0].f1.size[1] = 0;
  newobj.units[1].f1.size[0] = 1;
  newobj.units[1].f1.size[1] = 0;
  newobj.units[2].f1.size[0] = 1;
  newobj.units[2].f1.size[1] = 0;
  newobj.units[3].f1.size[0] = 1;
  newobj.units[3].f1.size[1] = 0;
  newobj.units[4].f1.size[0] = 1;
  newobj.units[4].f1.size[1] = 0;
  newobj.units[5].f1.size[0] = 1;
  newobj.units[5].f1.size[1] = 0;
  newobj.units[6].f1.size[0] = 1;
  newobj.units[6].f1.size[1] = 0;
  newobj.units[7].f1.size[0] = 1;
  newobj.units[7].f1.size[1] = 0;
  newobj.units[8].f1.size[0] = 1;
  newobj.units[8].f1.size[1] = 0;
  newobj.units[9].f1.size[0] = 1;
  newobj.units[9].f1.size[1] = 0;
  newobj.hasDescrs = false;
  newobj.descrs[0].f1.size[0] = 1;
  newobj.descrs[0].f1.size[1] = 0;
  newobj.descrs[1].f1.size[0] = 1;
  newobj.descrs[1].f1.size[1] = 0;
  newobj.descrs[2].f1.size[0] = 1;
  newobj.descrs[2].f1.size[1] = 0;
  newobj.descrs[3].f1.size[0] = 1;
  newobj.descrs[3].f1.size[1] = 0;
  newobj.descrs[4].f1.size[0] = 1;
  newobj.descrs[4].f1.size[1] = 0;
  newobj.descrs[5].f1.size[0] = 1;
  newobj.descrs[5].f1.size[1] = 0;
  newobj.descrs[6].f1.size[0] = 1;
  newobj.descrs[6].f1.size[1] = 0;
  newobj.descrs[7].f1.size[0] = 1;
  newobj.descrs[7].f1.size[1] = 0;
  newobj.descrs[8].f1.size[0] = 1;
  newobj.descrs[8].f1.size[1] = 0;
  newobj.descrs[9].f1.size[0] = 1;
  newobj.descrs[9].f1.size[1] = 0;
  newobj.hasContinuity = false;
  for (int i{0}; i < 10; i++) {
    newobj.continuity[i] = Continuity::unset;
  }
}

} // namespace b_private
} // namespace tabular
} // namespace coder
} // namespace internal
} // namespace matlab
} // namespace coder

//
// File trailer for varNamesDim.cpp
//
// [EOF]
//
