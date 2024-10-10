// BSEF21M033
// IMRAN JAVED
// SEF21
// SSDSA-Assignment 01(Stack Applications)

#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.h"
using namespace std;

template <typename T>
Stack<T>::Stack()
{
    data = nullptr;
    capacity = 0;
    top = 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& ref)
{
    if (ref.data == nullptr)
    {
        this->~Stack();
        return;
    }
    data = new T[ref.capacity];
    capacity = ref.capacity;
    top = ref.top;
    for (int i = 0; i < top; i++)
        data[i] = ref.data[i];
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& ref)
{
    if (this == &ref)
        return *this;
    this->~Stack();
    if (ref.data == nullptr)
    {
        this->~Stack();
        return *this;
    }
    data = new T[ref.capacity];
    capacity = ref.capacity;
    top = ref.top;
    for (int i = 0; i < top; i++)
        data[i] = ref.data[i];
    return *this;
}

template <typename T>
Stack<T>::~Stack()
{
    if (!data)
        return;
    delete[] data;
    data = nullptr;
    capacity = 0;
    top = 0;
}

template <typename T>
void Stack<T>::push(T val)
{
    if (isFull())
        grow(capacity == 0 ? 1 : capacity * 2);
    data[top++] = val;
}

template <typename T>
void Stack<T>::pop()
{
    if (isEmpty())
        // exit(0);
        throw "Stack is empty";

    top--;
    if (top > 0 && top == capacity / 4)
        shrink(capacity / 2);
}

template <typename T>
T Stack<T>::peek()
{
    if (isEmpty())
        // exit(0);
        throw "Stack is empty";

    return data[top - 1];
}

template <typename T>
bool Stack<T>::isEmpty()
{
    return top == 0;
}

template <typename T>
bool Stack<T>::isFull()
{
    return top == capacity;
}

template <typename T>
int Stack<T>::getCapacity()
{
    return capacity;
}

template <typename T>
int Stack<T>::getNumberOfElements()
{
    return top;
}

template <typename T>
void Stack<T>::grow(int newCap)
{
    T* temp = new T[newCap];
    for (int i = 0; i < top; i++)
        temp[i] = data[i];
    int tempTop = top;
    this->~Stack();
    data = temp;
    capacity = newCap;
    top = tempTop;
}

template <typename T>
void Stack<T>::shrink(int newCap)
{
    T* temp = new T[newCap];
    for (int i = 0; i < top; i++)
        temp[i] = data[i];
    int tempTop = top;
    this->~Stack();
    data = temp;
    capacity = newCap;
    top = tempTop;
}

#endif