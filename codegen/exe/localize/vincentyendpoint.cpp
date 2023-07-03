//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: vincentyendpoint.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:32:45
//

// Include Files
#include "vincentyendpoint.h"
#include "localize_rtwutil.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// VICENTYENDPOINT calculates the latitude and longitude from one position
//  to another based on the second positions range and bearing using the
//    the Vicenty formulea method.
//    Inputs are in degrees
//
// INPUTS:
//    lat1 - 1 x 1 latitude of position 1 in degrees
//    lon1 - 1 x 1 longitude of position 1 in degrees
//    bearing - n x 1 compass bearing in degrees from North to position 2
//    range - n x 1 range in meters to position 2
//
// OUPUTS:
//    lat2 - n x 1 latitudes of position 2 in degrees
//    lon2 - n x 1 longitudes of position 2 in degrees
//
// --------------------------------------------------------------------------
//  Author: Michael Shafer
//  Date: 2023-06-21
// --------------------------------------------------------------------------
// --------------------------------------------------------------------------
//
// Arguments    : double lat1
//                double lon1
//                double bearings
//                double ranges
//                double *lons2
// Return Type  : double
//
double vincentyendpoint(double lat1, double lon1, double bearings,
                        double ranges, double *lons2)
{
  double B;
  double C;
  double U1;
  double a_tmp;
  double alpha1;
  double b_a_tmp;
  double c_tmp;
  double sigma;
  double sigma1;
  double sigma1_tmp_tmp;
  double sigmaNew;
  double sinAlpha;
  double sinAlpha_tmp;
  double sinAlpha_tmp_tmp;
  double twoSigmaM;
  // Using WGS-84
  //  lat1 = 35 + 10/60 + 24.75/3600;
  //  lon1 = -111 + 39/60 + 29.11/3600;
  //
  //  lat2 = 35 + 10/60 + 24.82/3600;
  //  lon2 = -111 + 39/60 + 24.80/3600;
  // s is the ellipsoidal distance between the two points;
  // Length of semi-major axis of the ellipsoid (radius at equator);
  // Flattening of the ellipsoid;
  // Length of semi-minor axis of the ellipsoid (radius at the poles);
  // (1-f)a
  // Latitude of the points;
  // Longitude of the points;
  // Reduced latitude (latitude on the auxiliary sphere)
  U1 = std::atan(0.99664718933525254 *
                 std::tan(lat1 * 3.1415926535897931 / 180.0));
  // Using same variables as documentation
  alpha1 = bearings * 3.1415926535897931 / 180.0;
  // Angular Separation between point 1 and the equator
  sigma1_tmp_tmp = std::cos(alpha1);
  sigma1 = rt_atan2d_snf(std::tan(U1), sigma1_tmp_tmp);
  sinAlpha_tmp_tmp = std::cos(U1);
  sinAlpha_tmp = std::sin(alpha1);
  sinAlpha = sinAlpha_tmp_tmp * sinAlpha_tmp;
  c_tmp = sinAlpha * sinAlpha;
  alpha1 = (1.0 - c_tmp) * 0.006739496742333464;
  B = alpha1 / 1024.0 *
      (alpha1 * (alpha1 * (74.0 - 47.0 * alpha1) - 128.0) + 256.0);
  C = ranges /
      (6.356752314245E+6 *
       (alpha1 / 16384.0 *
            (alpha1 * (alpha1 * (320.0 - 175.0 * alpha1) - 768.0) + 4096.0) +
        1.0));
  sigmaNew = C;
  alpha1 = 1.0;
  //  figure
  twoSigmaM = rtNaN;
  sigma = rtNaN;
  while (alpha1 > 1.0E-12) {
    sigma = sigmaNew;
    twoSigmaM = 2.0 * sigma1 + sigmaNew;
    alpha1 = std::cos(twoSigmaM);
    a_tmp = std::sin(sigmaNew);
    b_a_tmp = alpha1 * alpha1;
    sigmaNew = C + B * a_tmp *
                       (alpha1 +
                        0.25 * B *
                            (std::cos(sigmaNew) * (2.0 * b_a_tmp - 1.0) -
                             B / 6.0 * alpha1 * (4.0 * (a_tmp * a_tmp) - 3.0) *
                                 (4.0 * b_a_tmp - 3.0)));
    alpha1 = (sigmaNew - sigma) / sigma;
    //  plot(i, residual,'.'); hold on;
    //  drawnow
  }
  double arg1_tmp_tmp;
  sigma1 = std::sin(sigma);
  arg1_tmp_tmp = std::cos(sigma);
  sigmaNew = std::sin(U1);
  a_tmp = sinAlpha_tmp_tmp * arg1_tmp_tmp;
  b_a_tmp = sigmaNew * sigma1;
  B = b_a_tmp - a_tmp * sigma1_tmp_tmp;
  C = 0.00020955066654671753 * (1.0 - c_tmp) *
      (0.0033528106647474805 * (4.0 - 3.0 * (1.0 - c_tmp)) + 4.0);
  alpha1 = std::cos(2.0 * (twoSigmaM / 2.0));
  // alpha2 = atan2(sinAlpha1,...
  //                -sin(U1)*sin(sigma)+cos(U1)*cos(sigma)*cos(alpha1));
  *lons2 =
      ((rt_atan2d_snf(sigma1 * sinAlpha_tmp, a_tmp - b_a_tmp * sigma1_tmp_tmp) -
        (1.0 - C) * 0.0033528106647474805 * sinAlpha *
            (sigma + C * sigma1 *
                         (alpha1 + C * arg1_tmp_tmp *
                                       (2.0 * (alpha1 * alpha1) - 1.0)))) +
       lon1 * 3.1415926535897931 / 180.0) *
      180.0 / 3.1415926535897931;
  return rt_atan2d_snf(sigmaNew * arg1_tmp_tmp +
                           sinAlpha_tmp_tmp * sigma1 * sigma1_tmp_tmp,
                       0.99664718933525254 * std::sqrt(c_tmp + B * B)) *
         180.0 / 3.1415926535897931;
}

//
// File trailer for vincentyendpoint.cpp
//
// [EOF]
//
