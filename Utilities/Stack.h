#pragma once
/*
* Stack.h
* Author: Christopher Vaughn
* Created on: 3/6/24
* Purpose: Create a stack data structure using a linked list.
* Hard coded to use integers. 
*/
#include "CollectionBase.h"
namespace Utilities::Containers
	{
		class Stack : public CollectionBase
		{
		public:
			struct Node
			{
				int data;
				Node* next;
			};
			Stack();
			Stack(int* arr, int size);
			Stack(const Stack& orig);
			~Stack();
			void Push(int value);
			int Pop();
			int Peek();
			bool IsEmpty();
			int Count();
			void Clear();
			std::string ToString();
			void Print();
			int operator[](int index);
			Stack& operator=(const Stack& other);
			Stack operator+(const Stack& other);
			bool operator==(const Stack& other);
			bool operator!=(const Stack& other);
			Stack operator+=(const Stack& other);
		protected:
			Node* head;
		};
	};