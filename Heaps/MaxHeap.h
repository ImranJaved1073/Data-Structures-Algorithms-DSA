#ifndef MAXHEAP_H
#define MAXHEAP_H


#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

template <class T>
class MaxHeap
{
	T* arr;
	int curSize;
	int maxSize;
	void swap(T&, T&);
	int getLeftChild(T i) { return 2 * i + 1; }
	int getRightChild(T i) { return 2 * i + 2; }
	int getParent(T i) { return (i - 1) / 2; }
	void heapifyup(int idx)
	{
		while (idx && arr[getParent(idx)] < arr[idx])
		{
			swap(arr[idx], arr[getParent(idx)]);
			idx = getParent(idx);
		}
	}
	void heapifydown(int idx)
	{
		int left = getLeftChild(idx);
		int right = getRightChild(idx);
		int largest = idx;
		if (left < curSize && arr[left] > arr[idx])
			largest = left;
		if (right < curSize && arr[right] > arr[largest])
			largest = right;
		if (largest != idx)
		{
			swap(arr[idx], arr[largest]);
			heapifydown(largest);
		}
	}
public:
	MaxHeap(int height); //Constructor
	~MaxHeap(); //Destructor
	bool isEmpty(); //Checks whether the heap is empty or not
	bool isFull(); //Checks whether the heap is full or not
	void insert(T val); // This function should insert val in the MaxHeap.
	T remove(); // This function should remove and return the max node from the MaxHeap.
	void display(); // This function displays the maxHeap in level order traversal as shown below.
	int getSize() { return curSize; }


};

template<class T>
void MaxHeap<T>::swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
MaxHeap<T>::MaxHeap(int height)
{
	maxSize = pow(2, height) - 1;
	arr = new T[maxSize];
	curSize = 0;
}

template <typename T>
MaxHeap<T>::~MaxHeap()
{
	if (arr)
		delete[] arr;
	arr = nullptr;
}

template <class T>
bool MaxHeap<T>::isEmpty()
{
	return curSize == 0;
}

template <class T>
bool MaxHeap<T>::isFull()
{
	return curSize == maxSize;
}

template <class T>
void MaxHeap<T>::insert(T val)
{
	arr[curSize] = val;
	int currIdx = curSize;
	while (currIdx)
	{
		if (arr[currIdx] > arr[getParent(currIdx)])
		{
			swap(arr[currIdx], arr[getParent(currIdx)]);
			currIdx = getParent(currIdx);
		}
		else currIdx = 0;
	}
	curSize++;
}

template <class T>
T MaxHeap<T>::remove()
{
	T removed = arr[0];
	swap(arr[0], arr[curSize - 1]);
	curSize--;
	T parIdx = 0;
	while (parIdx <= curSize)
	{
		if (arr[getLeftChild(parIdx)] > arr[getRightChild(parIdx)])
		{
			if (arr[parIdx] < arr[getLeftChild(parIdx)])
			{
				swap(arr[getLeftChild(parIdx)], arr[parIdx]);
				parIdx = getLeftChild(parIdx);
			}
			else parIdx = maxSize + 1;
		}
		else
		{
			if (arr[parIdx] < arr[getRightChild(parIdx)])
			{
				swap(arr[getRightChild(parIdx)], arr[parIdx]);
				parIdx = getRightChild(parIdx);
			}
			else parIdx = maxSize + 1;
		}
	}
	return removed;
}


template <class T>
void MaxHeap<T>::display()
{
	if (isEmpty())
		return;

	for (int i = 0; i < curSize; i++)
	{
		cout << arr[i] << ":";
	}
	cout << endl;
}

#endif // !MAXHEAP_H







