#include "Choturukutnik.h"
#include "Functions.h"


int main()
{
	int size;
	cout << "Enter amount of chotirikutnik: "; cin >> size;

	cout << "Enter clockwise or counter-clockwise coordinates!\n";

	vector<Choturukutnik> MyArr = initilising_Array(size);

	for (int i = 0; i < MyArr.size(); i++)
	{
		cout<<"S = "<<MyArr[i].perimetr()<<'\n';
	}
	

	int maxPerIndex = indexOfMaxPerimetr(MyArr);

	cout << "The biggest perimetr is in " << maxPerIndex + 1 << " choturukutnik";
	return 1;
}

