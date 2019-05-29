#include "MathUtil.h"
#include<math.h>

float wrapPi(float theta) {
	theta += kPi;
	theta -= floor(theta*kiOver2Pi)*k2Pi;
	theta -= kPi;
	return theta;
}