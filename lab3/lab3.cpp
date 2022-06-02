#include "Choturukutnik.h"
int main()
{
	int size;
	cout << "Enter amount of chotirikutnik: "; cin >> size;
	
	cout << "Enter clockwise or counter-clockwise coordinates!\n";

	vector<Choturukutnik> MyArr = initilising_Array(size);
	ShowPerimetrOfChoturukutnik(MyArr);

	int maxPerIndex = indexOfMaxPerimetr(MyArr);
	
	cout << "The biggest perimetr is in " << maxPerIndex + 1 << " choturukutnik";
	return 1;
}

