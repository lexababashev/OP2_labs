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
	c = 0;
	Radian = M_PI / 4;
	Degrees = 45;
	this->k = tan(Radian);

}

Line::Line(int c)
{
	a = 1;
	b = 1;
	this->c = c;
	Radian = 3 * M_PI / 4;
	Degrees = 135;

	this->k = tan(Radian);

}

Line::Line(int a, int b, int c)
{
	this->a = a;
	this->b = b;
	this->c = c;

	if (b==0)
	{
		Radian = M_PI / 2;
		Degrees = 90;
		this->k = 0;

	}
	else {
		Radian = atan((double)(-a) / (double)b);
		Degrees = RadianToDegrees();

		this->k = tan(Radian);

	}

}

int Line::Ox() {
	int x;
	if (a==0)
	{
		cout << " the line lies on Ox or parallel to the axis! "<<'\n';
		return 0;
	}
	else {
		x = -(c/a);
		return x;
	}
}
int Line::Oy() {
	int y;
	if (b==0)
	{
		
		cout << " the line lies on Oy or parallel to the axis! " << '\n';
		return 0;
	}
	else {
		y = -(c / b);
		return y;
	}

}

 void Line::operator++()
{
	this->Degrees += 1;
	Radian = DegreesToRadian();

	this->k = tan(Radian);

}

bool Line::operator||(Line lineToCheckWith)
{
	if (this->a == lineToCheckWith.get_a() && this->b == lineToCheckWith.get_b())
	{
		return true;
	}
	else {
		return false;
	}
}

int Line::get_a() {
	return a;
}
int Line::get_b() {
	return b;
}
int Line::get_c() {
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