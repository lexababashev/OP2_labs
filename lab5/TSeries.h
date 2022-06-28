#pragma once

class TSeries
{
protected:
    int firstNumber;
    int step;
    TSeries(int firstMember, int step);


public:
    void SetFirstNumber(int firstNumber);
    void SetStep(int step);
    int GetStep();
    int GetFirstNumber();
    virtual int FindNElement(int n) = 0;
    virtual int Sum(int n) = 0;
};


