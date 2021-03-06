#include"Vector3.h"
#include"Matrix4x3.h"
#include "MathUtil.h"
#include <assert.h>

void Matrix4x3::zeroTranslation() {
	tx = ty = tz = 0.0f;
}

void Matrix4x3::setTranslation(const Vector3 &d) {
	tx = d.x; ty = d.y; tz = d.z;
}

//获取平移矩阵
void Matrix4x3::setupTranslation(const Vector3 &d) {
	m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
	m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
	tx = d.x; ty = d.y; tz = d.z;
}

/*
axis:旋转轴1;x轴，2：y轴，3：z轴
theta:旋转角度
return:返回旋转矩阵
*/
void Matrix4x3::setRotate(int axis, float theta) {

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
	tx = ty = tz = 0.0f;
}
/*
缩放矩阵
*/
void Matrix4x3::setScale(const float kX,const float kY,const float kZ) 
{
	m11 = kX; m12 = 0.0f; m13 = 0.0f;
	m21 = 0.0f; m22 = kY; m23 = 0.0f;
	m31 = 0.0f; m32 = 0.0; m33 = kZ;
	tx = ty = tz = 0.0f;
}

/*
通用投影矩阵
*/

void Matrix4x3::setupProject(const Vector3 &n) {
	assert(fabs(n*n) - 1.0f < 0.01);
	m11 = 1.0f - n.x*n.x;
	m22 = 1.0f - n.y*n.y;
	m33 = 1.0f - n.z*n.z;

	m12 = m21 = -n.x *n.y;
	m13 = m31 = -n.x *n.z;
	m23 = m32 = -n.y*n.z;
	tx = ty = tz = 0.0f;
}

void Matrix4x3::setScale(const Vector3 &s)
{
	m11 = s.x; m12 = 0.0f; m13 = 0.0f;
	m21 = 0.0f; m22 = s.y; m23 = 0.0f;
	m31 = 0.0f; m32 = 0.0; m33 = s.z;
	tx = ty = tz = 0.0f;
}
/*
镜像矩阵
axis；1：x,2:y，3：z
*/
void Matrix4x3::setupReflect(int axis,float k) {
	switch (axis)
	{
	case 1://x = k轴发生镜像
		m11 = -1.0f; m12 = 0.0f; m13 = 0.0f;
		m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
		m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
		tx = 2.0f *k;
		ty = 0.0f;
		tz = 0.0f;
		break;
	case 2://y = k轴发生镜像
		m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
		m21 = 0.0f; m22 = -1.0f; m23 = 0.0f;
		m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
		tx = 0.0;
		ty = 2.0f *k;
		tz = 0.0f;
		break;
	case 3://z= k轴发生镜像
		m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
		m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
		m31 = 0.0f; m32 = 0.0f; m33 = -1.0f;
		tx = 0.0f;
		ty = 0.0f;
		tz = 2.0f *k;
		break;
	default:
		assert(false);
	}
}
/*空间内任意平面镜像矩阵，参数是垂直于改空间平面的法向量*/
void Matrix4x3::setupReflect(const Vector3 &n) 
{
	//确保是单位向量
	assert(fabs(n*n) - 1.0f < 0.01);
	float ax = -2.0f*n.x;
	float ay = -2.0f*n.y;
	float az = -2.0f*n.z;

	m11 = 1.0f + ax * n.x;
	m22 = 1.0f + ay * n.y;
	m33 = 1.0f + az * n.z;

	m12 = m21 = ax * n.y;
	m13 = m31 = ax*n.z;
	m23 = m32 = ay * n.z;
	tx = ty = tz = 0;
}
/*'
切变
*/
void Matrix4x3::setupShear(int axis, float s, float t) {
	switch (axis)
	{
	case 1://用x切变y,z
		m11 = 1.0f; m12 = s; m13 = t;
		m21 = 0.0f; m22 = 1.0f; m23 = 0.0;
		m31 = 0.0f; m32 = 0.0; m33 = 1.0f;
		break;
	case 2:
		m11 = 1.0f; m12 = 0.0; m13 = 0.0;
		m21 = s; m22 = 1.0f; m23 = t;
		m31 = 0.0f; m32 = 0.0; m33 = 1.0f;
		break;
	case 3:
		m11 = 1.0f; m12 = 0.0; m13 = 0.0;
		m21 = 0.0f; m22 = 1.0f; m23 = 0.0;
		m31 = s; m32 = s; m33 = 1.0f;
		break;
	default:
		break;

	}
	tx = ty = tz = 0;
}

float getDet(const Matrix4x3 &m) {
	return m.m11 * m.m22*m.m33 + 
		   m.m12 * m.m23*m.m31 + 
		   m.m13 * m.m21*m.m32 - 
		   m.m11 * m.m23*m.m32 - 
		   m.m12 * m.m21*m.m33 - 
		   m.m13 * m.m22*m.m31;
}

/*
矩阵的逆，
*/
Matrix4x3 inverse(const Matrix4x3 &m) {
	float det = getDet(m);
	//非奇异矩阵才可以求逆，非奇异矩阵行列不是不为零
	assert(fabs(det) > 0.0001);
	float t = 1.0 / det;
	Matrix4x3 r;
	r.m11 = (m.m22*m.m33 - m.m23*m.m32)*t;
	r.m12 = (m.m13*m.m32 - m.m12*m.m33)*t;
	r.m13 = (m.m12*m.m23 - m.m13*m.m22)*t;

	r.m21 = (m.m23*m.m31 - m.m21*m.m33)*t;
	r.m22 = (m.m11*m.m33 - m.m13*m.m31)*t;
	r.m23 = (m.m13*m.m21 - m.m11*m.m23)*t;

	r.m31 = (m.m21*m.m32 - m.m22*m.m31)*t;
	r.m32 = (m.m12*m.m31 - m.m11*m.m32)*t;
	r.m33 = (m.m11*m.m22 - m.m12*m.m21)*t;

	return r;
}
Matrix4x3 operator *(const Matrix4x3 &a, const Matrix4x3 &b) 
{
	Matrix4x3 r;
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

	r.tx = a.tx * b.m11 + a.ty *b.m21 + a.tz*b.m31 + b.tx;
	r.ty = a.tx*b.m12 + a.ty * b.m22 + a.tz*b.m32 + b.ty;
	r.tz = a.tx *b.m13 + a.ty * b.m23 + a.tz * b.m33 + b.tz;
	return r;
}
Vector3 getTranslation(const Matrix4x3 &m) {
	return Vector3(m.tx, m.ty, m.tz);
}
Matrix4x3 &operator *=(Matrix4x3 &a, const Matrix4x3 &m) {
	return a = a * m;
}


//行向量和矩阵相乘.DX是行向量，opengl 是列向量
Vector3 operator *(const Vector3 &p, const Matrix4x3 &m)
{
	Vector3 v;
	v.x = p.x*m.m11 + p.y*m.m21 + p.z*m.m31;
	v.y = p.x*m.m12 + p.y*m.m22 + p.z*m.m32;
	v.z = p.x*m.m13 + p.y*m.m23 + p.z*m.m33;
	return v;
}

Vector3 &operator *=(Vector3 &p, const Matrix4x3 &m) {
	return p = p * m;
}

