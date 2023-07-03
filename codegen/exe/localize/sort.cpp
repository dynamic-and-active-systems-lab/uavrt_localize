//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sort.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:32:45
//

// Include Files
#include "sort.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : ::coder::array<double, 1U> &x
//                ::coder::array<int, 1U> &idx
// Return Type  : void
//
namespace coder {
namespace internal {
void sort(::coder::array<double, 1U> &x, ::coder::array<int, 1U> &idx)
{
  array<double, 1U> xwork;
  array<int, 1U> iwork;
  int i;
  int ib;
  unsigned int unnamed_idx_0;
  unnamed_idx_0 = static_cast<unsigned int>(x.size(0));
  idx.set_size(static_cast<int>(unnamed_idx_0));
  ib = static_cast<int>(unnamed_idx_0);
  for (i = 0; i < ib; i++) {
    idx[i] = 0;
  }
  if (x.size(0) != 0) {
    double x4[4];
    int idx4[4];
    int bLen;
    int i2;
    int i3;
    int i4;
    int idx_tmp;
    int n;
    int quartetOffset;
    int wOffset_tmp;
    n = x.size(0);
    x4[0] = 0.0;
    idx4[0] = 0;
    x4[1] = 0.0;
    idx4[1] = 0;
    x4[2] = 0.0;
    idx4[2] = 0;
    x4[3] = 0.0;
    idx4[3] = 0;
    iwork.set_size(static_cast<int>(unnamed_idx_0));
    for (i = 0; i < ib; i++) {
      iwork[i] = 0;
    }
    ib = x.size(0);
    xwork.set_size(ib);
    for (i = 0; i < ib; i++) {
      xwork[i] = 0.0;
    }
    bLen = 0;
    ib = 0;
    for (int k{0}; k < n; k++) {
      if (std::isnan(x[k])) {
        idx_tmp = (n - bLen) - 1;
        idx[idx_tmp] = k + 1;
        xwork[idx_tmp] = x[k];
        bLen++;
      } else {
        ib++;
        idx4[ib - 1] = k + 1;
        x4[ib - 1] = x[k];
        if (ib == 4) {
          double d;
          double d1;
          signed char b_i2;
          signed char b_i3;
          signed char b_i4;
          signed char i1;
          quartetOffset = k - bLen;
          if (x4[0] <= x4[1]) {
            ib = 1;
            i2 = 2;
          } else {
            ib = 2;
            i2 = 1;
          }
          if (x4[2] <= x4[3]) {
            i3 = 3;
            i4 = 4;
          } else {
            i3 = 4;
            i4 = 3;
          }
          d = x4[i3 - 1];
          d1 = x4[ib - 1];
          if (d1 <= d) {
            d1 = x4[i2 - 1];
            if (d1 <= d) {
              i1 = static_cast<signed char>(ib);
              b_i2 = static_cast<signed char>(i2);
              b_i3 = static_cast<signed char>(i3);
              b_i4 = static_cast<signed char>(i4);
            } else if (d1 <= x4[i4 - 1]) {
              i1 = static_cast<signed char>(ib);
              b_i2 = static_cast<signed char>(i3);
              b_i3 = static_cast<signed char>(i2);
              b_i4 = static_cast<signed char>(i4);
            } else {
              i1 = static_cast<signed char>(ib);
              b_i2 = static_cast<signed char>(i3);
              b_i3 = static_cast<signed char>(i4);
              b_i4 = static_cast<signed char>(i2);
            }
          } else {
            d = x4[i4 - 1];
            if (d1 <= d) {
              if (x4[i2 - 1] <= d) {
                i1 = static_cast<signed char>(i3);
                b_i2 = static_cast<signed char>(ib);
                b_i3 = static_cast<signed char>(i2);
                b_i4 = static_cast<signed char>(i4);
              } else {
                i1 = static_cast<signed char>(i3);
                b_i2 = static_cast<signed char>(ib);
                b_i3 = static_cast<signed char>(i4);
                b_i4 = static_cast<signed char>(i2);
              }
            } else {
              i1 = static_cast<signed char>(i3);
              b_i2 = static_cast<signed char>(i4);
              b_i3 = static_cast<signed char>(ib);
              b_i4 = static_cast<signed char>(i2);
            }
          }
          idx[quartetOffset - 3] = idx4[i1 - 1];
          idx[quartetOffset - 2] = idx4[b_i2 - 1];
          idx[quartetOffset - 1] = idx4[b_i3 - 1];
          idx[quartetOffset] = idx4[b_i4 - 1];
          x[quartetOffset - 3] = x4[i1 - 1];
          x[quartetOffset - 2] = x4[b_i2 - 1];
          x[quartetOffset - 1] = x4[b_i3 - 1];
          x[quartetOffset] = x4[b_i4 - 1];
          ib = 0;
        }
      }
    }
    wOffset_tmp = x.size(0) - bLen;
    if (ib > 0) {
      signed char perm[4];
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (ib == 1) {
        perm[0] = 1;
      } else if (ib == 2) {
        if (x4[0] <= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
      } else if (x4[0] <= x4[1]) {
        if (x4[1] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }
      i = static_cast<unsigned char>(ib);
      for (int k{0}; k < i; k++) {
        idx_tmp = perm[k] - 1;
        quartetOffset = (wOffset_tmp - ib) + k;
        idx[quartetOffset] = idx4[idx_tmp];
        x[quartetOffset] = x4[idx_tmp];
      }
    }
    ib = bLen >> 1;
    for (int k{0}; k < ib; k++) {
      quartetOffset = wOffset_tmp + k;
      i2 = idx[quartetOffset];
      idx_tmp = (n - k) - 1;
      idx[quartetOffset] = idx[idx_tmp];
      idx[idx_tmp] = i2;
      x[quartetOffset] = xwork[idx_tmp];
      x[idx_tmp] = xwork[quartetOffset];
    }
    if ((bLen & 1) != 0) {
      i = wOffset_tmp + ib;
      x[i] = xwork[i];
    }
    ib = 2;
    if (wOffset_tmp > 1) {
      if (x.size(0) >= 256) {
        int nBlocks;
        nBlocks = wOffset_tmp >> 8;
        if (nBlocks > 0) {
          for (int b{0}; b < nBlocks; b++) {
            double b_xwork[256];
            int b_iwork[256];
            i4 = (b << 8) - 1;
            for (int b_b{0}; b_b < 6; b_b++) {
              bLen = 1 << (b_b + 2);
              n = bLen << 1;
              i = 256 >> (b_b + 3);
              for (int k{0}; k < i; k++) {
                i2 = (i4 + k * n) + 1;
                for (quartetOffset = 0; quartetOffset < n; quartetOffset++) {
                  ib = i2 + quartetOffset;
                  b_iwork[quartetOffset] = idx[ib];
                  b_xwork[quartetOffset] = x[ib];
                }
                i3 = 0;
                quartetOffset = bLen;
                ib = i2 - 1;
                int exitg1;
                do {
                  exitg1 = 0;
                  ib++;
                  if (b_xwork[i3] <= b_xwork[quartetOffset]) {
                    idx[ib] = b_iwork[i3];
                    x[ib] = b_xwork[i3];
                    if (i3 + 1 < bLen) {
                      i3++;
                    } else {
                      exitg1 = 1;
                    }
                  } else {
                    idx[ib] = b_iwork[quartetOffset];
                    x[ib] = b_xwork[quartetOffset];
                    if (quartetOffset + 1 < n) {
                      quartetOffset++;
                    } else {
                      ib -= i3;
                      for (quartetOffset = i3 + 1; quartetOffset <= bLen;
                           quartetOffset++) {
                        idx_tmp = ib + quartetOffset;
                        idx[idx_tmp] = b_iwork[quartetOffset - 1];
                        x[idx_tmp] = b_xwork[quartetOffset - 1];
                      }
                      exitg1 = 1;
                    }
                  }
                } while (exitg1 == 0);
              }
            }
          }
          ib = nBlocks << 8;
          quartetOffset = wOffset_tmp - ib;
          if (quartetOffset > 0) {
            merge_block(idx, x, ib, quartetOffset, 2, iwork, xwork);
          }
          ib = 8;
        }
      }
      merge_block(idx, x, 0, wOffset_tmp, ib, iwork, xwork);
    }
  }
}

//
// Arguments    : ::coder::array<unsigned int, 1U> &x
//                ::coder::array<int, 1U> &idx
// Return Type  : void
//
void sort(::coder::array<unsigned int, 1U> &x, ::coder::array<int, 1U> &idx)
{
  array<int, 1U> iwork;
  array<unsigned int, 1U> xwork;
  int i;
  int nQuartets;
  unsigned int unnamed_idx_0;
  unnamed_idx_0 = static_cast<unsigned int>(x.size(0));
  idx.set_size(static_cast<int>(unnamed_idx_0));
  nQuartets = static_cast<int>(unnamed_idx_0);
  for (i = 0; i < nQuartets; i++) {
    idx[i] = 0;
  }
  if (x.size(0) != 0) {
    int idx4[4];
    unsigned int x4[4];
    int b_i;
    int i1;
    int i2;
    int i3;
    int i4;
    x4[0] = 0U;
    idx4[0] = 0;
    x4[1] = 0U;
    idx4[1] = 0;
    x4[2] = 0U;
    idx4[2] = 0;
    x4[3] = 0U;
    idx4[3] = 0;
    iwork.set_size(static_cast<int>(unnamed_idx_0));
    for (i = 0; i < nQuartets; i++) {
      iwork[i] = 0;
    }
    nQuartets = x.size(0);
    xwork.set_size(nQuartets);
    for (i = 0; i < nQuartets; i++) {
      xwork[i] = 0U;
    }
    nQuartets = x.size(0) >> 2;
    for (int j{0}; j < nQuartets; j++) {
      unsigned int u;
      unsigned int u1;
      unsigned int u2;
      signed char b_i1;
      signed char b_i2;
      signed char b_i3;
      signed char b_i4;
      b_i = j << 2;
      idx4[0] = b_i + 1;
      idx4[1] = b_i + 2;
      idx4[2] = b_i + 3;
      idx4[3] = b_i + 4;
      unnamed_idx_0 = x[b_i];
      x4[0] = unnamed_idx_0;
      u = x[b_i + 1];
      x4[1] = u;
      u1 = x[b_i + 2];
      x4[2] = u1;
      u2 = x[b_i + 3];
      x4[3] = u2;
      if (unnamed_idx_0 <= u) {
        i1 = 1;
        i2 = 2;
      } else {
        i1 = 2;
        i2 = 1;
      }
      if (u1 <= u2) {
        i3 = 3;
        i4 = 4;
      } else {
        i3 = 4;
        i4 = 3;
      }
      unnamed_idx_0 = x4[i3 - 1];
      u = x4[i1 - 1];
      if (u <= unnamed_idx_0) {
        u = x4[i2 - 1];
        if (u <= unnamed_idx_0) {
          b_i1 = static_cast<signed char>(i1);
          b_i2 = static_cast<signed char>(i2);
          b_i3 = static_cast<signed char>(i3);
          b_i4 = static_cast<signed char>(i4);
        } else if (u <= x4[i4 - 1]) {
          b_i1 = static_cast<signed char>(i1);
          b_i2 = static_cast<signed char>(i3);
          b_i3 = static_cast<signed char>(i2);
          b_i4 = static_cast<signed char>(i4);
        } else {
          b_i1 = static_cast<signed char>(i1);
          b_i2 = static_cast<signed char>(i3);
          b_i3 = static_cast<signed char>(i4);
          b_i4 = static_cast<signed char>(i2);
        }
      } else {
        unnamed_idx_0 = x4[i4 - 1];
        if (u <= unnamed_idx_0) {
          if (x4[i2 - 1] <= unnamed_idx_0) {
            b_i1 = static_cast<signed char>(i3);
            b_i2 = static_cast<signed char>(i1);
            b_i3 = static_cast<signed char>(i2);
            b_i4 = static_cast<signed char>(i4);
          } else {
            b_i1 = static_cast<signed char>(i3);
            b_i2 = static_cast<signed char>(i1);
            b_i3 = static_cast<signed char>(i4);
            b_i4 = static_cast<signed char>(i2);
          }
        } else {
          b_i1 = static_cast<signed char>(i3);
          b_i2 = static_cast<signed char>(i4);
          b_i3 = static_cast<signed char>(i1);
          b_i4 = static_cast<signed char>(i2);
        }
      }
      idx[b_i] = idx4[b_i1 - 1];
      idx[b_i + 1] = idx4[b_i2 - 1];
      idx[b_i + 2] = idx4[b_i3 - 1];
      idx[b_i + 3] = idx4[b_i4 - 1];
      x[b_i] = x4[b_i1 - 1];
      x[b_i + 1] = x4[b_i2 - 1];
      x[b_i + 2] = x4[b_i3 - 1];
      x[b_i + 3] = x4[b_i4 - 1];
    }
    b_i = nQuartets << 2;
    i1 = x.size(0) - b_i;
    if (i1 > 0) {
      signed char perm[4];
      for (int k{0}; k < i1; k++) {
        nQuartets = b_i + k;
        idx4[k] = nQuartets + 1;
        x4[k] = x[nQuartets];
      }
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (i1 == 1) {
        perm[0] = 1;
      } else if (i1 == 2) {
        if (x4[0] <= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
      } else if (x4[0] <= x4[1]) {
        if (x4[1] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }
      for (int k{0}; k < i1; k++) {
        i2 = perm[k] - 1;
        nQuartets = b_i + k;
        idx[nQuartets] = idx4[i2];
        x[nQuartets] = x4[i2];
      }
    }
    nQuartets = 2;
    if (x.size(0) > 1) {
      if (x.size(0) >= 256) {
        i4 = x.size(0) >> 8;
        for (int b{0}; b < i4; b++) {
          int b_iwork[256];
          unsigned int b_xwork[256];
          int offset;
          offset = (b << 8) - 1;
          for (int b_b{0}; b_b < 6; b_b++) {
            int bLen;
            int bLen2;
            bLen = 1 << (b_b + 2);
            bLen2 = bLen << 1;
            i = 256 >> (b_b + 3);
            for (int k{0}; k < i; k++) {
              i1 = (offset + k * bLen2) + 1;
              for (int j{0}; j < bLen2; j++) {
                nQuartets = i1 + j;
                b_iwork[j] = idx[nQuartets];
                b_xwork[j] = x[nQuartets];
              }
              i3 = 0;
              b_i = bLen;
              nQuartets = i1 - 1;
              int exitg1;
              do {
                exitg1 = 0;
                nQuartets++;
                if (b_xwork[i3] <= b_xwork[b_i]) {
                  idx[nQuartets] = b_iwork[i3];
                  x[nQuartets] = b_xwork[i3];
                  if (i3 + 1 < bLen) {
                    i3++;
                  } else {
                    exitg1 = 1;
                  }
                } else {
                  idx[nQuartets] = b_iwork[b_i];
                  x[nQuartets] = b_xwork[b_i];
                  if (b_i + 1 < bLen2) {
                    b_i++;
                  } else {
                    nQuartets -= i3;
                    for (int j{i3 + 1}; j <= bLen; j++) {
                      i2 = nQuartets + j;
                      idx[i2] = b_iwork[j - 1];
                      x[i2] = b_xwork[j - 1];
                    }
                    exitg1 = 1;
                  }
                }
              } while (exitg1 == 0);
            }
          }
        }
        nQuartets = i4 << 8;
        b_i = x.size(0) - nQuartets;
        if (b_i > 0) {
          merge_block(idx, x, nQuartets, b_i, 2, iwork, xwork);
        }
        nQuartets = 8;
      }
      merge_block(idx, x, 0, x.size(0), nQuartets, iwork, xwork);
    }
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for sort.cpp
//
// [EOF]
//
