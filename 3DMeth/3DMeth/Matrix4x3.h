#pragma once
#ifndef _MATRIX3X3_H_INCLUDED
#define _MATRIX3X3_H_INCLUDED
class Vector3;


class  Matrix4x3
{
public:
	float m11, m12, m13;
	float m21, m22, m23;
	float m31, m32, m33;
	float tx, ty, tz;

	void setRotate(int axis, float theta);
	void setScale(const float kX, const float kY, const float kZ);
	void setScale(const Vector3 &s);
	/*
	ͶӰ���󣬲����Ǵ�ֱ��ͶӰ�������
	*/
	void setupProject(const Vector3 &n);
	
	/*�������*/
	void setupReflect(int aXis,float k);
	/*�ռ�������ƽ�澵����󣬲����Ǵ�ֱ�ڸĿռ�ƽ��ķ�����*/
	void setupReflect(const Vector3 &n);
	/*�б�*/
	void setupShear(int axis, float s, float t);

	void zeroTranslation();
	void setTranslation(const Vector3 &d);
	void setupTranslation(const Vector3 &d);
	
	
private:

};

Matrix4x3 operator *(const Matrix4x3 &a, const Matrix4x3 &b);
Vector3 operator *(const Vector3 &p, const Matrix4x3 &m);

Matrix4x3 &operator *=(Matrix4x3 &a,const Matrix4x3 &m);
Vector3 &operator *=( Vector3 &p, const Matrix4x3 &m);
/*��������ʽ*/
float getDet(const Matrix4x3 &m);
//������
Matrix4x3 inverse(const Matrix4x3 &m);

Vector3 getTranslation(const Matrix4x3 &m);
#endif // !_MATRIX3X3_H_INCLUDED

