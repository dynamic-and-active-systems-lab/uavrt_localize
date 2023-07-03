//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: unique.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:32:45
//

// Include Files
#include "unique.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<unsigned int, 1U> &a
//                ::coder::array<unsigned int, 1U> &b
// Return Type  : void
//
namespace coder {
void unique_vector(const ::coder::array<unsigned int, 1U> &a,
                   ::coder::array<unsigned int, 1U> &b)
{
  array<int, 1U> idx;
  array<int, 1U> iwork;
  int b_i;
  int i;
  int k;
  int n;
  int na;
  int qEnd;
  na = a.size(0);
  n = a.size(0) + 1;
  idx.set_size(a.size(0));
  i = a.size(0);
  for (b_i = 0; b_i < i; b_i++) {
    idx[b_i] = 0;
  }
  if (a.size(0) != 0) {
    iwork.set_size(a.size(0));
    b_i = a.size(0) - 1;
    for (k = 1; k <= b_i; k += 2) {
      if (a[k - 1] <= a[k]) {
        idx[k - 1] = k;
        idx[k] = k + 1;
      } else {
        idx[k - 1] = k + 1;
        idx[k] = k;
      }
    }
    if ((a.size(0) & 1) != 0) {
      idx[a.size(0) - 1] = a.size(0);
    }
    i = 2;
    while (i < n - 1) {
      int i2;
      int j;
      i2 = i << 1;
      j = 1;
      for (int pEnd{i + 1}; pEnd < n; pEnd = qEnd + i) {
        int kEnd;
        int p;
        int q;
        p = j;
        q = pEnd;
        qEnd = j + i2;
        if (qEnd > n) {
          qEnd = n;
        }
        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          int i1;
          b_i = idx[p - 1];
          i1 = idx[q - 1];
          if (a[b_i - 1] <= a[i1 - 1]) {
            iwork[k] = b_i;
            p++;
            if (p == pEnd) {
              while (q < qEnd) {
                k++;
                iwork[k] = idx[q - 1];
                q++;
              }
            }
          } else {
            iwork[k] = i1;
            q++;
            if (q == qEnd) {
              while (p < pEnd) {
                k++;
                iwork[k] = idx[p - 1];
                p++;
              }
            }
          }
          k++;
        }
        for (k = 0; k < kEnd; k++) {
          idx[(j + k) - 1] = iwork[k];
        }
        j = qEnd;
      }
      i = i2;
    }
  }
  b.set_size(a.size(0));
  for (k = 0; k < na; k++) {
    b[k] = a[idx[k] - 1];
  }
  i = 0;
  k = 1;
  while (k <= na) {
    unsigned int x;
    x = b[k - 1];
    do {
      k++;
    } while (!((k > na) || (b[k - 1] != x)));
    i++;
    b[i - 1] = x;
  }
  if (i < 1) {
    i = 0;
  }
  b.set_size(i);
}

} // namespace coder

//
// File trailer for unique.cpp
//
// [EOF]
//
