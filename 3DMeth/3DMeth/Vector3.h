#pragma once
#ifndef  _VECTOR3_H_
#define  _VECTOR3_H_
#include<math.h>
#include <iostream>
using namespace std;
class Vector3 {
public :
	float x, y, z;
	Vector3(){}
	//复制构造函数
	Vector3(const Vector3 &a):x(a.x),y(a.y),z(a.z){}
	Vector3(float nx,float ny,float nz):x(nx),y(ny),z(nz){}

	void zero() { x = y = z = 0; }
	//负向量
	Vector3 operator -()const { return Vector3(-x, -y, -z); }
	//向量和标量相乘
	Vector3 operator *(float a)const {
		return Vector3(x*a, y*a, z*a);
	}
	Vector3 operator /(float a)const {
		float oneOverA = 1.0f / a;//计算机里乘法速度快
		return Vector3(x*oneOverA,y*oneOverA, z*oneOverA);
	}

	Vector3 operator +(const Vector3 &a) const {
		return Vector3(x + a.x, y + a.y, z + a.z);
	}
	Vector3 operator +=(const Vector3 &a) {
		x += a.x;
		y += a.y;
		z += a.z;
		return *this;
	}
	Vector3 operator -=(const Vector3 &a) {
		x -= a.x;
		y -= a.y;
		z -= a.z;
		return *this;
	}
	Vector3 operator -(const Vector3 &a) const {
		cout << x <<"/"<< y <<"/"<< z << endl;
		return Vector3(x - a.x, y - a.y, z - a.z);
	}

	Vector3 operator *=(float a) {
		x *= a;
		y *= a;
		z *= a;
		return *this;
	}
	Vector3 operator /=(float a)
	{
		float oneOverA = 1.0f / a;
		x *= oneOverA;
		y *= oneOverA;
		z *= oneOverA;
		return *this;
	}
	//向量标准化
	void normalize() {
		float magSq = x * x + y * y + z * z;
		if (magSq > 0.0f) {
			float oneOverMag = 1.0f / sqrt(magSq);
			x *= oneOverMag;
			y *= oneOverMag;
			z *= oneOverMag;
		}
	}
	//向量点乘
	float operator *(const Vector3 &a) const {
		return x * a.x + y * a.y + z * a.z;
	}
	
};
//计算向量模
inline float vectorMag(const Vector3 &a) {
	return sqrt(a.x * a.x + a.y *a.y + a.z *a.z);
}
//
inline Vector3 operator*(float k,const Vector3 &a) {
	return Vector3(k*a.x, k*a.y, k*a.z);
}

inline float distance(const Vector3 &a, const Vector3 &b) {
	return vectorMag(a - b);
}
inline Vector3 corss( const Vector3 &a,const Vector3 &b) {
	return Vector3(a.y*b.z - b.y*a.z, b.x*a.z - a.x * b.z, a.x*b.y - b.x*a.y);
}
#endif // ! _VECTOR3_H_

