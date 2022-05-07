#include "Function.h"

int main()
{
	string oldPath = "old.txt";
	string newPath = "new.txt";
	CreateFile(oldPath);
	CreateNewFile(oldPath, newPath);
	cout << "OLD: \n";
	outputFile(oldPath);
	cout << "NEW: \n";
	outputFile(newPath);
	return 0;
}

