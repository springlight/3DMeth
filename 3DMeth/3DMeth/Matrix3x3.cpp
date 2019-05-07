#include"Vector3.h"
#include"Matrix3x3.h"
#include "MathUtil.h"
#include <assert.h>
/*
axis:��ת��1;x�ᣬ2��y�ᣬ3��z��
theta:��ת�Ƕ�
return:������ת����
*/
void Matrix3x3::setRotate(int axis, float theta) {

	float s, c;
	sinCos(&s, &c, theta);
	switch (axis)
	{
		case 1:
			m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
			m21 = 0.0f; m22 = c; m23 = s;
			m31 = 0.0f; m32 = -s; m33 = c;
			break;
		case 2:
			m11 = c;    m12 = 0.0f; m13 = -s;
			m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
			m31 = s;    m32 = 0.0f; m33 = c;
			break;
		case 3:
			m11 = c;    m12 = s; m13 = 0.0f;
			m21 = -s; m22 = c; m23 = 0.0f;
			m31 = 0.0f;    m32 = 0.0f; m33 = 1.0f;
			break;
		default:
		break;
	}
}
/*
���ž���
*/
void Matrix3x3::setScale(const float kX,const float kY,const float kZ) 
{
	m11 = kX; m12 = 0.0f; m13 = 0.0f;
	m21 = 0.0f; m22 = kY; m23 = 0.0f;
	m31 = 0.0f; m32 = 0.0; m33 = kZ;

}

/*
ͶӰ����
*/

void Matrix3x3::setupProject(const Vector3 &n) {
	assert(fabs(n*n) - 1.0f < 0.01);
	m11 = 1.0f - n.x*n.x;
	m22 = 1.0f - n.y*n.y;
	m33 = 1.0f - n.z*n.z;

	m12 = m21 = -n.x *n.y;
	m13 = m31 = -n.x *n.z;
	m23 = m32 = -n.y*n.z;
}

void Matrix3x3::setScale(const Vector3 &s)
{
	m11 = s.x; m12 = 0.0f; m13 = 0.0f;
	m21 = 0.0f; m22 = s.y; m23 = 0.0f;
	m31 = 0.0f; m32 = 0.0; m33 = s.z;

}

Matrix3x3 operator *(const Matrix3x3 &a, const Matrix3x3 &b) 
{
	Matrix3x3 r;
	//r�ĵ�һ��
	r.m11 = a.m11*b.m11 + a.m12*b.m21 + a.m13*b.m31;
	r.m12 = a.m11*b.m12 + a.m12*b.m22 + a.m13*b.m32;
	r.m13 = a.m11*b.m13 + a.m12*b.m23 + a.m13*b.m33;
	//r�ĵڶ���
	r.m21 = a.m21*b.m11 + a.m22*b.m21 + a.m23*b.m31;
	r.m22 = a.m21*b.m12 + a.m22*b.m22 + a.m23*b.m32;
	r.m23 = a.m21*b.m13 + a.m22*b.m23 + a.m23*b.m33;
	//r�ĵ�����
	r.m31 = a.m31*b.m11 + a.m32*b.m21 + a.m33*b.m31;
	r.m32 = a.m31*b.m12 + a.m32*b.m22 + a.m33*b.m32;
	r.m33 = a.m31*b.m13 + a.m32*b.m23 + a.m33*b.m33;
	return r;
}
Matrix3x3 &operator *=(Matrix3x3 &a, const Matrix3x3 &m) {
	return a = a * m;
}
//�������;������.DX����������opengl ��������
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

