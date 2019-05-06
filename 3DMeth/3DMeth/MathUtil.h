#pragma once
#ifndef _MATH_H_INCLUDED_
#define _MATH_H_INCLUDED_
#include <math.h>
const float kPi = 3.14159265f;
const float k2Pi = kPi * 2.0F;
const float kPiOver2 = kPi / 2.0f;
inline void sinCos(float *returnSin, float *returnCos, float theta) {
	*returnSin = sin(theta);
	*returnCos = cos(theta);
}
#endif // ! _MATH_H_INCLUDED_
