//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: localize_internal_types.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:18:22
//

#ifndef LOCALIZE_INTERNAL_TYPES_H
#define LOCALIZE_INTERNAL_TYPES_H

// Include Files
#include "localize_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Type Definitions
struct struct_T {
  double fid;
};

struct cell_wrap_4 {
  coder::array<char, 2U> f1;
};

struct cell_5 {
  coder::array<unsigned int, 1U> f1;
  coder::array<cell_wrap_4, 1U> f2;
  coder::array<double, 1U> f3;
  coder::array<double, 1U> f4;
  coder::array<double, 1U> f5;
  coder::array<double, 1U> f6;
  coder::array<double, 1U> f7;
  coder::array<double, 1U> f8;
  coder::array<double, 1U> f9;
  coder::array<double, 1U> f10;
};

struct b_struct_T {
  coder::empty_bounded_array<char, 2U> Description;
};

#endif
//
// File trailer for localize_internal_types.h
//
// [EOF]
//
