#include "Function.h"


int main()
{





	string nameAll = "All.txt";
	string nameSoon = "Soon.txt";
	string nameLong = "Long.txt";
	char filemode = ChooseFilemode();

	createFile(nameAll, filemode);
	displayFile(nameAll);

	NewFileSoon(nameAll, nameSoon, filemode);
	displayFile(nameSoon);

	NewFileLong(nameAll, nameLong, filemode);
	displayFile(nameLong);
	cout << "===============\n";
	deleteExpired(nameSoon);
	displayFile(nameSoon);
	deleteExpired(nameLong);
	displayFile(nameLong);

}


