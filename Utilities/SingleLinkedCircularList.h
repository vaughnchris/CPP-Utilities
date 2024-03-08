//
// Created by Christopher Vaughn on 3/5/24.
//

#ifndef POINTERS_CIRCULARLIST_H
#define POINTERS_CIRCULARLIST_H
#include <stack>
#include <string>
#include <iostream>
#include <stack>
using namespace std;
namespace Utilities 
{
    namespace Containers
    {
        // create a node class
        class CircularList {
        public:
            struct Node {
                int data;
                Node* next = nullptr;
            };
            //default constructor
            CircularList() = default;
            //overloaded constructor
            // that takes an array of integers
            // and the size of the array
            CircularList(int* data, int size) {
                for (int i = 0; i < size; i++) {
                    Push(data[i]);
                }
            }
            //copy constructor
            CircularList(const CircularList& other) {
                Node* temp = other.head;
                for (int i = 0; i < other.count; i++) {
                    Push(temp->data);
                    temp = temp->next;
                }
            }
            //destructor
            ~CircularList() {
                Clear();
            }
            void Push(int data) {
                Node* newNode = new Node;   // create a new node
                newNode->data = data; // set the data
                Node* temp = head;
                // if the list is empty
                if (temp == nullptr) {
                    // set the head to the new node
                    head = newNode;
                    // set the tail to the new node
                    newNode->next = head;
                    tail = newNode;
                }
                else {
                    // otherwise, find the end of the
                    // list and add the new node
                    tail->next = newNode;
                    // set the new nodes next pointing
                    // to the head
                    newNode->next = head;
                    // set the new node to the tail
                    tail = newNode;
                }
                // increment the count
                count++;
            }
            int Pop() {
                // if the list is empty
                if (head == nullptr)
                    return -1;
                // set the data to the head
                int data = head->data;
                // set the temp to the head
                Node* temp = head;
                // set the head to the next node
                head = head->next;
                // delete the temp
                delete temp;
                // decrement the count
                count--;
                // return the data
                return data;
            }
            int Dequeue() {
                // if the list is empty
                if (head == nullptr)
                    return -1;
                // set the temp to the head
                Node* temp = head;
                // set the head to the next node
                head = head->next;
                // set the tail to the head
                tail->next = head;
                // set the data to the temp
                int data = temp->data;
                // delete the temp
                delete temp;
                // decrement the count
                count--;
                // return the data
                return data;
            }
            void RemoveAt(int index)
            {
                if (index < this->count) {
                    // if the index is 0
                    if (index == 0) {
                        // set the head to the next node
                        Node* temp = head;
                        head = head->next;
                        delete temp;
                        count--;
                        return;
                    }
                    // set the temp to the head
                    Node* temp = head;
                    // set the prev to the head
                    Node* prev = head;
                    // loop through the list
                    for (int i = 0; i < index; i++) {
                        // set the prev to the temp
                        prev = temp;
                        // set the temp to the next node
                        temp = temp->next;
                    }
                    // set the prev to the next node
                    prev->next = temp->next;
                    // delete the temp
                    delete temp;
                    // decrement the count
                    count--;
                }
            }
            void RemoveAt(int* indexes, int size)
            {
                for (int i = 0; i < size; i++)
                    RemoveAt(indexes[i]);
            }
            void ReplaceAt(int index, int data) {
                if (index < this->count) {
                    // set the temp to the head
                    Node* temp = head;
                    // loop through the list
                    for (int i = 0; i < index; i++) {
                        // set the temp to the next node
                        temp = temp->next;
                    }
                    // set the data to the temp
                    temp->data = data;
                }
            }
            void ReplaceAt(int* indexes, int size, int data) {
                for (int i = 0; i < size; i++)
                    ReplaceAt(indexes[i], data);
            }
            void Replace(int oldData, int newData) {
                Node* temp = head;
                for (int i = 0; i < this->count; i++) {
                    if (temp->data == oldData)
                        temp->data = newData;
                    temp = temp->next;
                }
            }
            int Peek() {
                if (head == nullptr)
                    return -1;
                return head->data;
            }
            void Copy(CircularList& other) {
                Node* temp = other.head;
                for (int i = 0; i < other.count; i++) {
                    Push(temp->data);
                    temp = temp->next;
                }
            }
            int Count() {
                return this->count;
            }
            void Clear() {
                // set the temp to the head
                Node* temp = head;
                // while the temp is not null
                for (int i = 0; i < this->count; i++) {
                    // set the head to the next node
                    head = head->next;
                    // delete the temp
                    delete temp;
                    // set the temp to the head
                    temp = head;
                }
                // set the head to null
                head = nullptr;
                // set the tail to null
                tail = nullptr;
                // set the count to 0
                count = 0;
            }
            int Sum() {
                int sum = 0;
                Node* temp = head;
                Node* start = head;
                for (int i = 0; i < this->count; i++) {
                    sum += temp->data;
                    temp = temp->next;
                }
                return sum;
            }
            float Average() {
                int sum = 0;
                Node* temp = head;
                for (int i = 0; i < this->count; i++) {
                    sum += temp->data;
                    temp = temp->next;
                }
                return sum / this->count;
            }
            int Max() {
                int max = head->data;
                Node* temp = head;
                for (int i = 0; i < this->count; i++) {
                    if (temp->data > max)
                        max = temp->data;
                    temp = temp->next;
                }
                return max;
            }
            int Min() {
                int min = head->data;
                Node* temp = head;
                for (int i = 0; i < this->count; i++) {
                    if (temp->data < min)
                        min = temp->data;
                    temp = temp->next;
                }
                return min;
            }
            int Find(int data) {
                int index = 0;
                Node* temp = head;
                for (int i = 0; i < this->count; i++) {
                    if (temp->data == data)
                        return index;
                    temp = temp->next;
                    index++;
                }
                return -1;
            }
            int* FindAll(int data) {
                stack <int> indexes;
                Node* temp = head;
                for (int i = 0; i < this->count; i++) {
                    if (temp->data == data) {
                        indexes.push(i);
                    }
                    temp = temp->next;
                }
                int* output = new int[indexes.size()];
                int stop = indexes.size();
                for (int i = 0; i < stop; i++) {
                    output[i] = indexes.top();
                    indexes.pop();
                }
                return output;
            }
            void TrimFront(int n) {
                for (int i = 0; i < n; i++) {
                    Pop();
                }
            }
            void TrimBack(int n) {
                for (int i = 0; i < n; i++) {
                    Node* temp = head;
                    while (temp->next != tail) {
                        temp = temp->next;
                    }
                    delete tail;
                    tail = temp;
                    tail->next = head;
                    count--;
                }
            }
            void Print() {
                Node* temp = head;
                for (int i = 0; i < this->count; i++) {
                    std::cout << temp->data << " ";
                    temp = temp->next;
                }
                cout << "\n====================\n";
                cout << "Item Count: " << Count() << endl;
                cout << "Sum: " << Sum() << endl;
                cout << "Average: " << Average() << endl;
                cout << "Minimum: " << Min() << endl;
                cout << "Maximum: " << Max() << endl;
                cout << "====================\n\n";
                std::cout << std::endl;
            }
            string ToString() {
                string str = "";
                Node* temp = head;
                for (int i = 0; i < this->count; i++) {
                    str += to_string(temp->data) + ", ";
                    temp = temp->next;
                }
                return str;
            }
            ////////////Operator Overloads////////////////////////
            //overload the [] operator to return the data
            int operator[](int index) {
                Node* temp = head;
                for (int i = 0; i < index; i++) {
                    temp = temp->next;
                }
                return temp->data;
            }
            bool operator==(const CircularList& other) {
                Node* temp = head;
                Node* temp2 = other.head;
                while (temp != nullptr && temp2 != nullptr) {
                    if (temp->data != temp2->data)
                        return false;
                    temp = temp->next;
                    temp2 = temp2->next;
                }
                return true;
            }
            bool operator!=(const CircularList& other) {
                return !(*this == other);
            }

            CircularList& operator+(const CircularList& other) {
                CircularList* newList = new CircularList;
                Node* temp = head;
                for (int i = 0; i < this->count; i++) {
                    newList->Push(temp->data);
                    temp = temp->next;
                }
                temp = other.head;
                for (int i = 0; i < other.count; i++) {
                    newList->Push(temp->data);
                    temp = temp->next;
                }
                return *newList;
            }
            //Add two stacks together
            //by adding the items from other
            CircularList& operator+=(const int value) {
                Node* temp = head;
                for (int i = 0; i < count; i++) {
                    temp->data += value;
                    temp = temp->next;
                }
                return *this;
            }
            CircularList& operator++() {
                Node* temp = head;
                for (int i = 0; i < this->count; i++) {
                    temp->data++;
                    temp = temp->next;
                }
                return *this;
            }
            CircularList& operator-=(int value) {
                CircularList* newList = new CircularList(*this);
                Node* temp = head;
                for (int i = 0; i < this->count; i++) {
                    temp->data -= value;
                    temp = temp->next;
                }
                return *newList;
            };
            CircularList& operator--() {
                Node* temp = head;
                for (int i = 0; i < this->count; i++) {
                    temp->data--;
                    temp = temp->next;
                }
                return *this;
            }
        private:
            int count = 0;
            Node* head = nullptr;
            Node* tail = nullptr;
        };
    };
};
#endif //POINTERS_CIRCULARLIST_H


