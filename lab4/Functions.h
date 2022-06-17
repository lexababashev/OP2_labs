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
	Line(int);
	Line(int, int, int);

	int get_a();
	int get_b();
	int get_c();
	double get_k();


	double get_Degrees();
	double get_Radian();

	int Ox();
	int Oy();

	void operator++();

	bool operator||(Line lineToCheckWith);

private:
	int a, b, c;
	double k;
	double Radian, Degrees;

	double RadianToDegrees();
	double DegreesToRadian();




};
