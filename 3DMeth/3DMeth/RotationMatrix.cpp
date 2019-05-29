#include "RotationMatrix.h"
#include "MathUtil.h"

/*
��λ����
*/
//������������ת��һ��
void RotationMatrix::idenity() {
	m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
	m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
}
/*
����v�ǹ�������ϵ�Ŀռ����������յó���������ϵ�Ŀռ�����
���Կռ������������ת���󣬿��԰ѹ�������ϵת�䵽��������ϵ
*/
Vector3 RotationMatrix::inertialToObject(const Vector3 &v)const {
	return Vector3(m11*v.x + m21 * v.y + m31 * v.z,
	      	    m12*v.x + m22 * v.y + m32 * v.z,
		      m13*v.x + m23 * v.y + m33 * v.z);
}
/*
&v������ռ������
����ռ������������ת�����ת�ã���Ҳ���ǳ��Ծ�����棬��Ϊ���������ת��һ������Ҳ������һ��������
����������ó���������ϵ����������ϵ
*/
Vector3 RotationMatrix::objectToinertial(const Vector3 &v)const {
	return Vector3(m11*v.x + m12 * v.y + m13 * v.z,
		m21*v.x + m22 * v.y + m23 * v.z,
		m31*v.x + m33 * v.y + m33 * v.z);
}
