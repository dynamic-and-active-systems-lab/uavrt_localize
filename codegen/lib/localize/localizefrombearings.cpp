//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: localizefrombearings.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:18:22
//

// Include Files
#include "localizefrombearings.h"
#include "besseli.h"
#include "combineVectorElements.h"
#include "cotd.h"
#include "div.h"
#include "find.h"
#include "ixfun.h"
#include "localize_data.h"
#include "localize_internal_types.h"
#include "localize_rtwutil.h"
#include "median.h"
#include "nchoosek.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "table.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Declarations
static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<double, 1U> &in2,
                             const coder::array<double, 2U> &in3,
                             const coder::array<double, 1U> &in4);

static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<double, 1U> &in2,
                             const coder::array<double, 1U> &in3,
                             const coder::array<double, 1U> &in4);

static void binary_expand_op(coder::array<double, 1U> &in1, const double in2[2],
                             const coder::array<double, 1U> &in3);

static double binary_expand_op(const coder::array<double, 1U> &in1,
                               const coder::array<double, 1U> &in2);

static void c_binary_expand_op(coder::array<boolean_T, 1U> &in1,
                               const coder::array<double, 1U> &in2,
                               const coder::array<double, 1U> &in3);

static void d_binary_expand_op(coder::array<boolean_T, 1U> &in1,
                               const coder::array<double, 1U> &in2,
                               const coder::array<double, 1U> &in3,
                               const coder::array<double, 1U> &in4);

static void e_binary_expand_op(double in1[2],
                               const coder::array<double, 1U> &in2,
                               const coder::array<double, 1U> &in3,
                               const coder::array<double, 1U> &in4,
                               const coder::array<double, 1U> &in5);

static void minus(coder::array<double, 1U> &in1,
                  const coder::array<double, 1U> &in2);

// Function Definitions
//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 2U> &in3
//                const coder::array<double, 1U> &in4
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<double, 1U> &in2,
                             const coder::array<double, 2U> &in3,
                             const coder::array<double, 1U> &in4)
{
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in4.size(0) == 1) {
    loop_ub = in3.size(0);
  } else {
    loop_ub = in4.size(0);
  }
  in1.set_size(loop_ub);
  stride_0_0 = (in3.size(0) != 1);
  stride_1_0 = (in4.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] =
        in2[static_cast<int>(in3[i * stride_0_0]) - 1] * in4[i * stride_1_0];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<double, 1U> &in2,
                             const coder::array<double, 1U> &in3,
                             const coder::array<double, 1U> &in4)
{
  coder::array<double, 1U> b_in1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  if (in4.size(0) == 1) {
    if (in3.size(0) == 1) {
      if (in2.size(0) == 1) {
        loop_ub = in1.size(0);
      } else {
        loop_ub = in2.size(0);
      }
    } else {
      loop_ub = in3.size(0);
    }
  } else {
    loop_ub = in4.size(0);
  }
  b_in1.set_size(loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  stride_2_0 = (in3.size(0) != 1);
  stride_3_0 = (in4.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    b_in1[i] =
        (in1[i * stride_0_0] * in2[i * stride_1_0] + in3[i * stride_2_0]) -
        in4[i * stride_3_0];
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const double in2[2]
//                const coder::array<double, 1U> &in3
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &in1, const double in2[2],
                             const coder::array<double, 1U> &in3)
{
  int loop_ub;
  int stride_1_0;
  if (in3.size(0) == 1) {
    loop_ub = static_cast<int>(in2[0]);
  } else {
    loop_ub = in3.size(0);
  }
  in1.set_size(loop_ub);
  stride_1_0 = (in3.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = in3[i * stride_1_0];
  }
}

//
// Arguments    : const coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
// Return Type  : double
//
static double binary_expand_op(const coder::array<double, 1U> &in1,
                               const coder::array<double, 1U> &in2)
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
    b_in1[i] = in1[i * stride_0_0] * in2[i * stride_1_0];
  }
  return coder::combineVectorElements(b_in1) /
         coder::combineVectorElements(in1);
}

//
// Arguments    : coder::array<boolean_T, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
// Return Type  : void
//
static void c_binary_expand_op(coder::array<boolean_T, 1U> &in1,
                               const coder::array<double, 1U> &in2,
                               const coder::array<double, 1U> &in3)
{
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  in1.set_size(loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = ((!std::isnan(in2[i * stride_0_0])) &&
              (!std::isnan(in3[i * stride_1_0])));
  }
}

//
// Arguments    : coder::array<boolean_T, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
// Return Type  : void
//
static void d_binary_expand_op(coder::array<boolean_T, 1U> &in1,
                               const coder::array<double, 1U> &in2,
                               const coder::array<double, 1U> &in3,
                               const coder::array<double, 1U> &in4)
{
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  if (in4.size(0) == 1) {
    if (in3.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in3.size(0);
    }
  } else {
    loop_ub = in4.size(0);
  }
  in1.set_size(loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  stride_2_0 = (in4.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = ((!std::isnan(in2[i * stride_0_0])) &&
              (!std::isnan(in3[i * stride_1_0])) &&
              (!std::isnan(in4[i * stride_2_0])));
  }
}

//
// Arguments    : double in1[2]
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
//                const coder::array<double, 1U> &in5
// Return Type  : void
//
static void e_binary_expand_op(double in1[2],
                               const coder::array<double, 1U> &in2,
                               const coder::array<double, 1U> &in3,
                               const coder::array<double, 1U> &in4,
                               const coder::array<double, 1U> &in5)
{
  coder::array<double, 1U> b_in2;
  coder::array<double, 1U> c_in2;
  int loop_ub;
  int stride_0_0_tmp;
  int stride_1_0;
  int stride_2_0_tmp;
  if (in4.size(0) == 1) {
    if (in3.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in3.size(0);
    }
  } else {
    loop_ub = in4.size(0);
  }
  b_in2.set_size(loop_ub);
  stride_0_0_tmp = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  stride_2_0_tmp = (in4.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    b_in2[i] =
        in2[i * stride_0_0_tmp] * in3[i * stride_1_0] * in4[i * stride_2_0_tmp];
  }
  if (in4.size(0) == 1) {
    if (in5.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in5.size(0);
    }
  } else {
    loop_ub = in4.size(0);
  }
  c_in2.set_size(loop_ub);
  stride_1_0 = (in5.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    c_in2[i] =
        in2[i * stride_0_0_tmp] * in5[i * stride_1_0] * in4[i * stride_2_0_tmp];
  }
  in1[0] = coder::combineVectorElements(b_in2);
  in1[1] = -coder::combineVectorElements(c_in2);
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
// Return Type  : void
//
static void minus(coder::array<double, 1U> &in1,
                  const coder::array<double, 1U> &in2)
{
  coder::array<double, 1U> b_in2;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in1.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in1.size(0);
  }
  b_in2.set_size(loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in1.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    b_in2[i] = in2[i * stride_0_0] - in1[i * stride_1_0];
  }
  in1.set_size(b_in2.size(0));
  loop_ub = b_in2.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = b_in2[i];
  }
}

//
// Arguments    : coder::array<boolean_T, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
//                const coder::table &in4
// Return Type  : void
//
void b_binary_expand_op(coder::array<boolean_T, 1U> &in1,
                        const coder::array<double, 1U> &in2,
                        const coder::array<double, 1U> &in3,
                        const coder::table &in4)
{
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  if (in3.size(0) == 1) {
    i = in2.size(0);
  } else {
    i = in3.size(0);
  }
  if (in4.data.f3.size(0) == 1) {
    stride_0_0 = i;
  } else {
    stride_0_0 = in4.data.f3.size(0);
  }
  in1.set_size(stride_0_0);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  stride_2_0 = (in4.data.f3.size(0) != 1);
  if (in4.data.f3.size(0) == 1) {
    loop_ub = i;
  } else {
    loop_ub = in4.data.f3.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    in1[i] = ((!std::isnan(in2[i * stride_0_0])) &&
              (!std::isnan(in3[i * stride_1_0])) &&
              (!std::isnan(in4.data.f3[i * stride_2_0])));
  }
}

//
// LOCALIZE estimates a location based on a series of bearing estimates using
// localization methods presented in Lenth's 1972 paper cited below. The
// methods include MLE with, repeated median regression, and an M-estimator.
// The outputs is an x-y vector of estimated position found through the
// method requested.
//
// Arguments    : coder::array<double, 1U> &X
//                coder::array<double, 1U> &Y
//                coder::array<double, 1U> &T
//                double position[2]
// Return Type  : void
//
void b_localizefrombearings(coder::array<double, 1U> &X,
                            coder::array<double, 1U> &Y,
                            coder::array<double, 1U> &T, double position[2])
{
  coder::array<creal_T, 1U> c_y;
  coder::array<double, 1U> b_mu_i;
  coder::array<double, 1U> b_y;
  coder::array<double, 1U> ci;
  coder::array<double, 1U> ci_hat_str;
  coder::array<double, 1U> mu_i;
  coder::array<double, 1U> si;
  coder::array<double, 1U> si_hat_str;
  coder::array<double, 1U> theta_i;
  coder::array<double, 1U> wi;
  coder::array<double, 1U> y;
  coder::array<double, 1U> zi;
  coder::array<boolean_T, 1U> r;
  double pos3[2000];
  double A[4];
  double bess_input[2];
  double a21;
  double s;
  int b_loop_ub;
  int i;
  int loop_ub;
  int num_bears;
  int r1;
  int r2;
  // NOTE: Lenth uses X (East) and Y (North) position and bearing angles as
  // compass headings, which are positive CW from North. This program stays
  // consistent with this notation and the X and Y positions, should be the
  // East and North positions from which the bearings were measured. This may
  // conflict with the frames used by the program calling localize. If the
  // X-North Y-East coordinate frame is used, x and y positions entered to this
  // function can simply be switched, and the output positions should also then
  // be switched.
  //  INPUTS:
  // X           -    n x 1 vector of x-location where pulse_sig was measured.
  //                        X here is distance East "
  // Y           -    n x 1 vector of y-location where pulse_sig was measured
  // T           -    n x 1 vector of bearing angles in DEGREES from North with
  //                        positive in CW direction. Standard compass bearing.
  // method      -    a char array of selected method:
  //                    Options are 'MLE', 'RMR', or 'MEST'
  //  OUTPUTS:
  // position    -    1 x 2 estimate of [x,y] location of signal origin
  // Methods implemented here are from
  // Lenth, Russell. On Finding the Source of a Signal. Technometeric. Vol. 23,
  // No. 2, 1981.
  // MLE: Maximum likely hood esitmator
  // RMR: Repeated median regression
  // MEST: M-estimation with Andrews psi function with c = 1.5
  // Make sure these are all column vectors
  if ((X.size(0) == Y.size(0)) && (X.size(0) == T.size(0))) {
    // Eliminate any that have NaN X, Y, or T values.
    if (X.size(0) == 1) {
      num_bears = Y.size(0);
    } else {
      num_bears = X.size(0);
    }
    if ((X.size(0) == Y.size(0)) && (num_bears == T.size(0))) {
      r.set_size(X.size(0));
      loop_ub = X.size(0);
      for (int k{0}; k < loop_ub; k++) {
        r[k] =
            ((!std::isnan(X[k])) && (!std::isnan(Y[k])) && (!std::isnan(T[k])));
      }
    } else {
      d_binary_expand_op(r, X, Y, T);
    }
    r2 = r.size(0) - 1;
    num_bears = 0;
    r1 = 0;
    for (i = 0; i <= r2; i++) {
      if (r[i]) {
        num_bears++;
      }
      if (r[i]) {
        X[r1] = X[i];
        r1++;
      }
    }
    r1 = 0;
    for (i = 0; i <= r2; i++) {
      if (r[i]) {
        Y[r1] = Y[i];
        r1++;
      }
    }
    r1 = 0;
    for (i = 0; i <= r2; i++) {
      if (r[i]) {
        T[r1] = T[i];
        r1++;
      }
    }
  } else {
    // Check to see that vectors are same length
  }
  // Standardize the shape of all the input vectors
  X.set_size(num_bears);
  Y.set_size(num_bears);
  T.set_size(num_bears);
  //  %Prep some variables that will be needed for RMR
  //  if strcmp(method,'RMR')
  //      %Create the element selection vectors
  //      %This creates the list of all combintations
  //      bc = nchoosek(1:num_bears,2);
  //      bcA = bc(:,1);
  //      bcB = bc(:,2);
  //      %Generate the positions and angles of the different selected elements
  //      for %comparison: A vs B. XA = X(bcA); XB = X(bcB); YA = Y(bcA); YB =
  //      Y(bcB); TA = T(bcA); TB = T(bcB); %Find the intersection points for
  //      all the A and B lines X_int = (YA - YB + XB.*cotd(TB) -
  //      XA.*cotd(TA))./(cotd(TB)-cotd(TA)); Y_int =
  //      cotd(TA).*X_int+YA-XA.*cotd(TA); %Some test cases had a few NaN
  //      locations, so only track those that have no %NaNs either X_int and
  //      Y_int. We redefine everything here to rid the record %of those points.
  //      valid_pos_msk = ~isnan(X_int)&~isnan(Y_int);
  //      X_int = X_int(valid_pos_msk);
  //      Y_int = Y_int(valid_pos_msk);
  //  end
  //  MAXIMUM LIKELYHOOD ESTIMATOR
  theta_i.set_size(num_bears);
  for (int k{0}; k < num_bears; k++) {
    theta_i[k] = 0.017453292519943295 * (90.0 - T[k]);
  }
  // On page 1, paragraph of the Lenth paper.
  //  Lenth says x is E and y is N, but we use x N and y E,
  si.set_size(theta_i.size(0));
  loop_ub = theta_i.size(0);
  ci.set_size(theta_i.size(0));
  for (int k{0}; k < loop_ub; k++) {
    si[k] = std::sin(theta_i[k]);
    ci[k] = std::cos(theta_i[k]);
  }
  if ((si.size(0) == num_bears) && (ci.size(0) == num_bears)) {
    zi.set_size(si.size(0));
    loop_ub = si.size(0);
    for (int k{0}; k < loop_ub; k++) {
      zi[k] = si[k] * X[k] - ci[k] * Y[k];
    }
  } else {
    binary_expand_op(zi, si, X, ci, Y);
  }
  bess_input[0] = X.size(0);
  bess_input[1] = 1.0;
  wi.set_size(X.size(0));
  loop_ub = X.size(0);
  for (int k{0}; k < loop_ub; k++) {
    wi[k] = 1.0;
  }
  std::memset(&pos3[0], 0, 2000U * sizeof(double));
  if (X.size(0) == si.size(0)) {
    y.set_size(si.size(0));
    loop_ub = si.size(0);
    for (int k{0}; k < loop_ub; k++) {
      y[k] = si[k];
    }
  } else {
    binary_expand_op(y, bess_input, si);
  }
  if (static_cast<int>(bess_input[0]) == ci.size(0)) {
    mu_i.set_size(ci.size(0));
    loop_ub = ci.size(0);
    for (int k{0}; k < loop_ub; k++) {
      mu_i[k] = ci[k];
    }
  } else {
    binary_expand_op(mu_i, bess_input, ci);
  }
  if ((y.size(0) == si.size(0)) && (mu_i.size(0) == si.size(0)) &&
      (y.size(0) == ci.size(0)) && (mu_i.size(0) == ci.size(0))) {
    b_y.set_size(y.size(0));
    loop_ub = y.size(0);
    for (int k{0}; k < loop_ub; k++) {
      b_y[k] = y[k] * si[k];
    }
    b_mu_i.set_size(mu_i.size(0));
    loop_ub = mu_i.size(0);
    for (int k{0}; k < loop_ub; k++) {
      b_mu_i[k] = mu_i[k] * si[k];
    }
    s = coder::combineVectorElements(b_y);
    a21 = coder::combineVectorElements(b_mu_i);
    b_y.set_size(y.size(0));
    loop_ub = y.size(0);
    for (int k{0}; k < loop_ub; k++) {
      b_y[k] = y[k] * ci[k];
    }
    b_mu_i.set_size(mu_i.size(0));
    loop_ub = mu_i.size(0);
    for (int k{0}; k < loop_ub; k++) {
      b_mu_i[k] = mu_i[k] * ci[k];
    }
    A[0] = s;
    A[2] = -a21;
    A[1] = -coder::combineVectorElements(b_y);
    A[3] = coder::combineVectorElements(b_mu_i);
  } else {
    binary_expand_op(A, y, si, mu_i, ci);
  }
  if ((y.size(0) == zi.size(0)) && (mu_i.size(0) == zi.size(0))) {
    loop_ub = y.size(0);
    for (int k{0}; k < loop_ub; k++) {
      y[k] = y[k] * zi[k];
    }
    loop_ub = mu_i.size(0);
    for (int k{0}; k < loop_ub; k++) {
      mu_i[k] = mu_i[k] * zi[k];
    }
    bess_input[0] = coder::combineVectorElements(y);
    bess_input[1] = -coder::combineVectorElements(mu_i);
  } else {
    binary_expand_op(bess_input, y, zi, mu_i);
  }
  if (std::abs(A[1]) > std::abs(A[0])) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }
  a21 = A[r2] / A[r1];
  s = A[r1 + 2];
  pos3[1] = (bess_input[r2] - bess_input[r1] * a21) / (A[r2 + 2] - a21 * s);
  pos3[0] = (bess_input[r1] - pos3[1] * s) / A[r1];
  i = 1;
  loop_ub = Y.size(0);
  b_loop_ub = X.size(0);
  a21 = 1.0;
  while (a21 > 0.001) {
    creal_T x[2];
    double bi;
    double br;
    double brm;
    r2 = (i - 1) << 1;
    a21 = pos3[r2 + 1];
    si_hat_str.set_size(Y.size(0));
    for (int k{0}; k < loop_ub; k++) {
      si_hat_str[k] = a21 - Y[k];
    }
    a21 = pos3[r2];
    ci_hat_str.set_size(X.size(0));
    for (int k{0}; k < b_loop_ub; k++) {
      ci_hat_str[k] = a21 - X[k];
    }
    if (si_hat_str.size(0) == ci_hat_str.size(0)) {
      mu_i.set_size(si_hat_str.size(0));
      r1 = si_hat_str.size(0);
      for (int k{0}; k < r1; k++) {
        s = si_hat_str[k];
        a21 = ci_hat_str[k];
        mu_i[k] = rt_atan2d_snf(s, a21);
      }
    } else {
      coder::internal::expand_atan2(si_hat_str, ci_hat_str, mu_i);
    }
    if (theta_i.size(0) == mu_i.size(0)) {
      mu_i.set_size(theta_i.size(0));
      r1 = theta_i.size(0);
      for (int k{0}; k < r1; k++) {
        mu_i[k] = theta_i[k] - mu_i[k];
      }
    } else {
      minus(mu_i, theta_i);
    }
    // Update on 2023-07-03
    y.set_size(mu_i.size(0));
    r1 = mu_i.size(0);
    for (int k{0}; k < r1; k++) {
      y[k] = std::cos(mu_i[k]);
    }
    if (wi.size(0) == y.size(0)) {
      y.set_size(wi.size(0));
      r1 = wi.size(0);
      for (int k{0}; k < r1; k++) {
        y[k] = wi[k] * y[k];
      }
      a21 = coder::combineVectorElements(y) / coder::combineVectorElements(wi);
    } else {
      a21 = binary_expand_op(wi, y);
    }
    // The method below would break if C_bar_w = 1...
    //  kappa =
    //  1/(2*(1-C_bar_w)+(1-C_bar_w)^2*(0.48794-0.82905*C_bar_w-1.3915*C_bar_w^2)/C_bar_w);
    // so we use the derivative discussed before eqn 2.10 in Lenth using
    // a small step to approximate the derivative of the ln of the Bessel
    bess_input[0] = a21 - 0.0001;
    bess_input[1] = a21 + 0.0001;
    // Create input to bessel function to take derivative; Small step back that
    // we'll use to approx derivative.
    coder::besseli(bess_input, x);
    if (x[0].im == 0.0) {
      if (x[0].re < 0.0) {
        x[0].re = std::log(std::abs(x[0].re));
        x[0].im = 3.1415926535897931;
      } else {
        x[0].re = std::log(std::abs(x[0].re));
        x[0].im = 0.0;
      }
    } else if ((std::abs(x[0].re) > 8.9884656743115785E+307) ||
               (std::abs(x[0].im) > 8.9884656743115785E+307)) {
      s = x[0].re;
      x[0].re = std::log(rt_hypotd_snf(x[0].re / 2.0, x[0].im / 2.0)) +
                0.69314718055994529;
      x[0].im = rt_atan2d_snf(x[0].im, s);
    } else {
      s = x[0].re;
      x[0].re = std::log(rt_hypotd_snf(x[0].re, x[0].im));
      x[0].im = rt_atan2d_snf(x[0].im, s);
    }
    if (x[1].im == 0.0) {
      if (x[1].re < 0.0) {
        x[1].re = std::log(std::abs(x[1].re));
        x[1].im = 3.1415926535897931;
      } else {
        x[1].re = std::log(std::abs(x[1].re));
        x[1].im = 0.0;
      }
    } else if ((std::abs(x[1].re) > 8.9884656743115785E+307) ||
               (std::abs(x[1].im) > 8.9884656743115785E+307)) {
      s = x[1].re;
      x[1].re = std::log(rt_hypotd_snf(x[1].re / 2.0, x[1].im / 2.0)) +
                0.69314718055994529;
      x[1].im = rt_atan2d_snf(x[1].im, s);
    } else {
      s = x[1].re;
      x[1].re = std::log(rt_hypotd_snf(x[1].re, x[1].im));
      x[1].im = rt_atan2d_snf(x[1].im, s);
    }
    s = x[1].re - x[0].re;
    brm = x[1].im - x[0].im;
    a21 = (a21 + 0.0001) - (a21 - 0.0001);
    if (brm == 0.0) {
      br = s / a21;
      bi = 0.0;
    } else if (s == 0.0) {
      br = 0.0;
      bi = brm / a21;
    } else {
      br = s / a21;
      bi = brm / a21;
    }
    brm = std::abs(br);
    a21 = std::abs(bi);
    if (bi == 0.0) {
      br = 1.0 / br;
      bi = 0.0;
    } else if (br == 0.0) {
      br = 0.0;
      bi = -1.0 / bi;
    } else if (brm > a21) {
      s = bi / br;
      a21 = br + s * bi;
      br = 1.0 / a21;
      bi = -s / a21;
    } else if (brm == a21) {
      a21 = 0.5;
      if (br < 0.0) {
        a21 = -0.5;
      }
      s = 0.5;
      if (bi < 0.0) {
        s = -0.5;
      }
      br = a21 / brm;
      bi = -s / brm;
    } else {
      s = br / bi;
      a21 = bi + s * br;
      br = s / a21;
      bi = -1.0 / a21;
    }
    br *= 2.0;
    bi *= 2.0;
    r2 = mu_i.size(0);
    for (int k{0}; k < r2; k++) {
      mu_i[k] = std::cos(mu_i[k]);
    }
    c_y.set_size(mu_i.size(0));
    r1 = mu_i.size(0);
    for (int k{0}; k < r1; k++) {
      c_y[k].re = (1.0 - mu_i[k]) * br;
      c_y[k].im = (1.0 - mu_i[k]) * bi;
    }
    r2 = c_y.size(0);
    for (int k{0}; k < r2; k++) {
      coder::internal::scalar::b_sqrt(&c_y[k]);
    }
    mu_i.set_size(c_y.size(0));
    r1 = c_y.size(0);
    for (int k{0}; k < r1; k++) {
      mu_i[k] = c_y[k].re;
    }
    // Real is so that coder knows this has no complex parts. We know the
    // argument of the sqrt is bounded to be greater than zero.
    wi.set_size(mu_i.size(0));
    r1 = mu_i.size(0);
    for (int k{0}; k < r1; k++) {
      wi[k] = mu_i[k] / 1.5;
    }
    r2 = wi.size(0);
    y.set_size(mu_i.size(0));
    for (int k{0}; k < r2; k++) {
      wi[k] = std::sin(wi[k]);
      y[k] = std::abs(mu_i[k]);
    }
    // I_(abs(t)<c*pi) is the indicator function
    if (wi.size(0) == 1) {
      num_bears = y.size(0);
    } else {
      num_bears = wi.size(0);
    }
    if ((wi.size(0) == y.size(0)) && (num_bears == mu_i.size(0))) {
      r1 = wi.size(0);
      for (int k{0}; k < r1; k++) {
        wi[k] = 1.5 * wi[k] * static_cast<double>(y[k] < 4.71238898038469) /
                mu_i[k];
      }
    } else {
      e_binary_expand_op(wi, y, mu_i);
    }
    r1 = mu_i.size(0) - 1;
    for (r2 = 0; r2 <= r1; r2++) {
      if (mu_i[r2] == 0.0) {
        wi[r2] = 1.0;
      }
    }
    // Specified below equation eqn 4.7 in Lenth paper
    if (ci_hat_str.size(0) == si_hat_str.size(0)) {
      mu_i.set_size(ci_hat_str.size(0));
      r1 = ci_hat_str.size(0);
      for (int k{0}; k < r1; k++) {
        s = ci_hat_str[k];
        a21 = si_hat_str[k];
        mu_i[k] = s * s + a21 * a21;
      }
    } else {
      binary_expand_op(mu_i, ci_hat_str, si_hat_str);
    }
    r2 = mu_i.size(0);
    for (int k{0}; k < r2; k++) {
      mu_i[k] = std::sqrt(mu_i[k]);
    }
    r1 = mu_i.size(0);
    for (int k{0}; k < r1; k++) {
      s = mu_i[k];
      mu_i[k] = rt_powd_snf(s, 3.0);
    }
    if (si_hat_str.size(0) == mu_i.size(0)) {
      r1 = si_hat_str.size(0);
      for (int k{0}; k < r1; k++) {
        si_hat_str[k] = si_hat_str[k] / mu_i[k];
      }
    } else {
      rdivide(si_hat_str, mu_i);
    }
    if (ci_hat_str.size(0) == mu_i.size(0)) {
      r1 = ci_hat_str.size(0);
      for (int k{0}; k < r1; k++) {
        ci_hat_str[k] = ci_hat_str[k] / mu_i[k];
      }
    } else {
      rdivide(ci_hat_str, mu_i);
    }
    if (wi.size(0) == si.size(0)) {
      y.set_size(wi.size(0));
      r1 = wi.size(0);
      for (int k{0}; k < r1; k++) {
        y[k] = wi[k] * si[k];
      }
    } else {
      times(y, wi, si);
    }
    if (wi.size(0) == ci.size(0)) {
      mu_i.set_size(wi.size(0));
      r1 = wi.size(0);
      for (int k{0}; k < r1; k++) {
        mu_i[k] = wi[k] * ci[k];
      }
    } else {
      times(mu_i, wi, ci);
    }
    if ((y.size(0) == si_hat_str.size(0)) &&
        (mu_i.size(0) == si_hat_str.size(0)) &&
        (y.size(0) == ci_hat_str.size(0)) &&
        (mu_i.size(0) == ci_hat_str.size(0))) {
      b_y.set_size(y.size(0));
      r1 = y.size(0);
      for (int k{0}; k < r1; k++) {
        b_y[k] = y[k] * si_hat_str[k];
      }
      b_mu_i.set_size(mu_i.size(0));
      r1 = mu_i.size(0);
      for (int k{0}; k < r1; k++) {
        b_mu_i[k] = mu_i[k] * si_hat_str[k];
      }
      r1 = y.size(0);
      for (int k{0}; k < r1; k++) {
        y[k] = y[k] * ci_hat_str[k];
      }
      r1 = mu_i.size(0);
      for (int k{0}; k < r1; k++) {
        mu_i[k] = mu_i[k] * ci_hat_str[k];
      }
      A[0] = coder::combineVectorElements(b_y);
      A[2] = -coder::combineVectorElements(b_mu_i);
      A[1] = -coder::combineVectorElements(y);
      A[3] = coder::combineVectorElements(mu_i);
    } else {
      binary_expand_op(A, y, si_hat_str, mu_i, ci_hat_str);
    }
    if (wi.size(0) == 1) {
      num_bears = si_hat_str.size(0);
    } else {
      num_bears = wi.size(0);
    }
    if (wi.size(0) == 1) {
      r1 = ci_hat_str.size(0);
    } else {
      r1 = wi.size(0);
    }
    if ((wi.size(0) == si_hat_str.size(0)) && (num_bears == zi.size(0)) &&
        (wi.size(0) == ci_hat_str.size(0)) && (r1 == zi.size(0))) {
      si_hat_str.set_size(wi.size(0));
      r1 = wi.size(0);
      ci_hat_str.set_size(wi.size(0));
      for (int k{0}; k < r1; k++) {
        si_hat_str[k] = wi[k] * si_hat_str[k] * zi[k];
        ci_hat_str[k] = wi[k] * ci_hat_str[k] * zi[k];
      }
      bess_input[0] = coder::combineVectorElements(si_hat_str);
      bess_input[1] = -coder::combineVectorElements(ci_hat_str);
    } else {
      e_binary_expand_op(bess_input, wi, si_hat_str, zi, ci_hat_str);
    }
    if (std::abs(A[1]) > std::abs(A[0])) {
      r1 = 1;
      r2 = 0;
    } else {
      r1 = 0;
      r2 = 1;
    }
    a21 = A[r2] / A[r1];
    num_bears = i << 1;
    s = A[r1 + 2];
    pos3[num_bears + 1] =
        (bess_input[r2] - bess_input[r1] * a21) / (A[r2 + 2] - a21 * s);
    pos3[num_bears] = (bess_input[r1] - pos3[num_bears + 1] * s) / A[r1];
    // ([sum(si.*si_str) -sum(ci.*si_str);-sum(si.*ci_str)
    // sum(ci.*ci_str)])\[sum(si_str.*zi);-sum(ci_str.*zi)];
    i++;
    s = 3.3121686421112381E-170;
    r1 = (i - 1) << 1;
    r2 = (i - 2) << 1;
    brm = std::abs(pos3[r1] - pos3[r2]);
    if (brm > 3.3121686421112381E-170) {
      a21 = 1.0;
      s = brm;
    } else {
      bi = brm / 3.3121686421112381E-170;
      a21 = bi * bi;
    }
    brm = std::abs(pos3[r1 + 1] - pos3[r2 + 1]);
    if (brm > s) {
      bi = s / brm;
      a21 = a21 * bi * bi + 1.0;
      s = brm;
    } else {
      bi = brm / s;
      a21 += bi * bi;
    }
    a21 = s * std::sqrt(a21);
  }
  r2 = (i - 2) << 1;
  position[0] = pos3[r2];
  position[1] = pos3[r2 + 1];
  // disp(['loc_error_MEST = ',num2str(norm(pos_MEST))])
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
//                const coder::array<double, 1U> &in5
// Return Type  : void
//
void binary_expand_op(coder::array<double, 1U> &in1,
                      const coder::array<double, 1U> &in2,
                      const coder::array<double, 1U> &in3,
                      const coder::array<double, 1U> &in4,
                      const coder::array<double, 1U> &in5)
{
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  if (in5.size(0) == 1) {
    i = in4.size(0);
  } else {
    i = in5.size(0);
  }
  if (i == 1) {
    if (in3.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in3.size(0);
    }
  } else {
    loop_ub = i;
  }
  in1.set_size(loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  stride_2_0 = (in4.size(0) != 1);
  stride_3_0 = (in5.size(0) != 1);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = in2[i * stride_0_0] * in3[i * stride_1_0] -
             in4[i * stride_2_0] * in5[i * stride_3_0];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
// Return Type  : void
//
void binary_expand_op(coder::array<double, 1U> &in1,
                      const coder::array<double, 1U> &in3,
                      const coder::array<double, 1U> &in4)
{
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in4.size(0) == 1) {
    loop_ub = in3.size(0);
  } else {
    loop_ub = in4.size(0);
  }
  in1.set_size(loop_ub);
  stride_0_0 = (in3.size(0) != 1);
  stride_1_0 = (in4.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    double b_varargin_1;
    double varargin_1;
    varargin_1 = in3[i * stride_0_0];
    b_varargin_1 = in4[i * stride_1_0];
    in1[i] = varargin_1 * varargin_1 + b_varargin_1 * b_varargin_1;
  }
}

//
// Arguments    : double in1[4]
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
//                const coder::array<double, 1U> &in5
// Return Type  : void
//
void binary_expand_op(double in1[4], const coder::array<double, 1U> &in2,
                      const coder::array<double, 1U> &in3,
                      const coder::array<double, 1U> &in4,
                      const coder::array<double, 1U> &in5)
{
  coder::array<double, 1U> b_in2;
  coder::array<double, 1U> b_in4;
  double d;
  double d1;
  int b_stride_0_0_tmp;
  int loop_ub;
  int stride_0_0_tmp;
  int stride_1_0_tmp;
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  b_in2.set_size(loop_ub);
  stride_0_0_tmp = (in2.size(0) != 1);
  stride_1_0_tmp = (in3.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    b_in2[i] = in2[i * stride_0_0_tmp] * in3[i * stride_1_0_tmp];
  }
  if (in3.size(0) == 1) {
    loop_ub = in4.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  b_in4.set_size(loop_ub);
  b_stride_0_0_tmp = (in4.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    b_in4[i] = in4[i * b_stride_0_0_tmp] * in3[i * stride_1_0_tmp];
  }
  d = coder::combineVectorElements(b_in2);
  d1 = coder::combineVectorElements(b_in4);
  if (in5.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in5.size(0);
  }
  b_in2.set_size(loop_ub);
  stride_1_0_tmp = (in5.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    b_in2[i] = in2[i * stride_0_0_tmp] * in5[i * stride_1_0_tmp];
  }
  if (in5.size(0) == 1) {
    loop_ub = in4.size(0);
  } else {
    loop_ub = in5.size(0);
  }
  b_in4.set_size(loop_ub);
  for (int i{0}; i < loop_ub; i++) {
    b_in4[i] = in4[i * b_stride_0_0_tmp] * in5[i * stride_1_0_tmp];
  }
  in1[0] = d;
  in1[2] = -d1;
  in1[1] = -coder::combineVectorElements(b_in2);
  in1[3] = coder::combineVectorElements(b_in4);
}

//
// Arguments    : double in1[2]
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
// Return Type  : void
//
void binary_expand_op(double in1[2], const coder::array<double, 1U> &in2,
                      const coder::array<double, 1U> &in3,
                      const coder::array<double, 1U> &in4)
{
  coder::array<double, 1U> b_in2;
  coder::array<double, 1U> b_in4;
  int loop_ub;
  int stride_0_0;
  int stride_1_0_tmp;
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  b_in2.set_size(loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0_tmp = (in3.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    b_in2[i] = in2[i * stride_0_0] * in3[i * stride_1_0_tmp];
  }
  if (in3.size(0) == 1) {
    loop_ub = in4.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  b_in4.set_size(loop_ub);
  stride_0_0 = (in4.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    b_in4[i] = in4[i * stride_0_0] * in3[i * stride_1_0_tmp];
  }
  in1[0] = coder::combineVectorElements(b_in2);
  in1[1] = -coder::combineVectorElements(b_in4);
}

//
// LOCALIZE estimates a location based on a series of bearing estimates using
// localization methods presented in Lenth's 1972 paper cited below. The
// methods include MLE with, repeated median regression, and an M-estimator.
// The outputs is an x-y vector of estimated position found through the
// method requested.
//
// Arguments    : coder::array<double, 1U> &X
//                coder::array<double, 1U> &Y
//                coder::array<double, 1U> &T
//                double position[2]
// Return Type  : void
//
void localizefrombearings(coder::array<double, 1U> &X,
                          coder::array<double, 1U> &Y,
                          coder::array<double, 1U> &T, double position[2])
{
  coder::array<double, 2U> MED_INT_LOG;
  coder::array<double, 2U> b_bc;
  coder::array<double, 2U> int_log;
  coder::array<double, 1U> X_int;
  coder::array<double, 1U> YA;
  coder::array<double, 1U> Y_int;
  coder::array<double, 1U> b_X_int;
  coder::array<double, 1U> b_r;
  coder::array<unsigned int, 2U> y;
  coder::array<int, 1U> r2;
  coder::array<boolean_T, 1U> bc;
  coder::array<boolean_T, 1U> r1;
  double b_y;
  int a;
  int combj;
  int i;
  int nmkpi;
  int nrows;
  int num_bears;
  int r;
  // NOTE: Lenth uses X (East) and Y (North) position and bearing angles as
  // compass headings, which are positive CW from North. This program stays
  // consistent with this notation and the X and Y positions, should be the
  // East and North positions from which the bearings were measured. This may
  // conflict with the frames used by the program calling localize. If the
  // X-North Y-East coordinate frame is used, x and y positions entered to this
  // function can simply be switched, and the output positions should also then
  // be switched.
  //  INPUTS:
  // X           -    n x 1 vector of x-location where pulse_sig was measured.
  //                        X here is distance East "
  // Y           -    n x 1 vector of y-location where pulse_sig was measured
  // T           -    n x 1 vector of bearing angles in DEGREES from North with
  //                        positive in CW direction. Standard compass bearing.
  // method      -    a char array of selected method:
  //                    Options are 'MLE', 'RMR', or 'MEST'
  //  OUTPUTS:
  // position    -    1 x 2 estimate of [x,y] location of signal origin
  // Methods implemented here are from
  // Lenth, Russell. On Finding the Source of a Signal. Technometeric. Vol. 23,
  // No. 2, 1981.
  // MLE: Maximum likely hood esitmator
  // RMR: Repeated median regression
  // MEST: M-estimation with Andrews psi function with c = 1.5
  // Make sure these are all column vectors
  if ((X.size(0) == Y.size(0)) && (X.size(0) == T.size(0))) {
    // Eliminate any that have NaN X, Y, or T values.
    if (X.size(0) == 1) {
      i = Y.size(0);
    } else {
      i = X.size(0);
    }
    if ((X.size(0) == Y.size(0)) && (i == T.size(0))) {
      bc.set_size(X.size(0));
      r = X.size(0);
      for (i = 0; i < r; i++) {
        bc[i] =
            ((!std::isnan(X[i])) && (!std::isnan(Y[i])) && (!std::isnan(T[i])));
      }
    } else {
      d_binary_expand_op(bc, X, Y, T);
    }
    r = bc.size(0) - 1;
    num_bears = 0;
    nmkpi = 0;
    for (nrows = 0; nrows <= r; nrows++) {
      if (bc[nrows]) {
        num_bears++;
      }
      if (bc[nrows]) {
        X[nmkpi] = X[nrows];
        nmkpi++;
      }
    }
    nmkpi = 0;
    for (nrows = 0; nrows <= r; nrows++) {
      if (bc[nrows]) {
        Y[nmkpi] = Y[nrows];
        nmkpi++;
      }
    }
    nmkpi = 0;
    for (nrows = 0; nrows <= r; nrows++) {
      if (bc[nrows]) {
        T[nmkpi] = T[nrows];
        nmkpi++;
      }
    }
  } else {
    // Check to see that vectors are same length
  }
  // Standardize the shape of all the input vectors
  X.set_size(num_bears);
  Y.set_size(num_bears);
  T.set_size(num_bears);
  //  %Prep some variables that will be needed for RMR
  //  if strcmp(method,'RMR')
  //      %Create the element selection vectors
  //      %This creates the list of all combintations
  //      bc = nchoosek(1:num_bears,2);
  //      bcA = bc(:,1);
  //      bcB = bc(:,2);
  //      %Generate the positions and angles of the different selected elements
  //      for %comparison: A vs B. XA = X(bcA); XB = X(bcB); YA = Y(bcA); YB =
  //      Y(bcB); TA = T(bcA); TB = T(bcB); %Find the intersection points for
  //      all the A and B lines X_int = (YA - YB + XB.*cotd(TB) -
  //      XA.*cotd(TA))./(cotd(TB)-cotd(TA)); Y_int =
  //      cotd(TA).*X_int+YA-XA.*cotd(TA); %Some test cases had a few NaN
  //      locations, so only track those that have no %NaNs either X_int and
  //      Y_int. We redefine everything here to rid the record %of those points.
  //      valid_pos_msk = ~isnan(X_int)&~isnan(Y_int);
  //      X_int = X_int(valid_pos_msk);
  //      Y_int = Y_int(valid_pos_msk);
  //  end
  //  MAXIMUM LIKELYHOOD ESTIMATOR
  // On page 1, paragraph of the Lenth paper.
  //  Lenth says x is E and y is N, but we use x N and y E,
  // Create the element selection vectors
  // This creates the list of all combintations
  if (num_bears < 1) {
    y.set_size(1, 0);
  } else {
    y.set_size(1, num_bears);
    r = num_bears - 1;
    for (i = 0; i <= r; i++) {
      y[i] = static_cast<unsigned int>(i) + 1U;
    }
  }
  if (y.size(1) == 1) {
    r = 2;
    if (static_cast<int>(y[0]) - 2 < 2) {
      r = static_cast<int>(y[0]) - 2;
    }
    if (r == 0) {
      b_bc.set_size(1, 1);
      b_bc[0] = 1.0;
    } else if (r == 1) {
      b_bc.set_size(1, 1);
      b_bc[0] = y[0];
    } else {
      b_bc.set_size(1, 1);
      b_bc[0] = coder::nCk(static_cast<double>(y[0]), static_cast<double>(r));
    }
  } else if (y.size(1) < 2) {
    b_bc.set_size(0, 2);
  } else {
    int comb[2];
    r = 2;
    if (y.size(1) - 2 < 2) {
      r = y.size(1) - 2;
    }
    if (r == 0) {
      b_y = 1.0;
    } else if (r == 1) {
      b_y = y.size(1);
    } else {
      b_y = coder::nCk(static_cast<double>(y.size(1)), static_cast<double>(r));
    }
    nrows = static_cast<int>(std::floor(b_y));
    b_bc.set_size(nrows, 2);
    comb[0] = 1;
    comb[1] = 2;
    r = 1;
    nmkpi = y.size(1);
    for (int row{0}; row < nrows; row++) {
      b_bc[row] = y[comb[0] - 1];
      b_bc[row + b_bc.size(0)] = y[comb[1] - 1];
      if (r + 1 > 0) {
        a = comb[r];
        combj = comb[r] + 1;
        comb[r]++;
        if (a + 1 < nmkpi) {
          i = r + 2;
          for (a = i; a < 3; a++) {
            combj++;
            comb[1] = combj;
          }
          r = 1;
          nmkpi = y.size(1);
        } else {
          r--;
          nmkpi--;
        }
      }
    }
  }
  // Generate the positions and angles of the different selected elements for
  // comparison: A vs B.
  YA.set_size(b_bc.size(0));
  r = b_bc.size(0);
  // Find the intersection points for all the A and B lines
  X_int.set_size(b_bc.size(0));
  for (i = 0; i < r; i++) {
    YA[i] = Y[static_cast<int>(b_bc[i]) - 1];
    X_int[i] = T[static_cast<int>(b_bc[i + b_bc.size(0)]) - 1];
  }
  coder::b_cotd(X_int);
  Y_int.set_size(b_bc.size(0));
  r = b_bc.size(0);
  for (i = 0; i < r; i++) {
    Y_int[i] = T[static_cast<int>(b_bc[i]) - 1];
  }
  coder::b_cotd(Y_int);
  if (b_bc.size(0) == Y_int.size(0)) {
    b_r.set_size(b_bc.size(0));
    r = b_bc.size(0);
    for (i = 0; i < r; i++) {
      b_r[i] = X[static_cast<int>(b_bc[i]) - 1] * Y_int[i];
    }
  } else {
    binary_expand_op(b_r, X, b_bc, Y_int);
  }
  if (YA.size(0) == 1) {
    i = b_bc.size(0);
  } else {
    i = YA.size(0);
  }
  if (b_bc.size(0) == 1) {
    nmkpi = X_int.size(0);
  } else {
    nmkpi = b_bc.size(0);
  }
  if (i == 1) {
    r = nmkpi;
  } else {
    r = i;
  }
  if (r == 1) {
    combj = b_r.size(0);
  } else {
    combj = r;
  }
  if (X_int.size(0) == 1) {
    nrows = Y_int.size(0);
  } else {
    nrows = X_int.size(0);
  }
  if ((YA.size(0) == b_bc.size(0)) && (b_bc.size(0) == X_int.size(0)) &&
      (i == nmkpi) && (r == b_r.size(0)) && (X_int.size(0) == Y_int.size(0)) &&
      (combj == nrows)) {
    b_X_int.set_size(YA.size(0));
    r = YA.size(0);
    for (i = 0; i < r; i++) {
      b_y = b_bc[i + b_bc.size(0)];
      b_X_int[i] = (((YA[i] - Y[static_cast<int>(b_y) - 1]) +
                     X[static_cast<int>(b_y) - 1] * X_int[i]) -
                    b_r[i]) /
                   (X_int[i] - Y_int[i]);
    }
  } else {
    binary_expand_op(b_X_int, YA, Y, b_bc, X, X_int, b_r, Y_int);
  }
  if (Y_int.size(0) == 1) {
    i = b_X_int.size(0);
  } else {
    i = Y_int.size(0);
  }
  if (i == 1) {
    combj = YA.size(0);
  } else {
    combj = i;
  }
  if ((Y_int.size(0) == b_X_int.size(0)) && (i == YA.size(0)) &&
      (combj == b_r.size(0))) {
    r = Y_int.size(0);
    for (i = 0; i < r; i++) {
      Y_int[i] = (Y_int[i] * b_X_int[i] + YA[i]) - b_r[i];
    }
  } else {
    binary_expand_op(Y_int, b_X_int, YA, b_r);
  }
  // Some test cases had a few NaN locations, so only track those that have no
  // NaNs either X_int and Y_int. We redefine everything here to rid the record
  // of those points.
  if (b_X_int.size(0) == Y_int.size(0)) {
    r1.set_size(b_X_int.size(0));
    r = b_X_int.size(0);
    for (i = 0; i < r; i++) {
      r1[i] = ((!std::isnan(b_X_int[i])) && (!std::isnan(Y_int[i])));
    }
  } else {
    c_binary_expand_op(r1, b_X_int, Y_int);
  }
  r = r1.size(0) - 1;
  a = 0;
  nmkpi = 0;
  for (nrows = 0; nrows <= r; nrows++) {
    if (r1[nrows]) {
      a++;
    }
    if (r1[nrows]) {
      b_X_int[nmkpi] = b_X_int[nrows];
      nmkpi++;
    }
  }
  b_X_int.set_size(a);
  a = 0;
  nmkpi = 0;
  for (nrows = 0; nrows <= r; nrows++) {
    if (r1[nrows]) {
      a++;
    }
    if (r1[nrows]) {
      Y_int[nmkpi] = Y_int[nrows];
      nmkpi++;
    }
  }
  Y_int.set_size(a);
  // Define twice so coder knows it is variable size
  int_log.set_size(2, 100);
  MED_INT_LOG.set_size(2, 100);
  for (i = 0; i < 200; i++) {
    int_log[i] = rtNaN;
    MED_INT_LOG[i] = rtNaN;
  }
  for (nrows = 0; nrows < num_bears; nrows++) {
    unsigned int tick;
    tick = 1U;
    // Coder doesn't like loop indeces of unknown size so loop had to
    // change to that below with the if j~=i to not run for j == i
    for (a = 0; a < num_bears; a++) {
      if (a != nrows) {
        r = b_bc.size(0);
        bc.set_size(b_bc.size(0));
        for (i = 0; i < r; i++) {
          double d;
          b_y = b_bc[i];
          d = b_bc[i + b_bc.size(0)];
          bc[i] = (((b_y == static_cast<double>(nrows) + 1.0) &&
                    (d == static_cast<double>(a) + 1.0)) ||
                   ((d == static_cast<double>(nrows) + 1.0) &&
                    (b_y == static_cast<double>(a) + 1.0)));
        }
        coder::eml_find(bc, r2);
        YA.set_size(r2.size(0));
        r = r2.size(0);
        for (i = 0; i < r; i++) {
          YA[i] = r2[i];
        }
        // Find the entry that had both i and j in either the first or second
        // columns
        X_int.set_size(YA.size(0) + YA.size(0));
        r = YA.size(0);
        for (i = 0; i < r; i++) {
          X_int[i] = b_X_int[static_cast<int>(YA[i]) - 1];
        }
        r = YA.size(0);
        for (i = 0; i < r; i++) {
          X_int[i + YA.size(0)] = Y_int[static_cast<int>(YA[i]) - 1];
        }
        int_log[2 * (static_cast<int>(tick) - 1)] = X_int[0];
        int_log[2 * (static_cast<int>(tick) - 1) + 1] = X_int[1];
        // create a log of all i-th ray intersecting with all other rays
        tick++;
        if (tick > static_cast<unsigned int>(int_log.size(1))) {
          i = int_log.size(1);
          int_log.set_size(2, int_log.size(1) + 100);
          for (nmkpi = 0; nmkpi < 100; nmkpi++) {
            r = nmkpi + i;
            int_log[2 * r] = rtNaN;
            int_log[2 * r + 1] = rtNaN;
          }
          // Expand preallocation if needed
        }
      }
    }
    double MED_INT_LOG_tmp[2];
    coder::median(int_log, MED_INT_LOG_tmp);
    // take the mean of the i-th ray's intersection locations.
    MED_INT_LOG[2 * nrows] = MED_INT_LOG_tmp[0];
    MED_INT_LOG[2 * nrows + 1] = MED_INT_LOG_tmp[1];
    // take the mean of the i-th ray's intersection locations.
    if (static_cast<unsigned int>(nrows) + 2U >
        static_cast<unsigned int>(MED_INT_LOG.size(1))) {
      i = MED_INT_LOG.size(1);
      MED_INT_LOG.set_size(2, MED_INT_LOG.size(1) + 100);
      for (nmkpi = 0; nmkpi < 100; nmkpi++) {
        r = nmkpi + i;
        MED_INT_LOG[2 * r] = rtNaN;
        MED_INT_LOG[2 * r + 1] = rtNaN;
      }
      // Expand preallocation if needed
    }
  }
  coder::median(MED_INT_LOG, position);
  // disp(['loc_error_RMR = ',num2str(norm(pos_RMR))])
  //  M-ESTIMATOR
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
// Return Type  : void
//
void times(coder::array<double, 1U> &in1, const coder::array<double, 1U> &in2,
           const coder::array<double, 1U> &in3)
{
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  in1.set_size(loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = in2[i * stride_0_0] * in3[i * stride_1_0];
  }
}

//
// File trailer for localizefrombearings.cpp
//
// [EOF]
//
