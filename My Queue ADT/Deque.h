#ifndef DEQUE_H
#define DEQUE_H

template <typename T>
class Deque
{
private:
    T *data;
    int capacity, front, rear, noOfElements;
    void reSize(int newSize);

public:
    Deque();
    Deque(const Deque<T> &);
    Deque<T> &operator=(const Deque<T> &);
    ~Deque();
    void insertAtTail(T);
    void insertAtHead(T);
    T deleteAtHead();
    T deleteAtTail();
    bool isEmpty() const;
    bool isFull() const;
    int getCapacity() const;
    int getNoOfElements() const;
};

template <typename T>
Deque<T>::Deque()
{
    data = nullptr;
    capacity = front = rear = noOfElements = 0;
}

template <typename T>
Deque<T>::Deque(const Deque<T> &ref)
{
    if (ref.data == nullptr)
    {
        data = nullptr;
        capacity = front = rear = noOfElements = 0;
        return;
    }
    data = new T[ref.capacity];
    capacity = ref.capacity;
    front = 0;
    rear = ref.noOfElements - 1;
    noOfElements = ref.noOfElements;
    int j = ref.front;
    for (int i = 0; i < noOfElements; i++)
    {
        data[i] = ref.data[j];
        j = (j + 1) % capacity;
    }
}

template <typename T>
Deque<T> &Deque<T>::operator=(const Deque<T> &ref)
{
    if (this == &ref)
        return *this;
    this->~Deque();
    if (ref.data == nullptr)
    {
        data = nullptr;
        capacity = front = rear = noOfElements = 0;
        return *this;
    }
    data = new T[ref.capacity];
    capacity = ref.capacity;
    front = 0;
    rear = ref.noOfElements;
    noOfElements = ref.noOfElements;
    int j = ref.front;
    for (int i = 0; i < noOfElements; i++)
    {
        data[i] = ref.data[j];
        j = (j + 1) % capacity;
    }
    return *this;
}

template <typename T>
Deque<T>::~Deque()
{
    if (!data)
        return;
    data = nullptr;
    capacity = front = rear = noOfElements = 0;
}

template <typename T>
bool Deque<T>::isEmpty() const
{
    return noOfElements == 0;
}

template <typename T>
bool Deque<T>::isFull() const
{
    return noOfElements == capacity;
}

template <typename T>
int Deque<T>::getCapacity() const
{
    return capacity;
}

template <typename T>
int Deque<T>::getNoOfElements() const
{
    return noOfElements;
}

template <typename T>
void Deque<T>::insertAtHead(T element)
{
    if (isFull())
        reSize(capacity == 0 ? 1 : capacity * 2);

    front = (front - 1 + capacity) % capacity;
    data[front] = element;
    noOfElements++;
}

template <typename T>
void Deque<T>::insertAtTail(T element)
{
    if (isFull())
        reSize(capacity == 0 ? 1 : capacity * 2);

    data[rear] = element;
    rear = (rear + 1) % capacity;
    noOfElements++;
}

template <typename T>
T Deque<T>::deleteAtHead()
{
    if (isEmpty())
        exit(0);
    T temp = data[front];
    front = (front + 1) % capacity;
    noOfElements--;
    if (noOfElements == capacity / 4)
        reSize(capacity / 2);
    return temp;
}

template <typename T>
T Deque<T>::deleteAtTail()
{
    if (isEmpty())
        exit(0);
    T temp = data[rear - 1];
    rear = (rear - 1) % capacity;
    noOfElements--;
    if (noOfElements == capacity / 4)
        reSize(capacity / 2);
    return temp;
}

template <typename T>
void Deque<T>::reSize(int newSize)
{
    T *temp = new T[newSize];
    int j = front;
    for (int i = 0; i < noOfElements; i++)
    {
        temp[i] = data[j];
        j = (j + 1) % capacity;
    }
    front = 0;
    rear = noOfElements;
    capacity = newSize;
    delete[] data;
    data = temp;
}

#endif