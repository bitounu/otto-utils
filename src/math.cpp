#include "math.hpp"

namespace otto {

float regularPolyRadius(float sideLen, uint32_t numSides) {
  return sideLen / (2.0f * std::sin(PI / numSides));
}

float lerp(float a, float b, float t) {
  return a + (b - a) * t;
}

// Interpolate between two angles, assuming both angles are in the range 0-2pi.
float lerpAngular(float angle, float targetAngle, float t) {
  auto angleDiff = std::abs(targetAngle - angle);
  if (std::abs(angle - (targetAngle + TWO_PI)) < angleDiff) {
    targetAngle += TWO_PI;
  }
  return angle + (targetAngle - angle) * t;
}

float map(float x, float imin, float imax, float omin, float omax) {
  return omin + (x - imin) / (imax - imin) * (omax - omin);
}

float mapUnit(float x, float imin, float imax) {
  return (x - imin) / (imax - imin);
}

float mapClamp(float x, float imin, float imax, float omin, float omax) {
  return std::max(omin, std::min(omax, map(x, imin, imax, omin, omax)));
}

float mapUnitClamp(float x, float imin, float imax) {
  return std::max(0.0f, std::min(1.0f, mapUnit(x, imin, imax)));
}

float clamp(float x, float omin, float omax) {
  return std::min(omax, std::max(omin, x));
}

} // otto
