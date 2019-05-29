#include<iostream>
#include"Vector3.h"
#include "MathUtil.h"
#include "Matrix4x3.h"
#include "RotationMatrix.h"
#include "EulerAngles.h"
using namespace std;
float to_zero(float n) {
	return ((abs(n) < 0.00001) ? 0 : n);
}
void print_v(Vector3 v) {
	cout << "{" << to_zero(v.x) << "," << to_zero(v.y) << "," << to_zero(v.z) << "}" << endl;
}

void print_m(Matrix4x3 m) {
	cout << to_zero(m.m11) << "\t" << to_zero(m.m12) << "\t" << to_zero(m.m13) << endl;
	cout << to_zero(m.m21) << "\t" << to_zero(m.m22) << "\t" << to_zero(m.m23) << endl;
	cout << to_zero(m.m31) << "\t" << to_zero(m.m32) << "\t" << to_zero(m.m33) << endl;
}


int main()
{
#pragma region 向量
	/*Vector3 v1(10, 20, 30);
	print_v(v1);
	Vector3 v2(v1);
	print_v(v2);

	Vector3 v3 = -v1;
	print_v(v3);
	v2.zero();
	print_v(v2);
	Vector3 v4(5, -4, 7);
	float r = vectorMag(v4);
	cout << r << endl;*/

	/*Vector3 v5(1, 2, 3);
	Vector3 v6 = 6*v5;
	Vector3 v7 = v5 / 5;

	print_v(v6);
	v5 *= 5;
	print_v(v5);*/
	/*Vector3 v11(12, -5, 0);
	Vector3 v12(6, -5, 5);
	Vector3 v13 = v11 - v12;
	print_v(v13);
	v11.normalize();
	print_v(v11);
	Vector3 v14(1, 1, 0);
	Vector3 v15(2, 2, 0);
	float d = distance(v14, v15);

	cout <<"dis"<< d << endl;*/
	//Vector3 v16(3, -2, 7);
	//Vector3 v17(0, 4, -1);
	//float dot = v16 * v17;
	//cout << "dot " << dot << endl;
	//float angle = acos(dot / (vectorMag(v16)*vectorMag(v17))) * 180 / 3.14159;
	//cout << "angele is --" << angle << endl;

	//Vector3 t1(1, 3, 4);
	//Vector3 t2(2, -5, 8);
	//Vector3 cross = corss(t1, t2);
	//print_v(cross);

	//float d = t1 * cross;
	//cout << d << endl;
#pragma endregion

#pragma region 矩阵
	/*cout << "矩阵" << endl;
	Matrix3x3 a, b,c;
	a.m11 = 1; a.m12 = -5; a.m13 = 3;
	a.m21 = 0; a.m22 = -2; a.m23 = 6;
	a.m31 = 7; a.m32 = 2;  a.m33 = -4;

	b.m11 = -8; b.m12 = 6; b.m13 = 1;
	b.m21 = 7;  b.m22 = 0; b.m23 = -3;
	b.m31 = 2;  b.m32 = 4; b.m33 = 5;
	c = a * b;

	print_m(c);

	cout << "矩阵和向量相乘" << endl;
	Vector3 v(1,2,3);
	Vector3 p = v * a;
	print_m(a);
	print_v(p);*/
#pragma endregion

	//cout << "---旋转---" << endl;
	//Vector3 a(10, 0, 0);
	//Vector3 b;
	//Matrix3x3 M;
	////print_m(M);
	//M.setRotate(3, kPiOver2);
	//print_m(M);
	//b = a * M;
	//M.setRotate(3, kPi);
	//b = a * M;
	//print_v(b);

	//Matrix3x3 M;
	//Vector3 s(1, 2, 3);
	///*M.setScale(s);
	//Vector3 a(2, 2, 2);
	//Vector3 b = a * M;
	//print_v(b);*/

	//Vector3 c(10, 20, 30), b;
	//Vector3 n(0, 0, 1);
	//M.setupProject(n);
	//print_m(M);
	//b = c * M;
	//print_v(b);
	//Matrix3x3 M;
	//Vector3 a(10, 20, 30),b;
	//M.setupReflect(1);
	//b = a * M;
	// print_v(b);
	// M.setupShear(1, 1, 2);
	// b = a * M;
	// print_v(b);
	//Matrix4x3 a;
	//a.m11 = 1; a.m12 = -5; a.m13 = 3;
	//a.m21 = 0; a.m22 = -2; a.m23 = 6;
	//a.m31 = 7; a.m32 = 2;  a.m33 = -4;
	//
	//Matrix4x3 b = inverse(a);
	//Matrix4x3 c = a * b;
	//print_m(c);

RotationMatrix m;
//m.m11 = 0.866; m.m12 = 0.0f; m.m13 =  -0.5f;
//m.m21 = 0.0f; m.m22 = 1.0f; m.m23 = 0.0f;
//m.m31 = 0.5f; m.m32 = 0.0f; m.m33 = 0.866;
//弧度
m.setup(EulerAngles(30*kPi /180,0,0));
Vector3 v(10, 20, 30);
Vector3 v2;
//惯性空间绕m矩阵旋转
v2 = m.inertialToObject(v);
print_v(v2);
v2 = m.objectToinertial(v);
print_v(v2);
	system("pause");
	return 0;
}