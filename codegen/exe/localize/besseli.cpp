//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: besseli.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:32:45
//

// Include Files
#include "besseli.h"
#include "cmlri.h"
#include "cospiAndSinpi.h"
#include "gammaln.h"
#include "localize_data.h"
#include "localize_rtwutil.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const double z[2]
//                creal_T w[2]
// Return Type  : void
//
namespace coder {
void besseli(const double z[2], creal_T w[2])
{
  creal_T ak1;
  creal_T tmp;
  creal_T zn;
  double AZ;
  double aa;
  double acz;
  double ak;
  double b_atol;
  double coef_im;
  double cs1_im;
  double cs1_re;
  double cs2_im;
  double csgn_im;
  double cz_im;
  double cz_re;
  double hz_im;
  double hz_re;
  double im;
  double re;
  double rs;
  double sgn;
  int ierr;
  int inw;
  int nw;
  boolean_T errflag;
  boolean_T exitg1;
  boolean_T guard1{false};
  if (std::isnan(z[0])) {
    tmp.re = rtNaN;
    tmp.im = 0.0;
  } else {
    ierr = 0;
    AZ = rt_hypotd_snf(z[0], 0.0);
    if (AZ > 1.0737418235E+9) {
      ierr = 4;
    } else if (AZ > 32767.999992370605) {
      ierr = 3;
    }
    zn.re = z[0];
    zn.im = 0.0;
    csgn_im = 0.0;
    if (z[0] < 0.0) {
      zn.re = -z[0];
      zn.im = -0.0;
      internal::scalar::cospiAndSinpi(0.0, csgn_im);
    }
    tmp.re = 0.0;
    tmp.im = 0.0;
    cs2_im = rt_hypotd_snf(zn.re, zn.im);
    guard1 = false;
    if (cs2_im <= 2.0) {
      nw = 0;
      if (cs2_im == 0.0) {
        tmp.re = 1.0;
        tmp.im = 0.0;
      } else if (cs2_im < 2.2250738585072014E-305) {
        tmp.re = 1.0;
        tmp.im = 0.0;
      } else {
        hz_re = 0.5 * zn.re;
        hz_im = 0.5 * zn.im;
        if (cs2_im > 4.7170688552396617E-153) {
          cz_re = hz_re * hz_re - hz_im * hz_im;
          AZ = hz_re * hz_im;
          cz_im = AZ + AZ;
          acz = rt_hypotd_snf(cz_re, cz_im);
        } else {
          cz_re = 0.0;
          cz_im = 0.0;
          acz = 0.0;
        }
        if (hz_re < 0.0) {
          hz_re = std::log(std::abs(hz_re));
        } else {
          hz_re = std::log(hz_re);
        }
        AZ = 1.0;
        gammaln(AZ);
        AZ = hz_re * 0.0 - AZ;
        if (AZ > -700.92179369444591) {
          sgn = std::exp(AZ);
          coef_im = sgn * 0.0;
          b_atol = 2.2204460492503131E-16 * acz;
          hz_re = 1.0;
          hz_im = 0.0;
          if (!(acz < 2.2204460492503131E-16)) {
            ak1.re = 1.0;
            ak1.im = 0.0;
            ak = 3.0;
            AZ = 1.0;
            aa = 2.0;
            do {
              rs = 1.0 / AZ;
              re = ak1.re * cz_re - ak1.im * cz_im;
              im = ak1.re * cz_im + ak1.im * cz_re;
              ak1.re = rs * re;
              ak1.im = rs * im;
              hz_re += ak1.re;
              hz_im += ak1.im;
              AZ += ak;
              ak += 2.0;
              aa = aa * acz * rs;
            } while (!!(aa > b_atol));
          }
          AZ = hz_re * sgn - hz_im * coef_im;
          hz_im = hz_re * coef_im + hz_im * sgn;
          tmp.re = AZ - hz_im * 0.0;
          tmp.im = AZ * 0.0 + hz_im;
        } else {
          nw = 1;
          if (acz > 0.0) {
            nw = -1;
          }
        }
      }
      if (nw < 0) {
        inw = 1;
      } else {
        inw = nw;
      }
      if ((1 - inw != 0) && (nw < 0)) {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      if (cs2_im < 21.784271729432426) {
        nw = cmlri(zn, tmp);
        if (nw < 0) {
          if (nw == -2) {
            inw = -2;
          } else {
            inw = -1;
          }
        } else {
          inw = 0;
        }
      } else {
        nw = 0;
        ak1.re = 0.15915494309189535 / zn.re;
        ak1.im = 0.0;
        internal::scalar::b_sqrt(&ak1);
        if (std::abs(zn.re) > 700.92179369444591) {
          nw = -1;
          tmp.re = rtNaN;
          tmp.im = 0.0;
        } else {
          if (zn.re == 0.0) {
            hz_re = 1.0;
            hz_im = std::sin(zn.im);
          } else {
            hz_re = std::exp(zn.re);
            hz_im = 0.0;
          }
          re = ak1.re * hz_re - ak1.im * hz_im;
          im = ak1.re * hz_im + ak1.im * hz_re;
          cz_re = 8.0 * zn.re;
          rs = 8.0 * cs2_im;
          coef_im = -1.0;
          b_atol = 2.2204460492503131E-16 / rs;
          sgn = 1.0;
          cs1_re = 1.0;
          cs1_im = 0.0;
          acz = 1.0;
          cs2_im = 0.0;
          hz_re = 1.0;
          hz_im = 0.0;
          ak = 0.0;
          aa = 1.0;
          cz_im = rs;
          AZ = cz_re;
          errflag = true;
          inw = 0;
          exitg1 = false;
          while ((!exitg1) && (inw < 45)) {
            hz_re *= coef_im;
            hz_im *= coef_im;
            if (hz_im == 0.0) {
              hz_re /= AZ;
              hz_im = 0.0;
            } else if (hz_re == 0.0) {
              hz_re = 0.0;
              hz_im = rtNaN;
            } else {
              hz_re /= AZ;
              hz_im = rtNaN;
            }
            acz += hz_re;
            cs2_im += hz_im;
            sgn = -sgn;
            cs1_re += hz_re * sgn;
            cs1_im += hz_im * sgn;
            AZ += cz_re;
            aa = aa * std::abs(coef_im) / cz_im;
            cz_im += rs;
            ak += 8.0;
            coef_im -= ak;
            if (aa <= b_atol) {
              errflag = false;
              exitg1 = true;
            } else {
              inw++;
            }
          }
          if (errflag) {
            nw = -2;
          } else {
            if (zn.re + zn.re < 700.92179369444591) {
              hz_re = -2.0 * zn.re;
              if (hz_re == 0.0) {
                hz_re = 1.0;
                hz_im = std::sin(-2.0 * zn.im);
              } else {
                hz_re = std::exp(hz_re);
                hz_im = 0.0;
              }
              rs = hz_re * acz - hz_im * cs2_im;
              AZ = hz_re * cs2_im + hz_im * acz;
              rs *= 0.0;
              AZ *= 0.0;
              cs1_re += rs - AZ;
              cs1_im += rs + AZ;
            }
            tmp.re = cs1_re * re - cs1_im * im;
            tmp.im = cs1_re * im + cs1_im * re;
          }
        }
        if (nw < 0) {
          if (nw == -2) {
            inw = -2;
          } else {
            inw = -1;
          }
        } else {
          inw = 0;
        }
      }
    }
    if (inw < 0) {
      if (inw == -2) {
        ierr = 5;
      } else {
        ierr = 2;
      }
    } else if ((!(z[0] >= 0.0)) && (inw != 1)) {
      if (std::fmax(std::abs(tmp.re), std::abs(tmp.im)) <=
          1.0020841800044864E-289) {
        tmp.re *= 4.503599627370496E+15;
        tmp.im *= 4.503599627370496E+15;
        AZ = 2.2204460492503131E-16;
      } else {
        AZ = 1.0;
      }
      re = tmp.re - tmp.im * csgn_im;
      im = tmp.re * csgn_im + tmp.im;
      tmp.re = AZ * re;
      tmp.im = AZ * im;
    }
    if (ierr == 5) {
      tmp.re = rtNaN;
      tmp.im = 0.0;
    } else if (ierr == 2) {
      tmp.re = rtInf;
      tmp.im = 0.0;
    }
    if (z[0] > 0.0) {
      AZ = tmp.re;
      tmp.re = AZ;
      tmp.im = 0.0;
    }
  }
  w[0] = tmp;
  if (std::isnan(z[1])) {
    tmp.re = rtNaN;
    tmp.im = 0.0;
  } else {
    ierr = 0;
    AZ = rt_hypotd_snf(z[1], 0.0);
    if (AZ > 1.0737418235E+9) {
      ierr = 4;
    } else if (AZ > 32767.999992370605) {
      ierr = 3;
    }
    zn.re = z[1];
    zn.im = 0.0;
    csgn_im = 0.0;
    if (z[1] < 0.0) {
      zn.re = -z[1];
      zn.im = -0.0;
      internal::scalar::cospiAndSinpi(0.0, csgn_im);
    }
    tmp.re = 0.0;
    tmp.im = 0.0;
    cs2_im = rt_hypotd_snf(zn.re, zn.im);
    guard1 = false;
    if (cs2_im <= 2.0) {
      nw = 0;
      if (cs2_im == 0.0) {
        tmp.re = 1.0;
        tmp.im = 0.0;
      } else if (cs2_im < 2.2250738585072014E-305) {
        tmp.re = 1.0;
        tmp.im = 0.0;
      } else {
        hz_re = 0.5 * zn.re;
        hz_im = 0.5 * zn.im;
        if (cs2_im > 4.7170688552396617E-153) {
          cz_re = hz_re * hz_re - hz_im * hz_im;
          AZ = hz_re * hz_im;
          cz_im = AZ + AZ;
          acz = rt_hypotd_snf(cz_re, cz_im);
        } else {
          cz_re = 0.0;
          cz_im = 0.0;
          acz = 0.0;
        }
        if (hz_re < 0.0) {
          hz_re = std::log(std::abs(hz_re));
        } else {
          hz_re = std::log(hz_re);
        }
        AZ = 1.0;
        gammaln(AZ);
        AZ = hz_re * 0.0 - AZ;
        if (AZ > -700.92179369444591) {
          sgn = std::exp(AZ);
          coef_im = sgn * 0.0;
          b_atol = 2.2204460492503131E-16 * acz;
          hz_re = 1.0;
          hz_im = 0.0;
          if (!(acz < 2.2204460492503131E-16)) {
            ak1.re = 1.0;
            ak1.im = 0.0;
            ak = 3.0;
            AZ = 1.0;
            aa = 2.0;
            do {
              rs = 1.0 / AZ;
              re = ak1.re * cz_re - ak1.im * cz_im;
              im = ak1.re * cz_im + ak1.im * cz_re;
              ak1.re = rs * re;
              ak1.im = rs * im;
              hz_re += ak1.re;
              hz_im += ak1.im;
              AZ += ak;
              ak += 2.0;
              aa = aa * acz * rs;
            } while (!!(aa > b_atol));
          }
          AZ = hz_re * sgn - hz_im * coef_im;
          hz_im = hz_re * coef_im + hz_im * sgn;
          tmp.re = AZ - hz_im * 0.0;
          tmp.im = AZ * 0.0 + hz_im;
        } else {
          nw = 1;
          if (acz > 0.0) {
            nw = -1;
          }
        }
      }
      if (nw < 0) {
        inw = 1;
      } else {
        inw = nw;
      }
      if ((1 - inw != 0) && (nw < 0)) {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      if (cs2_im < 21.784271729432426) {
        nw = cmlri(zn, tmp);
        if (nw < 0) {
          if (nw == -2) {
            inw = -2;
          } else {
            inw = -1;
          }
        } else {
          inw = 0;
        }
      } else {
        nw = 0;
        ak1.re = 0.15915494309189535 / zn.re;
        ak1.im = 0.0;
        internal::scalar::b_sqrt(&ak1);
        if (std::abs(zn.re) > 700.92179369444591) {
          nw = -1;
          tmp.re = rtNaN;
          tmp.im = 0.0;
        } else {
          if (zn.re == 0.0) {
            hz_re = 1.0;
            hz_im = std::sin(zn.im);
          } else {
            hz_re = std::exp(zn.re);
            hz_im = 0.0;
          }
          re = ak1.re * hz_re - ak1.im * hz_im;
          im = ak1.re * hz_im + ak1.im * hz_re;
          cz_re = 8.0 * zn.re;
          rs = 8.0 * cs2_im;
          coef_im = -1.0;
          b_atol = 2.2204460492503131E-16 / rs;
          sgn = 1.0;
          cs1_re = 1.0;
          cs1_im = 0.0;
          acz = 1.0;
          cs2_im = 0.0;
          hz_re = 1.0;
          hz_im = 0.0;
          ak = 0.0;
          aa = 1.0;
          cz_im = rs;
          AZ = cz_re;
          errflag = true;
          inw = 0;
          exitg1 = false;
          while ((!exitg1) && (inw < 45)) {
            hz_re *= coef_im;
            hz_im *= coef_im;
            if (hz_im == 0.0) {
              hz_re /= AZ;
              hz_im = 0.0;
            } else if (hz_re == 0.0) {
              hz_re = 0.0;
              hz_im = rtNaN;
            } else {
              hz_re /= AZ;
              hz_im = rtNaN;
            }
            acz += hz_re;
            cs2_im += hz_im;
            sgn = -sgn;
            cs1_re += hz_re * sgn;
            cs1_im += hz_im * sgn;
            AZ += cz_re;
            aa = aa * std::abs(coef_im) / cz_im;
            cz_im += rs;
            ak += 8.0;
            coef_im -= ak;
            if (aa <= b_atol) {
              errflag = false;
              exitg1 = true;
            } else {
              inw++;
            }
          }
          if (errflag) {
            nw = -2;
          } else {
            if (zn.re + zn.re < 700.92179369444591) {
              hz_re = -2.0 * zn.re;
              if (hz_re == 0.0) {
                hz_re = 1.0;
                hz_im = std::sin(-2.0 * zn.im);
              } else {
                hz_re = std::exp(hz_re);
                hz_im = 0.0;
              }
              rs = hz_re * acz - hz_im * cs2_im;
              AZ = hz_re * cs2_im + hz_im * acz;
              rs *= 0.0;
              AZ *= 0.0;
              cs1_re += rs - AZ;
              cs1_im += rs + AZ;
            }
            tmp.re = cs1_re * re - cs1_im * im;
            tmp.im = cs1_re * im + cs1_im * re;
          }
        }
        if (nw < 0) {
          if (nw == -2) {
            inw = -2;
          } else {
            inw = -1;
          }
        } else {
          inw = 0;
        }
      }
    }
    if (inw < 0) {
      if (inw == -2) {
        ierr = 5;
      } else {
        ierr = 2;
      }
    } else if ((!(z[1] >= 0.0)) && (inw != 1)) {
      if (std::fmax(std::abs(tmp.re), std::abs(tmp.im)) <=
          1.0020841800044864E-289) {
        tmp.re *= 4.503599627370496E+15;
        tmp.im *= 4.503599627370496E+15;
        AZ = 2.2204460492503131E-16;
      } else {
        AZ = 1.0;
      }
      re = tmp.re - tmp.im * csgn_im;
      im = tmp.re * csgn_im + tmp.im;
      tmp.re = AZ * re;
      tmp.im = AZ * im;
    }
    if (ierr == 5) {
      tmp.re = rtNaN;
      tmp.im = 0.0;
    } else if (ierr == 2) {
      tmp.re = rtInf;
      tmp.im = 0.0;
    }
    if (z[1] > 0.0) {
      AZ = tmp.re;
      tmp.re = AZ;
      tmp.im = 0.0;
    }
  }
  w[1] = tmp;
}

} // namespace coder

//
// File trailer for besseli.cpp
//
// [EOF]
//
