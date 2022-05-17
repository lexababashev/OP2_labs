#include "Function.h"




char ChooseFilemode() {
    char res;
    do
    {
    cout << "click 1 to overwrite file or 2 to append it :"; cin >> res;
    } while (res!='1' && res != '2');

    return res;
}
void createFile(string name,char filemode) {
    ofstream File;
    if (filemode=='1')
    {
        File.open(name, ios::binary);
    }
    else {
        File.open(name, ios::binary | ios::app);
    }
    
    if (!File.is_open())
    {
        cout << "fail\n";
        return;
    }

    Product tovar;
    size_t amount;

    cout << "amount of product: "; cin >> amount; cout << endl;
    for (size_t i = 0; i < amount; i++) {
        cout << i + 1 << ") " << "name of product: "; cin >> tovar.name;
        
        cout << "   " << "date of release: ";
        string date;
        getline(cin, date, '.'); tovar.start.day = stoi(date);
        getline(cin, date, '.'); tovar.start.month = stoi(date);
        getline(cin, date); tovar.start.year = stoi(date);

        cout <<"   " << "date of expiration: ";
        getline(cin, date, '.'); tovar.end.day = stoi(date);
        getline(cin, date, '.'); tovar.end.month = stoi(date);
        getline(cin, date); tovar.end.year = stoi(date);

        File.write((char*)&tovar, sizeof(Product));
    }
    File.close();
}



bool isBad(Product tovar) {
    
    bool res = false;
    CTime current = CTime::GetCurrentTime();
    CTime end(tovar.end.year, tovar.end.month, tovar.end.day, 0, 0, 0);
    CTimeSpan diff = end - current;
    int days = diff.GetDays();
    if (days<0)
    {
        res = true;
    }
    return res;
}
bool SoonIsBad(Product tovar) {
    bool res = false;
    CTime start(tovar.start.year, tovar.start.month, tovar.start.day, 0, 0, 0);
    CTime end(tovar.end.year, tovar.end.month, tovar.end.day, 0, 0, 0);
    CTimeSpan diff = end - start;
    int days = diff.GetDays();
    if (days<=5)
    {
        res = true;
    }
    return res;
}
void NewFileSoon(string All, string nameSoon,char filemode) {
    ifstream FileAll(All, ios::binary);
    if (!FileAll.is_open())
    {
        cout << "fail\n";
        return;
    }
    ofstream FileSoon;
    if (filemode == '1')
    {
        FileSoon.open(nameSoon, ios::binary);
    }
    else {
        FileSoon.open(nameSoon, ios::binary | ios::app);
    }
    if (!FileSoon.is_open())
    {
        cout << "fail\n";
        return;
    }




    Product tovar;
    while (FileAll.read((char*)&tovar, sizeof(Product)))
    {
        if (SoonIsBad(tovar))
        {
            FileSoon.write((char*)&tovar, sizeof(Product));
        }
    }
    FileSoon.close();
    FileAll.close();
}


void NewFileLong(string All,string nameLong,char filemode) {
    ifstream FileAll(All, ios::binary);
    if (!FileAll.is_open())
    {
        cout << "fail\n";
        return;
    }
    ofstream FileLong;
    if (filemode == '1')
    {
        FileLong.open(nameLong, ios::binary);
    }
    else {
        FileLong.open(nameLong, ios::binary | ios::app);
    }
    if (!FileLong.is_open())
    {
        cout << "fail\n";
        return;
    }



    Product tovar;
    while (FileAll.read((char*)&tovar, sizeof(Product)))
    {
            if (!SoonIsBad(tovar))
            {
                FileLong.write((char*)&tovar, sizeof(Product));
            }
    }
    FileLong.close();
    FileAll.close();
}

void displayFile(string name) {
    ifstream File(name, ios::binary);
    Product tovar;
    if (!File.is_open())
    {
        cout << "fail\n";
        return;
    }
    cout << name << ':' << '\n';
    while (File.read((char*)&tovar, sizeof(Product))) {
        cout << tovar.name<<'\n';
    }
}

void deleteExpired(string name) {
    ifstream FileIn(name, ios::binary);
    vector <Product> buff;
    Product tovar;
    while (FileIn.read((char*)&tovar, sizeof(Product)))
    {
        if (isBad(tovar)==false) {
            buff.push_back(tovar);
        }
    }
    FileIn.close();

    ofstream FileOut(name, ios::binary);

    for (auto& buffered_tovar: buff)//size_t i = 0; i<buff.size();i++
    {
        FileOut.write((char*)&buffered_tovar, sizeof(Product)); //buff[i]
    }
    FileOut.close();
}