//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fgetl.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:18:22
//

// Include Files
#include "fgetl.h"
#include "fileManager.h"
#include "localize_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdio>

// Function Definitions
//
// Arguments    : double fileID
//                ::coder::array<char, 2U> &out
// Return Type  : void
//
namespace coder {
void fgetl(double fileID, ::coder::array<char, 2U> &out)
{
  std::FILE *b_filestar;
  std::FILE *filestar;
  int b_i;
  int i;
  boolean_T newLineAfterCarriageReturn;
  filestar = internal::getfilestar(fileID, newLineAfterCarriageReturn);
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = nullptr;
  }
  out.set_size(1, 0);
  if (!(filestar == nullptr)) {
    char *cOut;
    int st;
    int wherefrom;
    int exitg1;
    char ReadBuff[1024];
    boolean_T readNewline;
    do {
      int reachedEndOfFile;
      exitg1 = 0;
      cOut = std::fgets(&ReadBuff[0], 1024, filestar);
      readNewline = false;
      b_filestar = internal::getfilestar(fileID, newLineAfterCarriageReturn);
      if (b_filestar == nullptr) {
        reachedEndOfFile = 0;
      } else {
        st = std::feof(b_filestar);
        reachedEndOfFile = ((int)st != 0);
      }
      if (cOut == nullptr) {
        exitg1 = 1;
      } else {
        int carriageReturnAt;
        int idx;
        boolean_T fileEndAfterCarriageReturn;
        idx = 1;
        carriageReturnAt = 0;
        if (reachedEndOfFile != 0) {
          boolean_T exitg2;
          i = 0;
          exitg2 = false;
          while ((!exitg2) && (i < 1024)) {
            if (ReadBuff[i] == '\x00') {
              idx = i + 1;
              exitg2 = true;
            } else {
              if ((carriageReturnAt == 0) && (ReadBuff[i] == '\r')) {
                carriageReturnAt = i + 1;
              }
              i++;
            }
          }
          if (ReadBuff[idx - 1] == '\x00') {
            idx--;
          }
        } else {
          boolean_T exitg2;
          i = 0;
          exitg2 = false;
          while ((!exitg2) && (i < 1025)) {
            if (i + 1 > 1024) {
              idx = 1023;
              exitg2 = true;
            } else if (ReadBuff[i] == '\n') {
              idx = i + 1;
              exitg2 = true;
            } else {
              if ((carriageReturnAt == 0) && (ReadBuff[i] == '\r')) {
                carriageReturnAt = i + 1;
              }
              i++;
            }
          }
          readNewline = (ReadBuff[idx - 1] == '\n');
        }
        if ((carriageReturnAt > 0) && (carriageReturnAt < 1024)) {
          newLineAfterCarriageReturn = (ReadBuff[carriageReturnAt] == '\n');
          if ((reachedEndOfFile != 0) &&
              (ReadBuff[carriageReturnAt] == '\x00')) {
            fileEndAfterCarriageReturn = true;
          } else {
            fileEndAfterCarriageReturn = false;
          }
        } else {
          newLineAfterCarriageReturn = false;
          fileEndAfterCarriageReturn = false;
        }
        if ((carriageReturnAt == 0) || newLineAfterCarriageReturn ||
            fileEndAfterCarriageReturn) {
          if (idx < 1) {
            i = 0;
          } else {
            i = idx;
          }
          b_i = out.size(1);
          out.set_size(out.size(0), out.size(1) + i);
          for (int i1{0}; i1 < i; i1++) {
            out[b_i + i1] = ReadBuff[i1];
          }
        } else {
          b_i = out.size(1);
          out.set_size(out.size(0), out.size(1) + carriageReturnAt);
          for (int i1{0}; i1 < carriageReturnAt; i1++) {
            out[b_i + i1] = ReadBuff[i1];
          }
          wherefrom = SEEK_CUR;
          b_filestar =
              internal::getfilestar(fileID, newLineAfterCarriageReturn);
          if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
            b_filestar = nullptr;
          }
          if (!(b_filestar == nullptr)) {
            std::fseek(b_filestar, (long int)(carriageReturnAt - idx),
                       wherefrom);
          }
        }
        if (readNewline || (reachedEndOfFile != 0) || (carriageReturnAt > 0)) {
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
    b_filestar = internal::getfilestar(fileID, newLineAfterCarriageReturn);
    if (b_filestar == nullptr) {
      b_i = 0;
    } else {
      st = std::feof(b_filestar);
      b_i = ((int)st != 0);
    }
    if (b_i == 0) {
      filestar = internal::getfilestar(fileID, newLineAfterCarriageReturn);
      if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
        filestar = nullptr;
      }
      if (!(filestar == nullptr)) {
        unsigned char buf;
        std::fread(&buf, sizeof(unsigned char), (size_t)1, filestar);
      }
      b_filestar = internal::getfilestar(fileID, newLineAfterCarriageReturn);
      if (b_filestar == nullptr) {
        b_i = 0;
      } else {
        st = std::feof(b_filestar);
        b_i = ((int)st != 0);
      }
      if (b_i == 0) {
        wherefrom = SEEK_CUR;
        filestar = internal::getfilestar(fileID, newLineAfterCarriageReturn);
        if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
          filestar = nullptr;
        }
        if (!(filestar == nullptr)) {
          std::fseek(filestar, (long int)-1.0, wherefrom);
        }
      }
    }
  }
  if (out.size(1) != 0) {
    char c;
    c = out[out.size(1) - 1];
    if (c == '\n') {
      if ((out.size(1) > 1) && (out[out.size(1) - 2] == '\r')) {
        if (out.size(1) - 2 < 1) {
          i = 0;
        } else {
          i = out.size(1) - 2;
        }
        for (b_i = 0; b_i < i; b_i++) {
          out[b_i] = out[b_i];
        }
        out.set_size(1, i);
      } else {
        if (out.size(1) - 1 < 1) {
          i = 0;
        } else {
          i = out.size(1) - 1;
        }
        for (b_i = 0; b_i < i; b_i++) {
          out[b_i] = out[b_i];
        }
        out.set_size(1, i);
      }
    } else if (c == '\r') {
      if (out.size(1) - 1 < 1) {
        i = 0;
      } else {
        i = out.size(1) - 1;
      }
      for (b_i = 0; b_i < i; b_i++) {
        out[b_i] = out[b_i];
      }
      out.set_size(1, i);
    }
  }
}

} // namespace coder

//
// File trailer for fgetl.cpp
//
// [EOF]
//
