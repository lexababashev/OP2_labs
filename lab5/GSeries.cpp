#include "GSeries.h"

GSeries::GSeries(int firstNumber, int step) 
	:TSeries(firstNumber, step)
{
}

int GSeries::FindNElement(int n)
{
	return firstNumber * (int)pow(step, n - 1);
}

int GSeries::Sum(int n)
{
	return firstNumber * (int)(pow(step, n) - 1) / (step - 1);
}