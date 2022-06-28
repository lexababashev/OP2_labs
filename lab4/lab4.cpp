#include "Functions.h"
#include <string>



int main()
{
	Line P1;
	cout << "1) 1x - 1y + 1 = 0" << '\n' << '\n';

	string sa, sb, sc; 
	double a, b, c;
	while (true) {
		try
		{
			cout << "a = "; cin >> sa; cout << "b = "; cin >> sb; cout << "c = "; cin >> sc;
			a = stod(sa);
			b = stod(sb);
			c = stod(sc);
			break;
		}
		catch (const std::exception&)
		{
			cout<<"Fail! Try againe!\n";
		}
	}

	//double a, b, c; cout << "a = "; cin >> a; cout << "b = "; cin >> b; cout << "c = "; cin >> c;
	Line P2(a, b, c);
	cout << "2) "<< a <<"x + "<<b << "y + " << c <<" = 0" << '\n';



	if (P1 || P2)
	{
		cout << "P1 and P2 is paralel" << '\n' << '\n';
	}
	else
	{
		cout << "P1 and P2 is NOT paralel" << '\n' << '\n';
	}


	
	Line P3(P1);
	cout << "3) 1x - 1y + 1 = 0" << '\n' << '\n';
	cout << "line3 degrees = " << P3.get_Degrees() << '\n';
	cout << "k = " << P3.get_k() << '\n' ;
	cout << "Ox: (" << P3.Ox() << ";0) " << " Oy: (0; " << P3.Oy() << ")" << '\n' << '\n';
	++P3;
	cout << "line3 degrees = " << P3.get_Degrees() << '\n';
	cout << "k = " << P3.get_k() << '\n' ;

	cout << "Ox: (" << P3.Ox() << ";0) " << " Oy: (0; " << P3.Oy() << ")" << '\n';

}

