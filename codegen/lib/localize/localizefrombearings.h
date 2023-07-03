//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: localizefrombearings.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:18:22
//

#ifndef LOCALIZEFROMBEARINGS_H
#define LOCALIZEFROMBEARINGS_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class table;

}

// Function Declarations
void b_binary_expand_op(coder::array<boolean_T, 1U> &in1,
                        const coder::array<double, 1U> &in2,
                        const coder::array<double, 1U> &in3,
                        const coder::table &in4);

void b_localizefrombearings(coder::array<double, 1U> &X,
                            coder::array<double, 1U> &Y,
                            coder::array<double, 1U> &T, double position[2]);

void binary_expand_op(coder::array<double, 1U> &in1,
                      const coder::array<double, 1U> &in2,
                      const coder::array<double, 1U> &in3,
                      const coder::array<double, 1U> &in4,
                      const coder::array<double, 1U> &in5);

void binary_expand_op(coder::array<double, 1U> &in1,
                      const coder::array<double, 1U> &in3,
                      const coder::array<double, 1U> &in4);

void binary_expand_op(double in1[4], const coder::array<double, 1U> &in2,
                      const coder::array<double, 1U> &in3,
                      const coder::array<double, 1U> &in4,
                      const coder::array<double, 1U> &in5);

void binary_expand_op(double in1[2], const coder::array<double, 1U> &in2,
                      const coder::array<double, 1U> &in3,
                      const coder::array<double, 1U> &in4);

void localizefrombearings(coder::array<double, 1U> &X,
                          coder::array<double, 1U> &Y,
                          coder::array<double, 1U> &T, double position[2]);

void times(coder::array<double, 1U> &in1, const coder::array<double, 1U> &in2,
           const coder::array<double, 1U> &in3);

#endif
//
// File trailer for localizefrombearings.h
//
// [EOF]
//
