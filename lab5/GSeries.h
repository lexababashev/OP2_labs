#pragma once
#include "TSeries.h"
#include <cmath>

class GSeries: protected TSeries {
public:
	GSeries(int firstNumber, int step);
	int FindNElement(int n);
	int Sum(int n);
};