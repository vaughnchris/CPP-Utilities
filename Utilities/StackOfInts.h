#pragma once
#include "Stack.h"
namespace Utilities::Containers
{
class StackOfInts :
    public Stack
{
public:
    void MAX_VALUE(int value);
    int Sum();
    int Max();
    int Min();
    int Average();
    int Mode();
    int Range(int min);
    int Variance();
    int StandardDeviation();
    std::string ToString();
    void Print();

   
private:
    int INT_MAX_VAL = 100;
};
}


