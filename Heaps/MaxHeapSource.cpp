#include <iostream>
#include "MaxHeap.h"
using namespace std;

template<class T>
void heapSort(MaxHeap<T>* heap)
{
	int n = heap->getSize();
	T * arr = new T[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = heap->remove();
	}
	for (int i = n-1; i >= 0; i--)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;
	arr = nullptr;
}

template <class T>
void buidHeap(T* array, int n)
{
	MaxHeap<T> heap(n);
	for (int i = 0; i < n; i++)
	{
		heap.insert(array[i]);
	}
	heap.display();
	heapSort(&heap);
}

int main()
{
	int arr[] = { 25, 17, 20, 6, 10, 11, 15, 2, 3, 30 };
	buidHeap(arr, 10);
}