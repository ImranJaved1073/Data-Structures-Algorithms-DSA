#ifndef RandomizedQueue_H
#define RandomizedQueue_H

#include "GenericArray.h"

template <typename T>
class RandomizedQueue
{

private:
    GenericArray<T> data;
    int rear;
    void reSize(int newSize)
    {
        if (newSize < 0)
            return;
        GenericArray<T> temp(newSize);
        for (int i = 0; i < rear; i++)
            temp[i] = data[i];
        data = temp;
    }

public:
    class Iterator;
    RandomizedQueue();
    void enQueue(T);
    T deQueue();
    T getElementAtFront() const;
    bool isEmpty() const;
    bool isFull() const;
    int getNoOfElements() const;
    T sample() const;
};

template <typename T>
RandomizedQueue<T>::RandomizedQueue()
{
    rear = 0;
}

template <typename T>
int RandomizedQueue<T>::getNoOfElements() const
{
    return rear;
}

template <typename T>
bool RandomizedQueue<T>::isEmpty() const
{
    return rear == 0;
}

template <typename T>
bool RandomizedQueue<T>::isFull() const
{
    return rear == data.getCapacity();
}

template <typename T>
T RandomizedQueue<T>::getElementAtFront() const
{
    if (isEmpty())
        exit(0);
    return data[0];
}

template <typename T>
void RandomizedQueue<T>::enQueue(T element)
{
    if (isFull())
        data.reSize(data.getCapacity() == 0 ? 1 : data.getCapacity() * 2);

    data[rear] = element;
    rear++;
}

template <typename T>
T RandomizedQueue<T>::deQueue()
{
    if (isEmpty())
        exit(0);
    int random = rand() % rear;
    T temp = data[random];
    data[random] = data[rear - 1];
    rear--;
    if (rear == data.getCapacity() / 4)
        data.reSize(data.getCapacity() / 2);
    return temp;
}

template <typename T>
T RandomizedQueue<T>::sample() const
{
    if (isEmpty())
        exit(0);
    return data[rand() % rear];
}

template <typename T>
class RandomizedQueue<T>::Iterator
{
private:
    GenericArray<T> localizedData;
    int rear, index;
    int randomInteger(int l, int u)
    {
        return l + rand() % (u - l + 1);
    }
    void swap(T &a, T &b)
    {
        T temp = a;
        a = b;
        b = temp;
    }
    void shuffle()
    {
        for (int i = 0; i < rear; i++)
            swap(localizedData[i], localizedData[randomInteger(i, rear - 1)]);
    }

public:
    Iterator(RandomizedQueue<T> &queue)
    {
        rear = queue.rear;
        localizedData = queue.data;
        shuffle();
        index = 0;
    }

    bool hasNext()
    {
        return index < rear;
    }

    T &operator*()
    {
        if (index >= rear)
            exit(0);
        return localizedData[index];
    }

    void operator++()
    {
        if (index >= rear)
            exit(0);
        index++;
    }

    void reset()
    {
        index = 0;
        shuffle();
    }
};

#endif
