#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue
{
private:
    T* data;
    int capacity, front, rear, noOfElements;
    void reSize(int newSize);

public:
    Queue();
    Queue(const Queue<T>&);
    Queue<T>& operator=(const Queue<T>&);
    ~Queue();
    void enQueue(T);
    T deQueue();
    T getElementAtFront() const;
    bool isEmpty() const;
    bool isFull() const;
    int getCapacity() const;
    int getNoOfElements() const;
    bool search(const T& element) const;
};

template <typename T>
Queue<T>::Queue()
{
    data = nullptr;
    capacity = front = rear = noOfElements = 0;
}

template <typename T>
Queue<T>::Queue(const Queue<T>& ref)
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
Queue<T>& Queue<T>::operator=(const Queue<T>& ref)
{
    if (this == &ref)
        return *this;
    this->~Queue();
    if (ref.data == nullptr)
    {
        data = nullptr;
        capacity = front = rear = noOfElements = 0;
        return *this;
    }
    data = new T[ref.capacity];
    capacity = ref.capacity;
    noOfElements = ref.noOfElements;
    front = 0;
    rear = noOfElements - 1;
    int j = ref.front;
    for (int i = 0; i < noOfElements; i++)
    {
        data[i] = ref.data[j];
        j = (j + 1) % capacity;
    }
    return *this;
}

template <typename T>
Queue<T>::~Queue()
{
    if (!data)
        return;
    data = nullptr;
    capacity = front = rear = noOfElements = 0;
}

template <typename T>
bool Queue<T>::isEmpty() const
{
    return noOfElements == 0;
}

template <typename T>
bool Queue<T>::isFull() const
{
    return noOfElements == capacity;
}

template <typename T>
int Queue<T>::getCapacity() const
{
    return capacity;
}

template <typename T>
int Queue<T>::getNoOfElements() const
{
    return noOfElements;
}

template <typename T>
void Queue<T>::enQueue(T element)
{
    if (isFull())
        reSize(capacity == 0 ? 1 : capacity * 2);

    data[rear] = element;
    rear = (rear + 1) % capacity;
    noOfElements++;
}

template <typename T>
T Queue<T>::deQueue()
{
    if (isEmpty())
        exit(0);
    // throw "Queue is empty";
    T temp = data[front];
    front = (front + 1) % capacity;
    noOfElements--;
    if (noOfElements == capacity / 4)
        reSize(capacity / 2);
    return temp;
}

template <typename T>
T Queue<T>::getElementAtFront() const
{
    if (isEmpty())
        exit(0);
    return data[front];
}

template <typename T>
void Queue<T>::reSize(int newSize)
{
    T* temp = new T[newSize];
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

template <typename T>
bool Queue<T>::search(const T& element) const
{
	if (isEmpty())
		return false;
	int j = front;
    for (int i = 0; i < noOfElements; i++)
    {
		if (data[j] == element)
			return true;
		j = (j + 1) % capacity;
	}
	return false;
}

#endif