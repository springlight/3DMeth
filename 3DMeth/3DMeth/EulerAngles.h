#pragma once
#ifndef  _EULERANGLER_
#define _EULERANGLER_
#include "RotationMatrix.h"
#include "Matrix4x3.h"

class EulerAngles
{
public:
	float heading;//世界y轴旋转
	float pitch;//物体x轴旋转
	float bank;//物体z轴
	EulerAngles(){}
	EulerAngles(float h,float p,float b):heading(h),pitch(p),bank(b){}
	void cannoize();
	void fromOjbectToWorldMatrix(const Matrix4x3 &m);
	//惯性到物体
	void fromWorldToObjectMatrix(const Matrix4x3 &m);
	void fromRotationMarix(const RotationMatrix &m);

private:

};
#endif // ! _EULERANGLER_
