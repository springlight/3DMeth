
#ifndef __ROTATIONMATRIX_H_INCLUDE__
#define __ROTATIONMATRIX_H_INCLUDE__
#include "Vector3.h"

/*
*��������ϵ�͹�������ϵ����������ϵ��ת��
*/
class RotationMatrix
{
public:
	float m11, m12, m13;
	float m21, m22, m23;
	float m31, m32, m33;

	void idenity();

	/*
	��������ϵ����������ϵ
	*/
	Vector3 inertialToObject(const Vector3 &v) const;
	/*
	��������ϵ����������ϵ
	*/
	Vector3 objectToinertial(const Vector3 &v)const;

private:

};
#endif // !__ROTATIONMATRIX_H_INCLUDE__
