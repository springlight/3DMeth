#pragma once
#ifndef _MATRIX3X3_H_INCLUDED
#define _MATRIX3X3_H_INCLUDED
class Vector3;


class  Matrix3x3
{
public:
	float m11, m12, m13;
	float m21, m22, m23;
	float m31, m32, m33;


private:

};

Matrix3x3 operator *(const Matrix3x3 &a, const Matrix3x3 &b);

Vector3 operator *(const Vector3 &p, const Matrix3x3 &m);
#endif // !_MATRIX3X3_H_INCLUDED

