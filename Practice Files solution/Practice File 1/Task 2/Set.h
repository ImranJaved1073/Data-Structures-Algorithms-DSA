#ifndef SET_H
#define SET_H

#include "GenericArray.h"
#include <iostream>

using namespace std;

template <typename T>
class Set
{
	GenericArray<T> arr;

public:
	Set();
	Set(const Set<T>& ref);
	Set<T>& operator=(const Set<T>& ref);
	~Set();
	
	bool isEmpty() const;
	int getCardinality() const;
	
	bool insert(const T& element);
	bool remove(const T& element);
	bool isSubset(const Set<T>& ref) const;
	bool isMember(const T& element) const;
	
	Set<T> calcUnion(const Set<T>& ref) const;
	Set calcIntersection(const Set&) const;
	Set calcDifference(const Set&) const;
	Set<T> operator+(const Set<T>&) const;
	Set<T> operator-(const Set<T>&) const;
	bool operator==(const Set<T>&) const;
	
	void print() const;
};

template <typename T>
Set<T>::Set() :arr()
{}

template <typename T>
Set<T>::Set(const Set<T>& ref)
{
	arr = ref.arr;
}

template <typename T>
Set<T>::~Set()
{
	arr.~GenericArray();
}

template <typename T>
Set<T>& Set<T>::operator=(const Set<T>& ref)
{
	if (this != &ref)
		arr = ref.arr;
	return *this;
}

template <typename T>
bool Set<T>::isEmpty() const
{
	return arr.getCapacity() == 0;
}

template <typename T>
int Set<T>::getCardinality() const
{
	return arr.getCapacity();
}

template <typename T>
bool Set<T>::isMember(const T& element) const
{
	for (int i = 0; i < arr.getCapacity(); i++)
	{
		if (arr[i] == element)
			return true;
	}
	return false;
}

template <typename T>
bool Set<T>::insert(const T& element)
{
	if (isMember(element))
		return false;
	arr.reSize(arr.getCapacity() + 1);
	arr[arr.getCapacity() - 1] = element;
	return true;
}

template <typename T>
bool Set<T>::remove(const T& element)
{
	if (!isMember(element))
		return false;
	int index = 0;
	for (int i = 0; i < arr.getCapacity(); i++)
	{
		if (arr[i] == element)
		{
			index = i;
			break;
		}
	}
	for (int i = index; i < arr.getCapacity() - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr.reSize(arr.getCapacity() - 1);
	return true;
}

template <typename T>
void Set<T>::print() const
{
	for (int i = 0; i < arr.getCapacity(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

template <typename T>
bool Set<T>::isSubset(const Set<T>& ref) const
{
	int count = 0;
	if (arr.getCapacity() > ref.arr.getCapacity())
		return false;
	for (int i = 0; i < arr.getCapacity(); i++)
	{
		if (ref.isMember(arr[i]))
			count++;
	}
	return count == arr.getCapacity();
}

template <typename T>
Set<T> Set<T>::calcUnion(const Set<T>& ref) const
{
	Set<T> temp;
	for (int i = 0; i < arr.getCapacity(); i++)
		temp.insert(arr[i]);

	for (int i = 0; i < ref.arr.getCapacity(); i++)
		temp.insert(ref.arr[i]);
	return temp;
}

template <typename T>
Set<T> Set<T>::calcIntersection(const Set<T>& ref) const
{
	Set<T> temp;
	for (int i = 0; i < arr.getCapacity(); i++)
	{
		if (ref.isMember(arr[i]))
			temp.insert(arr[i]);
	}
	return temp;
}

template <typename T>
Set<T> Set<T>::calcDifference(const Set<T>& ref) const
{
	Set<T> temp;
	for (int i = 0; i < arr.getCapacity(); i++)
	{
		if (!ref.isMember(arr[i]))
			temp.insert(arr[i]);
	}
	return temp;
}

template <typename T>
Set<T> Set<T>::operator+(const Set<T>& ref) const
{
	return calcUnion(ref);
}

template <typename T>
Set<T> Set<T>::operator-(const Set<T>& ref) const
{
	return calcDifference(ref);
}

template <typename T>
bool Set<T>::operator==(const Set<T>& ref) const
{
	return isSubset(ref) && ref.isSubset(*this);
}


#endif // !SET-H