#ifndef GENERICDICTIONARY_H
#define GENERICDICTIONARY_H

#include <iostream>
#include "DictionaryPair.h"

using namespace std;

template <typename T, typename U>
class GenericDictionary
{
	DictionaryPair<T, U>* pair;
	int noOfPairs;
	int capacity;
	void reSize();
	int getKeyIndex(T key);
public:
	GenericDictionary();
	void addPair(T, U);
	U getValue(T);
	void print();
	~GenericDictionary();
	bool isEmpty();
	bool isFull();
};

template <typename T, typename U>
GenericDictionary<T, U>::GenericDictionary()
{
	pair = nullptr;
	noOfPairs = 0;
	capacity = 0;
}

template <typename T, typename U>
void GenericDictionary<T, U>::addPair(T key, U value)
{
	if (isFull())
	{
		reSize();
	}
	
	int index = getKeyIndex(key);
	if (index == -1)
	{
		/*DictionaryPair<T, U> temp(key, value);
		pair[noOfPairs] = temp;
		noOfPairs++;*/
		pair[noOfPairs++] = DictionaryPair<T, U>(key, value);
	}
	else
		pair[index].setValue(value);
}

template <typename T, typename U>
U GenericDictionary<T, U>::getValue(T key)
{
	int index = getKeyIndex(key);
	if (index != -1)
	{
		return pair[index].getValue();
	}
	exit(0);
}

template <typename T, typename U>
void GenericDictionary<T, U>::print()
{
	for (int i = 0; i < noOfPairs; i++)
	{
		cout << pair[i].getKey() << " " << pair[i].getValue() << endl;
	}
}

template <typename T, typename U>
GenericDictionary<T, U>::~GenericDictionary()
{
	if (pair != nullptr)
	{
		delete[]pair;
		pair = nullptr;
	}
	capacity = 0;
	noOfPairs = 0;
}

template <typename T, typename U>
bool GenericDictionary<T, U>::isEmpty()
{
	return noOfPairs == 0;
}

template <typename T, typename U>
bool GenericDictionary<T, U>::isFull()
{
	return noOfPairs == capacity;
}

template <typename T, typename U>
void GenericDictionary<T, U>::reSize()
{
	int no = noOfPairs;
	int newCapacity = capacity == 0 ? 1 : capacity * 2;
	DictionaryPair<T, U>* temp = new DictionaryPair<T, U>[newCapacity];
	if (noOfPairs > 0)
	{
		int size = newCapacity < noOfPairs ? newCapacity : noOfPairs;
		for (int i = 0; i < size; i++)
		{
			temp[i] = pair[i];
		}
	}
	this->~GenericDictionary();
	pair = temp;
	capacity = newCapacity;
	noOfPairs = no;
}

template <typename T, typename U>
int GenericDictionary<T, U>::getKeyIndex(T key)
{
	for (int i = 0; i < noOfPairs; i++)
	{
		if (pair[i].getKey() == key)
		{
			return i;
		}
	}
	return -1;
}
#endif // !DICTIONARY_PAIR