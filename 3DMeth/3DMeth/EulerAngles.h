#pragma once
#ifndef  _EULERANGLER_
#define _EULERANGLER_
#include "RotationMatrix.h"
#include "Matrix4x3.h"

class EulerAngles
{
public:
	float heading;//����y����ת
	float pitch;//����x����ת
	float bank;//����z��
	EulerAngles(){}
	EulerAngles(float h,float p,float b):heading(h),pitch(p),bank(b){}
	void cannoize();
	void fromOjbectToWorldMatrix(const Matrix4x3 &m);
	//���Ե�����
	void fromWorldToObjectMatrix(const Matrix4x3 &m);
	void fromRotationMarix(const RotationMatrix &m);

private:

};
#endif // ! _EULERANGLER_
