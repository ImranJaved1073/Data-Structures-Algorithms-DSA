#ifndef SET_H
#define SET_H

#include <iostream>

using namespace std;

template <typename T>
class Set
{
	T* data;
	int capacity;
	int noOfElements;
	void resize(int newCapacity);
	int searchElementIndex(const T& element) const;
public:
	Set();
	~Set();
	Set(const Set<T>&);
	int getCardinality() const;
	Set<T>& operator=(const Set<T>&);
	bool insert(T);
	bool remove(T);
	bool isMember(T) const;
	bool isSubset(const Set<T>&) const;

	Set calcUnion(const Set&) const;
	Set calcIntersection(const Set&) const;
	Set calcDifference(const Set&) const;
	Set<T> operator+(const Set<T>&) const;
	Set<T> operator-(const Set<T>&) const;
	bool operator==(const Set<T>&) const;

	void print() const;
};

template <typename T>
void Set<T>::resize(int newCapacity)
{
	int newNoOfElements = newCapacity < noOfElements ? newCapacity : noOfElements;
	if (newCapacity <= 0)
	{
		this->~Set();
		return;
	}
	T* ptr = new T[newCapacity];
	if (capacity > 0)
	{
		int size = newCapacity < capacity ? newCapacity : capacity;
		for (int i = 0; i < size; i++)
			ptr[i] = data[i];
	}
	this->~Set();
	capacity = newCapacity;
	noOfElements = newNoOfElements;
	data = ptr;
}

template <typename T>
Set<T>::Set()
{
	capacity = 0;
	noOfElements = 0;
	data = nullptr;
}

template <typename T>
Set<T>::Set(const Set<T>& rhs)
{
	if (rhs.data == nullptr)
	{
		this->capacity = 0;
		this->noOfElements = 0;
		data = nullptr;
		return;
	}
	capacity = rhs.capacity;
	noOfElements = rhs.noOfElements;
	data = new T[capacity];
	for (int i = 0; i < capacity; i++)
		data[i] = rhs.data[i];
}

template <typename T>
Set<T>::~Set()
{
	if (data)
	{
		delete[] data;
		data = nullptr;
	}
	capacity = 0;
	noOfElements = 0;
}

template <typename T>
int Set<T>::getCardinality() const
{
	return noOfElements;
}

template <typename T>
int Set<T>::searchElementIndex(const T& element) const
{
	for (int i = 0; i < noOfElements; i++)
		if (data[i] == element)
			return i;
	return -1;
}

template <typename T>
bool Set<T>::insert(T item)
{
	if (isMember(item))
		return false;
	if (noOfElements == capacity)
		resize(capacity + 1);
	data[noOfElements++] = item;
	return true;
}

template <typename T>
bool Set<T>::remove(T element)
{
	if (!isMember(element))
		return false;
	int index = searchElementIndex(element);
	
	for (int i = index; i < noOfElements - 1; i++)
		data[i] = data[i + 1];
	resize(noOfElements - 1);
	return true;
}

template <typename T>
bool Set<T>::isMember(T val) const
{
	return searchElementIndex(val) != -1;
}

template <typename T>
Set<T> Set<T>::calcUnion(const Set& rhs) const
{
	Set temp;
	for (int i = 0; i < noOfElements; i++)
		temp.insert(data[i]);

	for (int i = 0; i < rhs.noOfElements; i++)
		temp.insert(rhs.data[i]);

	return temp;
}

template <typename T>
Set<T> Set<T>::calcIntersection(const Set<T>& rhs) const
{
	Set<T> temp;
	for (int i = 0; i < noOfElements; i++)
		if (rhs.isMember(data[i]))
			temp.insert(data[i]);
	return temp;
}

template <typename T>
Set<T> Set<T>::calcDifference(const Set<T>& rhs) const
{
	Set<T> temp;
	for (int i = 0; i < noOfElements; i++)
		if (!rhs.isMember(data[i]))
			temp.insert(data[i]);
	return temp;
}

template <typename T>
Set<T> Set<T>::operator+(const Set<T>& rhs) const
{
	return calcUnion(rhs);
}

template <typename T>
Set<T> Set<T>::operator-(const Set<T>& rhs) const
{
	return calcDifference(rhs);
}

template <typename T>
bool Set<T>::operator==(const Set<T>& rhs) const
{
	if (noOfElements != rhs.noOfElements)
		return false;
	for (int i = 0; i < noOfElements; i++)
		if (!rhs.isMember(data[i]))
			return false;
	return true;
}

template <typename T>
Set<T>& Set<T>::operator=(const Set<T>& rhs)
{
	if (this != &rhs)
	{
		this->~GenericArray();
		if (rhs.data == nullptr)
		{
			this->capacity = 0;
			data = nullptr;
			return *this;
		}
		capacity = rhs.capacity;
		noOfElements = rhs.noOfElements;
		data = new T[capacity];
		for (int i = 0; i < capacity; i++)
			data[i] = rhs.data[i];
	}
	return *this;
}

template <typename T>
bool Set<T>::isSubset(const Set<T>& lhs) const
{
	int count = 0;
	if (this->noOfElements > lhs.noOfElements)
		return false;
	for (int i = 0; i < noOfElements; i++)
	{
		if (lhs.isMember(data[i]))
			count++;
	}
	if (count == this->noOfElements)
		return true;
	return false;
}

template <typename T>
void Set<T>::print() const
{
	for (int i = 0; i < noOfElements; i++)
		cout << data[i] << " ";
	cout << endl;
}



#endif // !SET-H