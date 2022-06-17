#include "Choturukutnik.h"

vector<Point> SetPoints() {
	int x, y;
	vector<Point> res;
	for (int i = 0; i < 4; i++)
	{
		cout << "x: "; cin >> x;
		cout << "y: "; cin >> y;
		res.push_back(Point(x, y));
	}
	return res;
}

vector<Choturukutnik> initilising_Array(int size) {
	vector<Choturukutnik> res;
	for (int i = 0; i < size; i++)
	{
		while (true)
		{
			vector<Point> points = SetPoints();
			Choturukutnik temp(points[0], points[1], points[2], points[3]);
			if (!temp.isCorrect())
			{
				cout << "FAIL! TRY AGAIN!!!\n";
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
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i - 1].perimetr() < arr[i].perimetr()) {
			res = i;
		}
	}
	return res;
}
