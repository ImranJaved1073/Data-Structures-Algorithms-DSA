#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
private:
    T *data;
    int capacity;
    int top;
    void reSize(int);

public:
    Stack();
    Stack(const Stack<T> &);
    Stack &operator=(const Stack<T> &);
    ~Stack();

    void push(T);
    T pop();
    T stackTop();
    bool isFull();
    bool isEmpty();
    int getCapacity();
    int getNumberOfElements();
};

template <typename T>
Stack<T>::Stack()
{
    data = nullptr;
    capacity = 0;
    top = 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T> &ref)
{
    if (ref.data == nullptr)
    {
        data = nullptr;
        capacity = 0;
        top = 0;
        return;
    }
    data = new T[ref.capacity];
    capacity = ref.capacity;
    top = ref.top;
    for (int i = 0; i < top; i++)
        data[i] = ref.data[i];
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &ref)
{
    if (this == &ref)
        return *this;
    this->~Stack();
    if (ref.data == nullptr)
    {
        data = nullptr;
        capacity = 0;
        top = 0;
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
        reSize(capacity == 0 ? 1 : capacity * 2);
    data[top++] = val;
}

template <typename T>
T Stack<T>::pop()
{
    if (isEmpty())
        exit(0);
        //throw "Stack is empty";

    T val = data[--top];
    if (top > 0 && top == capacity / 4)
        reSize(capacity / 2);
    return val;
}

template <typename T>
T Stack<T>::stackTop()
{
    if (isEmpty())
        exit(0);
        //throw "Stack is empty";

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
void Stack<T>::reSize(int newSize)
{
    T *temp = new T[newSize];
    for (int i = 0; i < top; i++)
        temp[i] = data[i];
    int tempTop = top;
    this->~Stack();
    data = temp;
    capacity = newSize;
    top = tempTop;
}

#endif // !STACK_H