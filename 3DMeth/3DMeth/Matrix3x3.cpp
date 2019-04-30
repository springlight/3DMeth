#include"Vector3.h"
#include"Matrix3x3.h"
Matrix3x3 operator *(const Matrix3x3 &a, const Matrix3x3 &b) 
{
	Matrix3x3 r;
	//r的第一行
	r.m11 = a.m11*b.m11 + a.m12*b.m21 + a.m13*b.m31;
	r.m12 = a.m11*b.m12 + a.m12*b.m22 + a.m13*b.m32;
	r.m13 = a.m11*b.m13 + a.m12*b.m23 + a.m13*b.m33;
	//r的第二行
	r.m21 = a.m21*b.m11 + a.m22*b.m21 + a.m23*b.m31;
	r.m22 = a.m21*b.m12 + a.m22*b.m22 + a.m23*b.m32;
	r.m23 = a.m21*b.m13 + a.m22*b.m23 + a.m23*b.m33;
	//r的第三行
	r.m31 = a.m31*b.m11 + a.m32*b.m21 + a.m33*b.m31;
	r.m32 = a.m31*b.m12 + a.m32*b.m22 + a.m33*b.m32;
	r.m33 = a.m31*b.m13 + a.m32*b.m23 + a.m33*b.m33;
	return r;
}
Matrix3x3 &operator *=(Matrix3x3 &a, const Matrix3x3 &m) {
	return a = a * m;
}
//行向量和矩阵相乘.DX是行向量，opengl 是列向量
Vector3 operator *(const Vector3 &p, const Matrix3x3 &m)
{
	Vector3 v;
	v.x = p.x*m.m11 + p.y*m.m21 + p.z*m.m31;
	v.y = p.x*m.m12 + p.y*m.m22 + p.z*m.m32;
	v.z = p.x*m.m13 + p.y*m.m23 + p.z*m.m33;
	return v;
}

Vector3 &operator *=(Vector3 &p, const Matrix3x3 &m) {
	return p = p * m;
}

