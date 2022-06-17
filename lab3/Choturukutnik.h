#pragma once
#define _USE_MATH_DEFINES
#define TO_DEGREES (180 / M_PI)
#include <iostream>
#include<math.h>
#include<vector>

using namespace std;

class Point
{
private:
	int x, y;
public:
	Point();
	Point(int x, int y);
	int get_x();
	int get_y();
};


class Choturukutnik
{
private:
	Point point1, point2, point3, point4;
	double length(Point p1, Point p2);

public:
	Choturukutnik();
	Choturukutnik(Point p1, Point p2, Point p3, Point p4);

	bool isCorrect();
	double perimetr();
};

