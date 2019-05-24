#pragma once
class EulerAngles
{
public:
	float heading;//世界y轴旋转
	float pitch;//物体x轴旋转
	float bank;//物体z轴
	EulerAngles(){}
	EulerAngles(float h,float p,float b):heading(h),pitch(p),bank(b){}

private:

};

