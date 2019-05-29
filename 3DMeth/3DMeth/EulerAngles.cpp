#include "EulerAngles.h"
#include "MathUtil.h"

/*����ŷ���ǽǶ�*/
void EulerAngles::cannoize() {
	pitch = wrapPi(pitch);
	if (pitch < -kPiOver2) {
		pitch = -kPi - pitch;
		heading += kPi;
		bank += kPi;
	}
	else if (pitch > kPiOver2) {
		pitch = kPi - pitch;
		heading += kPi;
		bank += kPi;
	}

	if (abs(pitch) > kPiOver2) {
		heading += bank;
		bank = 0.0f;
	}
	else {
		bank = wrapPi(bank);
	}
	heading = wrapPi(heading);
}
void EulerAngles::fromRotationMarix(const RotationMatrix &m) {
	float sp = -m.m23;//-sin(p)
	//���������
	//p = ����90������
	if ((fabs(sp) < 0.9999f))
	{
		pitch = kPiOver2 * sp;
		bank = 0.0f;
		heading = atan2(-m.m31, m.m11);

	}
	else {
		heading = atan2(m.m13, m.m33);
		pitch = asin(sp);
		bank = atan2(m.m21, m.m22);
	}
}

void EulerAngles::fromWorldToObjectMatrix(const Matrix4x3 &m) {
	float sp = -m.m23;//-sin(p)
	//���������
	//p = ����90������
	if ((fabs(sp) < 0.9999f))
	{
		pitch = kPiOver2 * sp;
		bank = 0.0f;
		heading = atan2(-m.m31, m.m11);

	}
	else {
		heading = atan2(m.m13, m.m33);
		pitch = asin(sp);
		bank = atan2(m.m21, m.m22);
	}
}
/*����-������*/

void EulerAngles::fromOjbectToWorldMatrix(const Matrix4x3 &m) {

	float sp = -m.m32;//-sin(p)
	//���������
	//p = ����90������
	if ((fabs(sp) < 0.9999f))
	{
		pitch = kPiOver2 * sp;
		bank = 0.0f;
		heading = atan2(-m.m23, m.m11);

	}
	else {
		heading = atan2(m.m13, m.m33);
		pitch = asin(sp);
		bank = atan2(m.m21, m.m22);
	}
}
/*ŷ����ת������ת���󣬹�������ϵ-->��������ϵ*/
void RotationMatrix::setup(const EulerAngles &oriention)
{
	float sh, ch, sp, cp, sb, cb;
	sinCos(&sh, &ch, oriention.heading);
	sinCos(&sp, &cp, oriention.pitch);
	sinCos(&sb, &cb, oriention.bank);

	m11 = ch * cb + sh * sp*sb;
	m12 = -ch * sb + sh * sp*cb;
	m13 = sh * cp;

	m21 = sb * cp;
	m22 = cb * cp;
	m23 = -sp;

	m31 = -sh * cb + ch * sp*sb;
	m32 = sb * sh + ch * sp*cb;
	m33 = ch * cp;

}
