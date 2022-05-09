#include "Function.h"

void CreateFile(string name) {
	ofstream inFile;
	cout << "If you want to enter text in cleaned file enter 1, if you don't enter anything\n";
	char mode;
	cin >> mode;
	if (mode == '1') {
		inFile.open(name);
	}
	else {
		inFile.open(name, ios::app);
	}
	if (!inFile.is_open()) {
		cout << "File has not been opened\n";
	}
	else {
		cout << "Enter text\nTo end the input press Ctrl+X\n";
		cin.ignore();
		while (true)
		{
			
			string line;
			getline(cin, line);

			if (char(line[0]) == 24)
			{
				break;
			}
			inFile << line << '\n';
		}
	}
	inFile.close();
}
void outputFile(string name) {
	ifstream inFile;
	inFile.open(name);
	if (!inFile.is_open()) {
		cout << "File has not been opened\n";
	}
	else {
		while (!inFile.eof()) {
			string textLine;
			getline(inFile, textLine);
			cout << textLine << endl;
		}
		inFile.close();
	}
}
string transform(string line) {
	return line.substr(1, line.length() / 2) + "!" + line.substr(line.length() / 2 + 1);
}
void CreateNewFile(string oldName, string newName) {
	ifstream oldFile;
	ofstream newFile;
	oldFile.open(oldName);
	newFile.open(newName);
	if (!oldFile.is_open() || !newFile.is_open()) {
		cout << "File has not been opened\n";
	}
	else {
		string norm;
		string buffer;
		while (!oldFile.eof()) {
			string temp;
			getline(oldFile, temp);
			

				if (temp[0] == '#') {
					temp = transform(temp);
					buffer += temp += '\n';
				}
				else {
					norm += temp += '\n';
				}
		}
		norm = norm.substr(0, norm.size() - 1);
		newFile << norm << buffer;
	}
	oldFile.close();
	newFile.close();
}