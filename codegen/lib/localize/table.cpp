//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: table.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:18:22
//

// Include Files
#include "table.h"
#include "find.h"
#include "localize_internal_types.h"
#include "metaDim.h"
#include "rowNamesDim.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "varNamesDim.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<boolean_T, 1U> &varargin_1
//                table &b
// Return Type  : void
//
namespace coder {
void table::parenReference(const ::coder::array<boolean_T, 1U> &varargin_1,
                           table &b) const
{
  array<int, 1U> numericRowIndices;
  int k;
  int nz;
  int vlen;
  vlen = varargin_1.size(0);
  if (varargin_1.size(0) == 0) {
    nz = 0;
  } else {
    nz = varargin_1[0];
    for (k = 2; k <= vlen; k++) {
      nz += varargin_1[k - 1];
    }
  }
  b.rowDim.length = nz;
  matlab::internal::coder::tabular::b_private::varNamesDim::createLike(
      b.varDim);
  k = varargin_1.size(0) - 1;
  vlen = 0;
  for (int i{0}; i <= k; i++) {
    if (varargin_1[i]) {
      vlen++;
    }
  }
  b.data.f1.set_size(vlen);
  vlen = 0;
  for (int i{0}; i <= k; i++) {
    if (varargin_1[i]) {
      b.data.f1[vlen] = data.f1[i];
      vlen++;
    }
  }
  eml_find(varargin_1, numericRowIndices);
  b.data.f2.set_size(numericRowIndices.size(0));
  vlen = numericRowIndices.size(0);
  for (int i{0}; i < vlen; i++) {
    b.data.f2[i].f1.set_size(1, data.f2[numericRowIndices[i] - 1].f1.size(1));
    nz = data.f2[numericRowIndices[i] - 1].f1.size(1);
    for (int b_i{0}; b_i < nz; b_i++) {
      b.data.f2[i].f1[b_i] = data.f2[numericRowIndices[i] - 1].f1[b_i];
    }
  }
  vlen = 0;
  for (int i{0}; i <= k; i++) {
    if (varargin_1[i]) {
      vlen++;
    }
  }
  b.data.f3.set_size(vlen);
  vlen = 0;
  for (int i{0}; i <= k; i++) {
    if (varargin_1[i]) {
      b.data.f3[vlen] = data.f3[i];
      vlen++;
    }
  }
  vlen = 0;
  for (int i{0}; i <= k; i++) {
    if (varargin_1[i]) {
      vlen++;
    }
  }
  b.data.f4.set_size(vlen);
  vlen = 0;
  for (int i{0}; i <= k; i++) {
    if (varargin_1[i]) {
      b.data.f4[vlen] = data.f4[i];
      vlen++;
    }
  }
  vlen = 0;
  for (int i{0}; i <= k; i++) {
    if (varargin_1[i]) {
      vlen++;
    }
  }
  b.data.f5.set_size(vlen);
  vlen = 0;
  for (int i{0}; i <= k; i++) {
    if (varargin_1[i]) {
      b.data.f5[vlen] = data.f5[i];
      vlen++;
    }
  }
  vlen = 0;
  for (int i{0}; i <= k; i++) {
    if (varargin_1[i]) {
      vlen++;
    }
  }
  b.data.f6.set_size(vlen);
  vlen = 0;
  for (int i{0}; i <= k; i++) {
    if (varargin_1[i]) {
      b.data.f6[vlen] = data.f6[i];
      vlen++;
    }
  }
  vlen = 0;
  for (int i{0}; i <= k; i++) {
    if (varargin_1[i]) {
      vlen++;
    }
  }
  b.data.f7.set_size(vlen);
  vlen = 0;
  for (int i{0}; i <= k; i++) {
    if (varargin_1[i]) {
      b.data.f7[vlen] = data.f7[i];
      vlen++;
    }
  }
  vlen = 0;
  for (int i{0}; i <= k; i++) {
    if (varargin_1[i]) {
      vlen++;
    }
  }
  b.data.f8.set_size(vlen);
  vlen = 0;
  for (int i{0}; i <= k; i++) {
    if (varargin_1[i]) {
      b.data.f8[vlen] = data.f8[i];
      vlen++;
    }
  }
  vlen = 0;
  for (int i{0}; i <= k; i++) {
    if (varargin_1[i]) {
      vlen++;
    }
  }
  b.data.f9.set_size(vlen);
  vlen = 0;
  for (int i{0}; i <= k; i++) {
    if (varargin_1[i]) {
      b.data.f9[vlen] = data.f9[i];
      vlen++;
    }
  }
  vlen = 0;
  for (int i{0}; i <= k; i++) {
    if (varargin_1[i]) {
      vlen++;
    }
  }
  b.data.f10.set_size(vlen);
  vlen = 0;
  for (int i{0}; i <= k; i++) {
    if (varargin_1[i]) {
      b.data.f10[vlen] = data.f10[i];
      vlen++;
    }
  }
  b.b_metaDim = b_metaDim;
  b.arrayProps = arrayProps;
}

//
// Arguments    : table &b
// Return Type  : void
//
void table::sortrows(table &b) const
{
  array<double, 1U> b_y;
  array<unsigned int, 2U> y;
  array<unsigned int, 1U> b_idx;
  array<unsigned int, 1U> idx;
  array<int, 1U> iidx;
  int i;
  int i1;
  int loop_ub;
  if (data.f1.size(0) < 1) {
    y.set_size(1, 0);
  } else {
    y.set_size(1, data.f1.size(0));
    loop_ub = data.f1.size(0) - 1;
    for (i = 0; i <= loop_ub; i++) {
      y[i] = static_cast<unsigned int>(i) + 1U;
    }
  }
  idx.set_size(y.size(1));
  loop_ub = y.size(1);
  for (i = 0; i < loop_ub; i++) {
    idx[i] = y[i];
  }
  b_y.set_size(idx.size(0));
  loop_ub = idx.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_y[i] = data.f9[static_cast<int>(idx[i]) - 1];
  }
  internal::sort(b_y, iidx);
  b_idx.set_size(iidx.size(0));
  loop_ub = iidx.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_idx[i] = idx[iidx[i] - 1];
  }
  idx.set_size(b_idx.size(0));
  loop_ub = b_idx.size(0);
  for (i = 0; i < loop_ub; i++) {
    idx[i] = b_idx[i];
  }
  b_idx.set_size(idx.size(0));
  loop_ub = idx.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_idx[i] = data.f1[static_cast<int>(idx[i]) - 1];
  }
  internal::sort(b_idx, iidx);
  b_idx.set_size(iidx.size(0));
  loop_ub = iidx.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_idx[i] = idx[iidx[i] - 1];
  }
  idx.set_size(b_idx.size(0));
  loop_ub = b_idx.size(0);
  for (i = 0; i < loop_ub; i++) {
    idx[i] = b_idx[i];
  }
  b.rowDim.length = idx.size(0);
  b.varDim = varDim;
  b.data.f1.set_size(idx.size(0));
  loop_ub = idx.size(0);
  for (i = 0; i < loop_ub; i++) {
    b.data.f1[i] = data.f1[static_cast<int>(idx[i]) - 1];
  }
  b.data.f2.set_size(idx.size(0));
  i = idx.size(0);
  for (int b_i{0}; b_i < i; b_i++) {
    b.data.f2[b_i].f1.set_size(
        1, data.f2[static_cast<int>(idx[b_i]) - 1].f1.size(1));
    loop_ub = data.f2[static_cast<int>(idx[b_i]) - 1].f1.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b.data.f2[b_i].f1[i1] = data.f2[static_cast<int>(idx[b_i]) - 1].f1[i1];
    }
  }
  b.data.f3.set_size(idx.size(0));
  loop_ub = idx.size(0);
  b.data.f4.set_size(idx.size(0));
  b.data.f5.set_size(idx.size(0));
  b.data.f6.set_size(idx.size(0));
  b.data.f7.set_size(idx.size(0));
  b.data.f8.set_size(idx.size(0));
  b.data.f9.set_size(idx.size(0));
  b.data.f10.set_size(idx.size(0));
  for (i = 0; i < loop_ub; i++) {
    i1 = static_cast<int>(idx[i]) - 1;
    b.data.f3[i] = data.f3[i1];
    b.data.f4[i] = data.f4[i1];
    b.data.f5[i] = data.f5[i1];
    b.data.f6[i] = data.f6[i1];
    b.data.f7[i] = data.f7[i1];
    b.data.f8[i] = data.f8[i1];
    b.data.f9[i] = data.f9[i1];
    b.data.f10[i] = data.f10[i1];
  }
  b.b_metaDim = b_metaDim;
  b.arrayProps = arrayProps;
}

} // namespace coder

//
// File trailer for table.cpp
//
// [EOF]
//
