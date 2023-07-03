//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_localize_api.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:18:22
//

#ifndef _CODER_LOCALIZE_API_H
#define _CODER_LOCALIZE_API_H

// Include Files
#include "coder_array_mex.h"
#include "emlrt.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
real_T localize(coder::array<char_T, 2U> *bearingFilePath);

void localize_api(const mxArray *prhs, const mxArray **plhs);

void localize_atexit();

void localize_initialize();

void localize_terminate();

void localize_xil_shutdown();

void localize_xil_terminate();

#endif
//
// File trailer for _coder_localize_api.h
//
// [EOF]
//
