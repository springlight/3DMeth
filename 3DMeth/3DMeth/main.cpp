#include<iostream>
#include"Vector3.h"
using namespace std;

void print_v(Vector3 v) {
	cout << "{" << v.x << "," << v.y << "," << v.z << "}" << endl;
}
int main()
{
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
	Vector3 v11(12, -5, 0);
	Vector3 v12(6, -5, 5);
	Vector3 v13 = v11 - v12;
	print_v(v13);
	v11.normalize();
	print_v(v11);
	Vector3 v14(1, 1, 0);
	Vector3 v15(2, 2, 0);
	float d = distance(v14, v15);
	cout <<"dis"<< d << endl;
	system("pause");
	return 0;
}