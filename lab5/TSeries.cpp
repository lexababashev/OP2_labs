#include "TSeries.h"

TSeries::TSeries(int firstNumber = 1, int step = 1)
{
    this->firstNumber = firstNumber;
    this->step = step;
}

int TSeries::GetStep() {
    return step;
}

int TSeries::GetFirstNumber() {
    return firstNumber;
}

void TSeries::SetStep(int step)
{
    this->step = step;
}

void TSeries::SetFirstNumber(int firstNumber)
{
    this->firstNumber = firstNumber;
}

