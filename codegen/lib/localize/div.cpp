//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: div.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:18:22
//

// Include Files
#include "div.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 2U> &in4
//                const coder::array<double, 1U> &in5
//                const coder::array<double, 1U> &in6
//                const coder::array<double, 1U> &in7
//                const coder::array<double, 1U> &in8
// Return Type  : void
//
void binary_expand_op(
    coder::array<double, 1U> &in1, const coder::array<double, 1U> &in2,
    const coder::array<double, 1U> &in3, const coder::array<double, 2U> &in4,
    const coder::array<double, 1U> &in5, const coder::array<double, 1U> &in6,
    const coder::array<double, 1U> &in7, const coder::array<double, 1U> &in8)
{
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0_tmp;
  int stride_3_0_tmp;
  int stride_4_0;
  int stride_6_0;
  if (in6.size(0) == 1) {
    i = in4.size(0);
  } else {
    i = in6.size(0);
  }
  if (in8.size(0) == 1) {
    i1 = in6.size(0);
  } else {
    i1 = in8.size(0);
  }
  if (i1 == 1) {
    if (in7.size(0) == 1) {
      if (i == 1) {
        if (in4.size(0) == 1) {
          loop_ub = in2.size(0);
        } else {
          loop_ub = in4.size(0);
        }
      } else {
        loop_ub = i;
      }
    } else {
      loop_ub = in7.size(0);
    }
  } else {
    loop_ub = i1;
  }
  in1.set_size(loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0_tmp = (in4.size(0) != 1);
  stride_3_0_tmp = (in6.size(0) != 1);
  stride_4_0 = (in7.size(0) != 1);
  stride_6_0 = (in8.size(0) != 1);
  for (i = 0; i < loop_ub; i++) {
    double d;
    i1 = static_cast<int>(in4[i * stride_1_0_tmp + in4.size(0)]) - 1;
    d = in6[i * stride_3_0_tmp];
    in1[i] = (((in2[i * stride_0_0] - in3[i1]) + in5[i1] * d) -
              in7[i * stride_4_0]) /
             (d - in8[i * stride_6_0]);
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
// Return Type  : void
//
void e_binary_expand_op(coder::array<double, 1U> &in1,
                        const coder::array<double, 1U> &in2,
                        const coder::array<double, 1U> &in3)
{
  coder::array<double, 1U> r;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  if (in3.size(0) == 1) {
    if (in2.size(0) == 1) {
      loop_ub = in1.size(0);
    } else {
      loop_ub = in2.size(0);
    }
  } else {
    loop_ub = in3.size(0);
  }
  r.set_size(loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  stride_2_0 = (in3.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    r[i] = 1.5 * in1[i * stride_0_0] *
           static_cast<double>(in2[i * stride_1_0] < 4.71238898038469) /
           in3[i * stride_2_0];
  }
  in1.set_size(r.size(0));
  loop_ub = r.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = r[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
// Return Type  : void
//
void rdivide(coder::array<double, 1U> &in1, const coder::array<double, 1U> &in2)
{
  coder::array<double, 1U> b_in1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  b_in1.set_size(loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    b_in1[i] = in1[i * stride_0_0] / in2[i * stride_1_0];
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// File trailer for div.cpp
//
// [EOF]
//
