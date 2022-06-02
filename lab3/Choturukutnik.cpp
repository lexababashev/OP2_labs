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
double Choturukutnik::Kut(Point p1, Point p2, Point p3) {

	double skaliarnii = ((double)p2.get_x() - (double)p1.get_x()) * ((double)p3.get_x() - (double)p2.get_x()) + ((double)p2.get_y() - (double)p1.get_y()) * ((double)p3.get_y() - (double)p2.get_y());
	double znamenik = length(p1, p2) * length(p2, p3);

	double kut = acos(skaliarnii / abs(znamenik));

	return abs(kut * TO_DEGREES);
}
Choturukutnik::Choturukutnik() {}
Choturukutnik::Choturukutnik(Point p1, Point p2, Point p3, Point p4) {
	point1 = p1;
	point2 = p2;
	point3 = p3;
	point4 = p4;
}
bool Choturukutnik::isNotCorrect() {
	double sumOfKut = Kut(point1, point2, point3) + Kut(point2, point3, point4) + Kut(point3, point4, point1) + Kut(point4, point1, point2);
	if (sumOfKut <= 360)
	{
		return false;
	}
	return true;
}
double Choturukutnik::perimetr() {
	return length(point1, point2) + length(point2, point3) + length(point3, point4) + length(point4, point1);
}




void SetPoint(int& x, int& y) {
	cout << "x: "; cin >> x;
	cout << "y: "; cin >> y;
}
vector<Point> SetPoints() {
	int x, y;
	vector<Point> res;
	for (int i = 0; i < 4; i++)
	{
		SetPoint(x, y);
		res.push_back(Point(x, y));
	}
	return res;
}
void ShowPerimetrOfChoturukutnik(vector<Choturukutnik>& arr) {
	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << i + 1 << ") " <<"S = " << arr[i].perimetr() << '\n';
	}
}
vector<Choturukutnik> initilising_Array(int size) {
	vector<Choturukutnik> res;
	for (int i = 0; i < size; i++)
	{
		while (true)
		{
			vector<Point> points = SetPoints();
			Choturukutnik temp(points[0], points[1], points[2], points[3]);
			if (temp.isNotCorrect())
			{
				cout << "FAIL! TRY AGAINE!!!\n";
			}
			else
			{
				res.push_back(temp);
				cout << "======================\n";
				break;
			}
		}
	}
	return res;
}
int indexOfMaxPerimetr(vector<Choturukutnik>& arr) {
	int res = 0;
	for (size_t i = 1; i < arr.size(); i++)
	{
		if (arr[i - 1].perimetr() < arr[i].perimetr()) {
			res = i;
		}
	}
	return res;
}