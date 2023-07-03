//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: vincentydistance.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:32:45
//

// Include Files
#include "vincentydistance.h"
#include "localize_rtwutil.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// VICENTYDISTANCE calculates the distance in meters between two points using
// the Vicenty formulea method.
//    Inputs are in degrees
//
// INPUTS:
//    lat1 - 1 x 1 latitude of position 1 in degrees
//    lon1 - 1 x 1 longitude of position 1 in degrees
//    lat2 - 1 x 1 latitude of position 2 in degrees
//    lon2 - 1 x 1 longitude of position 2 in degrees
//
// OUPUTS:
//    s - 1 x 1 distance in meters between the two positions
//
//
// --------------------------------------------------------------------------
//  Author: Michael Shafer
//  Date: 2023-06-12
// --------------------------------------------------------------------------
// --------------------------------------------------------------------------
//
// Arguments    : double lat1
//                double lon1
//                double lat2
//                double lon2
// Return Type  : double
//
double vincentydistance(double lat1, double lon1, double lat2, double lon2)
{
  double L;
  double U1;
  double U2;
  double cos2Sigma_m;
  double cosAlphaSquared;
  double cosSigma;
  double lamNew;
  double residual;
  double sigma;
  double sinSigma;
  // Using WGS-84
  // Test points
  //  lat1 = 35.174505555555555; %35 + 10/60 + 28.22/3600;
  //  lon1 = 111.6576666666667; % 111+ 39/60 + 27.60/3600;
  //
  //  lat2 = 35.174511111111109;    % 35 + 10/60 + 28.24/3600;
  //  lon2 = 111.6563944444444; % 111+ 39/60 + 23.02/3600;
  //
  //  mapDist = 115.97;
  // s is the ellipsoidal distance between the two points;
  // Length of semi-major axis of the ellipsoid (radius at equator);
  // Flattening of the ellipsoid;
  // Length of semi-minor axis of the ellipsoid (radius at the poles);
  // (1-f)a
  // Latitude of the points;
  // Reduced latitude (latitude on the auxiliary sphere)
  U1 = std::atan(0.99664718933525254 *
                 std::tan(lat1 * 3.1415926535897931 / 180.0));
  U2 = std::atan(0.99664718933525254 *
                 std::tan(lat2 * 3.1415926535897931 / 180.0));
  // Longitude of the points;
  // Difference in longitude of two points;
  L = lon2 * 3.1415926535897931 / 180.0 - lon1 * 3.1415926535897931 / 180.0;
  lamNew = L;
  residual = 1.0;
  cosAlphaSquared = rtNaN;
  sinSigma = rtNaN;
  cos2Sigma_m = rtNaN;
  cosSigma = rtNaN;
  sigma = rtNaN;
  //  figure
  while (residual > 1.0E-12) {
    double a_tmp;
    double b_a_tmp;
    double c_a_tmp;
    double lam;
    lam = lamNew;
    residual = std::cos(U2);
    a_tmp = std::sin(lamNew);
    cosAlphaSquared = residual * a_tmp;
    b_a_tmp = std::sin(U1);
    c_a_tmp = std::sin(U2);
    cos2Sigma_m = std::cos(U1);
    cosSigma = std::cos(lamNew);
    lamNew = cos2Sigma_m * c_a_tmp - b_a_tmp * residual * cosSigma;
    sinSigma = std::sqrt(cosAlphaSquared * cosAlphaSquared + lamNew * lamNew);
    lamNew = cos2Sigma_m * residual;
    cosSigma = b_a_tmp * c_a_tmp + lamNew * cosSigma;
    sigma = rt_atan2d_snf(sinSigma, cosSigma);
    residual = lamNew * a_tmp / sinSigma;
    lamNew = residual * residual;
    cos2Sigma_m = cosSigma - 2.0 * b_a_tmp * c_a_tmp / (1.0 - lamNew);
    cosAlphaSquared = 1.0 - lamNew;
    lamNew = 0.00020955066654671753 * (1.0 - lamNew) *
             (4.0 - 0.0033528106647474805 * (4.0 - 3.0 * (1.0 - lamNew)));
    lamNew =
        L + (1.0 - lamNew) * 0.0033528106647474805 * residual *
                (sigma + lamNew * sinSigma *
                             (cos2Sigma_m +
                              lamNew * cosSigma *
                                  (2.0 * (cos2Sigma_m * cos2Sigma_m) - 1.0)));
    residual = (lamNew - lam) / lam;
    //  plot(i, residual,'.'); hold on;
    //  drawnow
  }
  residual = cosAlphaSquared * 0.006739496742333464;
  lamNew = residual / 1024.0 *
           (residual * (residual * (74.0 - 47.0 * residual) - 128.0) + 256.0);
  cosAlphaSquared = cos2Sigma_m * cos2Sigma_m;
  return 6.356752314245E+6 *
         (residual / 16384.0 *
              (residual * (residual * (320.0 - 175.0 * residual) - 768.0) +
               4096.0) +
          1.0) *
         (sigma -
          lamNew * sinSigma *
              (cos2Sigma_m +
               0.25 * lamNew *
                   (cosSigma * (2.0 * cosAlphaSquared - 1.0) -
                    lamNew / 6.0 * cos2Sigma_m * (-3.0 - 4.0 * sinSigma) *
                        (4.0 * cosAlphaSquared - 3.0))));
  //  alpha1 = atan2(cos(U2)*sin(lam),...
  //      cos(U1)*sin(U2)-sin(U1)*cos(U2)*cos(lam));
  //  alpha2 = atan2(cos(U1)*sin(lam),...
  //      -sin(U1)*cos(U2)+cos(U1)*sin(U2)*cos(lam));
}

//
// File trailer for vincentydistance.cpp
//
// [EOF]
//
