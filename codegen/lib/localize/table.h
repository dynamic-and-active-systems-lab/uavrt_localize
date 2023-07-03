//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: table.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:18:22
//

#ifndef TABLE_H
#define TABLE_H

// Include Files
#include "localize_internal_types.h"
#include "metaDim.h"
#include "rowNamesDim.h"
#include "rtwtypes.h"
#include "varNamesDim.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
class table {
public:
  void sortrows(table &b) const;
  void parenReference(const ::coder::array<boolean_T, 1U> &varargin_1,
                      table &b) const;
  matlab::internal::coder::tabular::b_private::rowNamesDim rowDim;
  matlab::internal::coder::tabular::b_private::varNamesDim varDim;
  cell_5 data;
  b_struct_T arrayProps;

protected:
  matlab::internal::coder::tabular::b_private::metaDim b_metaDim;
};

} // namespace coder

#endif
//
// File trailer for table.h
//
// [EOF]
//
