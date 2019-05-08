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

	void setRotate(int axis, float theta);
	void setScale(const float kX, const float kY, const float kZ);
	void setScale(const Vector3 &s);
	/*
	投影矩阵，参数是垂直于投影面的向量
	*/
	void setupProject(const Vector3 &n);
	
	/*镜像矩阵*/
	void setupReflect(int aXis);
	/*空间内任意平面镜像矩阵，参数是垂直于改空间平面的法向量*/
	void setupReflect(const Vector3 &n);
	/*切变*/
	void setupShear(int axis, float s, float t);
	
private:

};

Matrix3x3 operator *(const Matrix3x3 &a, const Matrix3x3 &b);
Vector3 operator *(const Vector3 &p, const Matrix3x3 &m);

Matrix3x3 &operator *=(Matrix3x3 &a,const Matrix3x3 &m);
Vector3 &operator *=( Vector3 &p, const Matrix3x3 &m);
/*矩阵行列式*/
float getDet(const Matrix3x3 &m);
#endif // !_MATRIX3X3_H_INCLUDED

