#pragma once

namespace otto {

const float PI = M_PI;
const float TWO_PI = M_PI * 2.0f;
const float HALF_PI = M_PI / 2.0f;

float regularPolyRadius(float sideLen, uint32_t numSides);

float lerp(float a, float b, float t);
float lerpAngular(float angle, float targetAngle, float t);

float map(float x, float imin, float imax, float omin, float omax);
float mapUnit(float x, float imin, float imax);

float mapClamp(float x, float imin, float imax, float omin, float omax);
float mapUnitClamp(float x, float imin, float imax);

float clamp(float x, float omin, float omax);

} // otto
