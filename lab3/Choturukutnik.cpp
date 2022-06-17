#include "Choturukutnik.h"

Point::Point() {
	x = 0;
	y = 0;
}
Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}
int Point::get_x() {
	return x;
}
int Point::get_y() {
	return y;
}
double Choturukutnik::length(Point p1, Point p2) {
	return sqrt(pow((p2.get_x() - p1.get_x()), 2) + pow((p2.get_y() - p1.get_y()), 2));
}

Choturukutnik::Choturukutnik() {}
Choturukutnik::Choturukutnik(Point p1, Point p2, Point p3, Point p4) {
	point1 = p1;
	point2 = p2;
	point3 = p3;
	point4 = p4;
}
bool Choturukutnik::isCorrect() {

	float t1, t2, t3, t4;

	t1 = (point4.get_x() - point1.get_x()) * (point2.get_y() - point1.get_y()) -
		(point4.get_y() - point1.get_y()) * (point2.get_x() - point1.get_x());

	t2 = (point4.get_x() - point2.get_x()) * (point3.get_y() - point2.get_y()) -
		(point4.get_y() - point2.get_y()) * (point3.get_x() - point2.get_x());

	t3 = (point4.get_x() - point3.get_x()) * (point1.get_y() - point3.get_y()) -
		(point4.get_y() - point3.get_y()) * (point1.get_x() - point3.get_x());

	t4 = (point1.get_x() - point3.get_x()) * (point2.get_y() - point1.get_y()) -
		(point1.get_y() - point3.get_y()) * (point2.get_x() - point1.get_x());


	if ((t1 * t2 * t3 * t4) > 0) {
		return true;
	}

	return false;


}
double Choturukutnik::perimetr() {
	return length(point1, point2) + length(point2, point3) + length(point3, point4) + length(point4, point1);
}





