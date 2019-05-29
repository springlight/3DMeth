#include "RotationMatrix.h"
#include "MathUtil.h"

/*
单位矩阵
*/
//正交矩阵的逆和转置一样
void RotationMatrix::idenity() {
	m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
	m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
}
/*
参数v是惯性坐标系的空间向量，最终得出物体坐标系的空间向量
惯性空间的向量乘以旋转矩阵，可以把惯性坐标系转变到物体坐标系
*/
Vector3 RotationMatrix::inertialToObject(const Vector3 &v)const {
	return Vector3(m11*v.x + m21 * v.y + m31 * v.z,
	      	    m12*v.x + m22 * v.y + m32 * v.z,
		      m13*v.x + m23 * v.y + m33 * v.z);
}
/*
&v是物体空间的向量
物体空间的向量乘以旋转矩阵的转置，（也就是乘以矩阵的逆，因为正交矩阵和转置一样），也就是上一个方法的
方向操作，得出物体坐标系到惯性坐标系
*/
Vector3 RotationMatrix::objectToinertial(const Vector3 &v)const {
	return Vector3(m11*v.x + m12 * v.y + m13 * v.z,
		m21*v.x + m22 * v.y + m23 * v.z,
		m31*v.x + m33 * v.y + m33 * v.z);
}
