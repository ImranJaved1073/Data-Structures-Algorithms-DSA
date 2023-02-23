#ifndef GENERICARRAY_H
#define GENERICARRAY_H

#include <iostream>

using namespace std;

template <typename T>
class GenericArray
{
	T* data;
	int capacity;
	bool isValidIndex(int index) const
	{
		return index >= 0 && index < capacity;
	}

public:

	GenericArray();
	GenericArray(int size);
	~GenericArray();
	GenericArray(const GenericArray<T>& ref);

	GenericArray<T>& operator=(const GenericArray<T>& ref);
	T& operator[](int index);
	const T& operator[](int index) const;
	int getCapacity() const;
	void reSize(int newCap);
};

template <typename T>
GenericArray<T>::GenericArray()
{
	this->capacity = 0;
	data = nullptr;
}

template <typename T>
GenericArray<T>::GenericArray(int size) :GenericArray()
{
	if (size < 0)
		return;
	this->capacity = size;
	data = new T[capacity];
}

template <typename T>
GenericArray<T>::~GenericArray()
{
	if (data != nullptr)
		delete[] data;
	data = nullptr;
	capacity = 0;
}

template <typename T>
GenericArray<T>::GenericArray(const GenericArray<T>& ref)
{
	if (ref.data == nullptr)
	{
		this->capacity = 0;
		data = nullptr;
		return;
	}
	this->capacity = ref.capacity;
	data = new T[capacity];
	for (int i = 0; i < capacity; i++)
		data[i] = ref.data[i];
}

template <typename T>
GenericArray<T>& GenericArray<T>::operator=(const GenericArray<T>& ref)
{
	if (this == &ref)
		return *this;

	this->~GenericArray();
	if (ref.data == nullptr)
	{
		this->capacity = 0;
		data = nullptr;
		return *this;
	}

	this->capacity = ref.capacity;
	data = new T[capacity];
	for (int i = 0; i < capacity; i++)
		data[i] = ref.data[i];

	return *this;
}

template <typename T>
T& GenericArray<T>::operator[](int index)
{
	if (isValidIndex(index))
		return data[index];
	exit(0);
}

template <typename T>
const T& GenericArray<T>::operator[](int index) const
{
	if (isValidIndex(index))
		return data[index];
	exit(0);
}

template <typename T>
int GenericArray<T>::getCapacity() const
{
	return capacity;
}

template <typename T>
void GenericArray<T>::reSize(int newCap)
{
	if (newCap <= 0)
	{
		this->~GenericArray();
		return;
	}
	T* ptr = new T[newCap];
	if (capacity > 0)
	{
		int size = newCap < capacity ? newCap : capacity;
		for (int i = 0; i < size; i++)
		{
			ptr[i] = data[i];
		}
	}
	this->~GenericArray();
	capacity = newCap;
	data = ptr;
}

#endif // !GENERICARRAY-H

