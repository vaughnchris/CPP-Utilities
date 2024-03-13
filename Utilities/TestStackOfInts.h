#pragma once
#include "StackOfInts.h"
#include <iostream>
using namespace std;

void TestStackOfInts()
{
	Utilities::Containers::StackOfInts stackOfInts;
	for (int i = 0; i < 10; i++)
	{
		stackOfInts.Push(i);
	}	
	cout << stackOfInts.ToString() << endl;
	Utilities::Containers::StackOfInts stackOfInts2(stackOfInts);
	cout << "A copy of the original stack using the copy constructor:" << endl;	
	cout << stackOfInts2.ToString() << endl;
}
