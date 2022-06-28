#pragma once
#define _USE_MATH_DEFINES
#define TO_DEGREES (180 / M_PI)
#include <iostream>
#include<cmath>
#include<vector>


using namespace std;

class Line
{
public:
	Line();
	Line(double, double, double);
	Line(Line& a);
	

	double get_a();
	double get_b();
	double get_c();
	double get_k();


	double get_Degrees();
	double get_Radian();

	double Ox();
	double Oy();

	void operator++();

	bool operator||(Line lineToCheckWith);

private:
	double a, b, c;
	double k;
	double Radian, Degrees;

	double RadianToDegrees();
	double DegreesToRadian();

};
