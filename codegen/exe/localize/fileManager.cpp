//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fileManager.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:32:45
//

// Include Files
#include "fileManager.h"
#include "localize_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstdio>

// Variable Definitions
static std::FILE *eml_openfiles[20];

static boolean_T eml_autoflush[20];

// Function Declarations
namespace coder {
namespace internal {
static signed char filedata();

}
} // namespace coder

// Function Definitions
//
// Arguments    : void
// Return Type  : signed char
//
namespace coder {
namespace internal {
static signed char filedata()
{
  int k;
  signed char f;
  boolean_T exitg1;
  f = 0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 20)) {
    if (eml_openfiles[k] == nullptr) {
      f = static_cast<signed char>(k + 1);
      exitg1 = true;
    } else {
      k++;
    }
  }
  return f;
}

//
// Arguments    : double fid
// Return Type  : int
//
int cfclose(double fid)
{
  std::FILE *f;
  int st;
  signed char b_fileid;
  signed char fileid;
  st = -1;
  fileid = static_cast<signed char>(fid);
  if ((static_cast<signed char>(fid) > 22) ||
      (static_cast<signed char>(fid) < 0) ||
      (fid != static_cast<signed char>(fid))) {
    fileid = -1;
  }
  b_fileid = fileid;
  if (fileid < 0) {
    b_fileid = -1;
  }
  if (b_fileid >= 3) {
    f = eml_openfiles[b_fileid - 3];
  } else if (b_fileid == 0) {
    f = stdin;
  } else if (b_fileid == 1) {
    f = stdout;
  } else if (b_fileid == 2) {
    f = stderr;
  } else {
    f = nullptr;
  }
  if ((f != nullptr) && (fileid >= 3)) {
    int cst;
    cst = std::fclose(f);
    if (cst == 0) {
      st = 0;
      eml_openfiles[fileid - 3] = nullptr;
      eml_autoflush[fileid - 3] = true;
    }
  }
  return st;
}

//
// Arguments    : const ::coder::array<char, 2U> &cfilename
//                const char *cpermission
// Return Type  : signed char
//
signed char cfopen(const ::coder::array<char, 2U> &cfilename,
                   const char *cpermission)
{
  std::FILE *filestar;
  array<char, 2U> ccfilename;
  signed char fileid;
  signed char j;
  fileid = -1;
  j = filedata();
  if (j >= 1) {
    int i;
    int loop_ub;
    ccfilename.set_size(1, cfilename.size(1) + 1);
    loop_ub = cfilename.size(1);
    for (i = 0; i < loop_ub; i++) {
      ccfilename[i] = cfilename[i];
    }
    ccfilename[cfilename.size(1)] = '\x00';
    filestar = std::fopen(&ccfilename[0], cpermission);
    if (filestar != nullptr) {
      eml_openfiles[j - 1] = filestar;
      eml_autoflush[j - 1] = true;
      i = j + 2;
      if (j + 2 > 127) {
        i = 127;
      }
      fileid = static_cast<signed char>(i);
    }
  }
  return fileid;
}

//
// Arguments    : double fid
//                boolean_T &autoflush
// Return Type  : std::FILE *
//
std::FILE *getfilestar(double fid, boolean_T &autoflush)
{
  std::FILE *filestar;
  signed char fileid;
  fileid = static_cast<signed char>(fid);
  if ((static_cast<signed char>(fid) > 22) ||
      (static_cast<signed char>(fid) < 0) ||
      (fid != static_cast<signed char>(fid))) {
    fileid = -1;
  }
  if (fileid >= 3) {
    autoflush = eml_autoflush[fileid - 3];
    filestar = eml_openfiles[fileid - 3];
  } else if (fileid == 0) {
    filestar = stdin;
    autoflush = true;
  } else if (fileid == 1) {
    filestar = stdout;
    autoflush = true;
  } else if (fileid == 2) {
    filestar = stderr;
    autoflush = true;
  } else {
    filestar = nullptr;
    autoflush = true;
  }
  return filestar;
}

//
// Arguments    : void
// Return Type  : void
//
} // namespace internal
} // namespace coder
void filedata_init()
{
  for (int i{0}; i < 20; i++) {
    eml_autoflush[i] = false;
  }
  for (int i{0}; i < 20; i++) {
    eml_openfiles[i] = nullptr;
  }
}

//
// File trailer for fileManager.cpp
//
// [EOF]
//
