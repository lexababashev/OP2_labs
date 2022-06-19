#include "Functions.h"

double Line::RadianToDegrees()
{
	return Radian * (180.0 / M_PI);
}

double Line::DegreesToRadian()
{
	return Degrees * (M_PI / 180.0);
}

Line::Line()
{
	a = 1;
	b = -1;
	c = 1;
	Radian = M_PI / 4;
	Degrees = 45;
	k = tan(Radian);


}

Line::Line(Line& copyClass)
{
	this->a = copyClass.get_a();
	this->b = copyClass.get_b();
	this->c = copyClass.get_c();
	this->Radian = copyClass.get_Radian();
	this ->Degrees = copyClass.get_Degrees();
	this->k = copyClass.get_k();
}

Line::Line(double a, double b, double c)
{
	this->a = a;
	this->b = b;
	this->c = c;

	if (b==0)
	{
		this->Radian = M_PI / 2;
		this->Degrees = 90;
		this->k = 1;

	}
	else {
		Radian = atan((double)(-a) / (double)b);
		Degrees = RadianToDegrees();
		this->k = tan(Radian);

	}



}

double Line::Ox() {


		if (c == 0) {
			return 0;
		}
		else {
			return -(c / a);
		}
	
}
double Line::Oy() {


		if (c == 0) {
			return 0;
		}
		else {
			return -(c / b);
		}
		

}

 void Line::operator++()
{
	this->Degrees -= 1;
	Radian = DegreesToRadian();

	this->k = tan(Radian);
	if (c!=0)
	{
		this->a = c / k;
	}
}

bool Line::operator||(Line lineToCheckWith)
{
	if (this->a/lineToCheckWith.get_a() == this->b/lineToCheckWith.get_b())
	{
		return true;
	}
	else {
		return false;
	}
}

double Line::get_a() {
	return a;
}
double Line::get_b() {
	return b;
}
double Line::get_c() {
	return c;
}
double Line::get_k() {
	return k;
}

double Line::get_Degrees() {
	return Degrees;
}
double Line::get_Radian() {
	return Radian;
}
