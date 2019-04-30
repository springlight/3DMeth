#include<iostream>
#include"Vector3.h"
#include "Matrix3x3.h"
using namespace std;

void print_v(Vector3 v) {
	cout << "{" << v.x << "," << v.y << "," << v.z << "}" << endl;
}

void print_m(Matrix3x3 m) {
	cout << m.m11 << "\t" << m.m12 << "\t" << m.m13 << endl;
	cout << m.m21 << "\t" << m.m22 << "\t" << m.m23 << endl;
	cout << m.m31 << "\t" << m.m32 << "\t" << m.m33 << endl;
}
int main()
{
#pragma region ÏòÁ¿
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
	Vector3 v16(3, -2, 7);
	Vector3 v17(0, 4, -1);
	float dot = v16 * v17;
	cout << "dot " << dot << endl;
	float angle = acos(dot / (vectorMag(v16)*vectorMag(v17))) * 180 / 3.14159;
	cout << "angele is --" << angle << endl;

	Vector3 t1(1, 3, 4);
	Vector3 t2(2, -5, 8);
	Vector3 cross = corss(t1, t2);
	print_v(cross);

	float d = t1 * cross;
	cout << d << endl;
#pragma endregion

	cout << "¾ØÕó" << endl;
	Matrix3x3 a, b,c;
	a.m11 = 1; a.m12 = -5; a.m13 = 3;
	a.m21 = 0; a.m22 = -2; a.m23 = 6;
	a.m31 = 7; a.m32 = 2;  a.m33 = -4;

	b.m11 = -8; b.m12 = 6; b.m13 = 1;
	b.m21 = 7;  b.m22 = 0; b.m23 = -3;
	b.m31 = 2;  b.m32 = 4; b.m33 = 5;
	c = a * b;

	print_m(c);
	system("pause");
	return 0;
}