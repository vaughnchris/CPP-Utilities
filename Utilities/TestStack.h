#pragma once 
#include <iostream>
#include "Stack.h"

using namespace Utilities::Containers;
using namespace std;
void TestStack()
{
	//write some tests here
	Stack s;
	s.Push(5);
	s.Push(10);
	s.Push(15);
	cout << "Size: " << s.Count() << endl;
	cout << "Peek: " << s.Peek() << endl;
	cout << "Pop: " << s.Pop() << endl;
	cout << "Size: " << s.Count() << endl;
	cout << "Peek: " << s.Peek() << endl;
	Stack s2(s);
	cout << "Size of second stack: " << s2.Count() << endl;
	cout << "Peek from second stack: " << s2.Peek() << endl;
	cout << "Pop from second stack: " << s2.Pop() << endl;
	cout << "Size of second stack: " << s2.Count() << endl;
	cout << "Peek from second stack: " << s2.Peek() << endl;
	Stack s3 = s + s2;
	cout << "Size of third stack: " << s3.Count() << endl;
	cout << "Peek from third stack: " << s3.Peek() << endl;
	cout << "Pop from third stack: " << s3.Pop() << endl;
	cout << "Size of third stack: " << s3.Count() << endl;
	cout << "Third stack contents:" << endl;
	for (int i = 0; i < s3.Count(); i++)
	{
		cout << "Value at:" << i << " " << s3[i] << endl;
	}
}