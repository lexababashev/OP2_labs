#include "ASeries.h"

ASeries::ASeries(int firstNumber, int step)
		:TSeries(firstNumber, step)
{
}

int ASeries::Sum(int n)
{
	return (2 * firstNumber + step * (n - 1) * n) / 2;
}

int ASeries::FindNElement(int n) {
	return firstNumber + step * (n - 1);
}

