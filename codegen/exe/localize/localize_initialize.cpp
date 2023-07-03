//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: localize_initialize.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:32:45
//

// Include Files
#include "localize_initialize.h"
#include "fileManager.h"
#include "localize_data.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void localize_initialize()
{
  filedata_init();
  isInitialized_localize = true;
}

//
// File trailer for localize_initialize.cpp
//
// [EOF]
//
