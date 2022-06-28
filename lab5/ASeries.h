#pragma once
#include "TSeries.h"
class ASeries: protected TSeries {
public:
	ASeries(int firstNumber, int step);
	int FindNElement(int n);
	int Sum(int n);
};