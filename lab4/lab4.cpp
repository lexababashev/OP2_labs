#include "Functions.h"




int main()
{
	Line line1;
	cout << "1) 1x - 1y + 0 = 0" << '\n';
	cout << "Oy: x = 0 "  << " y = " << line1.Ox() << " Ox: x = " << line1.Oy() << " y = 0 "  << '\n';

	int c1; cout << "c = "; cin >> c1;
	cout << "2) 1x + 1y + "<<c1<<" = 0" << '\n';
	Line line2(c1);
	cout << "Oy: x = 0 " << " y = " << line2.Ox() << " Ox: x = " << line2.Oy() << " y = 0 " << '\n';


	int a, b, c2; cout << "a = "; cin >> a; cout << "b = "; cin >> b; cout << "c = "; cin >> c2;
	cout << "2) "<< a <<"x + "<<b << "y + " << c2 <<" = 0" << '\n';
	Line line3(a, b ,c2);
	cout << "Oy: x = 0 " << " y = " << line3.Ox() << " Ox: x = " << line3.Oy() << " y = 0 " << '\n' << '\n';


	cout << "line3 degrees = " << line3.get_Degrees() << '\n';
	cout << "k = " << line3.get_k() << '\n';
	++line3;
	cout << "line3 degrees = " << line3.get_Degrees() << '\n';
	cout << "k = " << line3.get_k() << '\n' << '\n';



	if (line1 || line2)
	{
		cout << "1 and 2 is paralel" << '\n';
	}
	else if(line2 || line3)
	{
		cout << "2 and 3 is paralel" << '\n';
	}
	else if (line3 || line1)
	{
		cout << "3 and 1 is paralel" << '\n';
	}
	else
	{
		cout << "noone is paralel" << '\n';
	}
	


}

