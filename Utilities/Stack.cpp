#pragma once
#include "Stack.h"
using namespace Utilities;
using namespace Containers;
//constructor and destructor
Stack::Stack()
{
	head = nullptr;
}
Stack::Stack(int* arr, int size)
{
	head = nullptr;
	for (int i = 0; i < size; i++)
	{
		Push(arr[i]);
	}
}
Stack::Stack(const Stack& orig)
{
	head = nullptr;
	Node* temp = orig.head;
	while (temp != nullptr)
	{
		Push(temp->data);
		temp = temp->next;
	}
}
Stack::~Stack()
{
		Clear();
}
//methods
void Stack::Push(int value)
{
	Node* newNode = new Node();
	newNode->data = value;
	newNode->next = head;
	head = newNode;
	count++;
}
int Stack::Pop()
{
	if (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		int value = temp->data;
		delete temp;
		count--;
		return value;
	}
	else
	{
		return -1;
	}
}
int Stack::Peek()
{
	if (head != nullptr)
	{
		return head->data;
	}
	else
	{
		return -1;
	}
}
bool Stack::IsEmpty()
{
	if (head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int Stack::Count()
{
	return count;
}
void Stack::Clear()
{
	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		count--;
	}
}
std::string Utilities::Containers::Stack::ToString()
{
	return "";
}
void Utilities::Containers::Stack::Print()
{
	//not implemented at this level
}
//operator overloads
int Stack::operator[](int index)
{
	Node* temp = head;
	for (int i = 0; i < index; i++)
	{
		if (temp != nullptr)
		{
			temp = temp->next;
		}
		else
		{
			return -1;
		}
	}
	return temp->data;
}
Stack& Stack::operator=(const Stack& other)
{
	Clear();
	Node* temp = other.head;
	while (temp != nullptr)
	{
		Push(temp->data);
		temp = temp->next;
	}
	count = 0;
	return *this;
}
Stack Stack::operator+(const Stack& other)
{
	Stack newStack;
	Node* temp = head;
	while (temp != nullptr)
	{
		newStack.Push(temp->data);
		temp = temp->next;
	}
	temp = other.head;
	while (temp != nullptr)
	{
		newStack.Push(temp->data);
		temp = temp->next;
	}
	return newStack;
}
bool Stack::operator==(const Stack& other)
{
	//compare the two stacks contents for equity
	Node *temp1 = head;
	Node *temp2 = other.head;
	while (temp1 != nullptr && temp2 != nullptr)
	{
		if (temp1->data != temp2->data)
		{
			return false;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
}
bool Stack::operator!=(const Stack& other)
{
	return !(*this == other);
}
Stack Stack::operator+=(const Stack& other)
{
	Node* temp = other.head;
	while (temp != nullptr)
	{
		Push(temp->data);
		temp = temp->next;
	}
	return *this;
}
