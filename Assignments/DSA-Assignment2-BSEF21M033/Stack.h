// BSEF21M033
// IMRAN JAVED
// SEF21
// SSDSA-Assignment 01(Stack Applications)

#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
private:
    T* data;
    int capacity;
    int top;
    void grow(int);
    void shrink(int);

public:
    Stack();
    Stack(const Stack<T>&);
    Stack& operator=(const Stack<T>&);
    ~Stack();

    void push(T);
    void pop();
    T peek();
    bool isFull();
    bool isEmpty();
    int getCapacity();
    int getNumberOfElements();
};

#include "Stack.cpp"

#endif // !STACK_H