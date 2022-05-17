#pragma once
#include <iostream>
#include<vector>
#include<string>
#include<fstream>
#include "Product.h"
#include<atltime.h>


using namespace std;



void createFile(string name,char filemode);
char ChooseFilemode();
void NewFileSoon(string All, string nameSoon,char filemode);
void NewFileLong(string All, string nameLong,char filemode);
bool isBad(Product tovar);
bool SoonIsBad(Product tovar);
void displayFile(string name);
void deleteExpired(string name);