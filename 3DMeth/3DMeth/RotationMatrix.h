
#ifndef __ROTATIONMATRIX_H_INCLUDE__
#define __ROTATIONMATRIX_H_INCLUDE__
#include "Vector3.h"

/*
*世界坐标系和惯性坐标系，物体坐标系的转换
*/
class RotationMatrix
{
public:
	float m11, m12, m13;
	float m21, m22, m23;
	float m31, m32, m33;

	void idenity();

	/*
	惯性坐标系到物体坐标系
	*/
	Vector3 inertialToObject(const Vector3 &v) const;
	/*
	物体坐标系到惯性坐标系
	*/
	Vector3 objectToinertial(const Vector3 &v)const;

private:

};
#endif // !__ROTATIONMATRIX_H_INCLUDE__
