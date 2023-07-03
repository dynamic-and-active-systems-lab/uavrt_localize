//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: div.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:18:22
//

#ifndef DIV_H
#define DIV_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void binary_expand_op(
    coder::array<double, 1U> &in1, const coder::array<double, 1U> &in2,
    const coder::array<double, 1U> &in3, const coder::array<double, 2U> &in4,
    const coder::array<double, 1U> &in5, const coder::array<double, 1U> &in6,
    const coder::array<double, 1U> &in7, const coder::array<double, 1U> &in8);

void e_binary_expand_op(coder::array<double, 1U> &in1,
                        const coder::array<double, 1U> &in2,
                        const coder::array<double, 1U> &in3);

void rdivide(coder::array<double, 1U> &in1,
             const coder::array<double, 1U> &in2);

#endif
//
// File trailer for div.h
//
// [EOF]
//
