#ifndef GENERICDICTIONARY_H
#define GENERICDICTIONARY_H

#include <iostream>
#include "DictionaryPair.h"
#include "GenericArray.h"

using namespace std;

template <typename T, typename U>
class GenericDictionary
{
	GenericArray<DictionaryPair<T, U>> data;
	int getKeyIndex(T key);
	void reSize(int newCap);
public:
	GenericDictionary();
	~GenericDictionary();
	void addPair(T key, U value);
	U getValue(T key);
	void print();
	bool isEmpty();
	bool isFull();
};

template <typename T, typename U>
GenericDictionary<T, U>::GenericDictionary()
{
}

template <typename T, typename U>
GenericDictionary<T, U>::~GenericDictionary()
{
	data.~GenericArray();
}

template <typename T, typename U>
void GenericDictionary<T, U>::addPair(T key, U value)
{
	int index = getKeyIndex(key);
	if (index == -1)
	{
		if (isFull())
			reSize(data.getCapacity() + 1);
		data[data.getCapacity() - 1] = DictionaryPair<T, U>(key, value);
	}
	else
		data[index].setValue(value);
}

template <typename T, typename U>
U GenericDictionary<T, U>::getValue(T key)
{
	int index = getKeyIndex(key);
	if (index != -1)
	{
		return data[index].getValue();
	}
	exit(0);
}

template <typename T, typename U>
void GenericDictionary<T, U>::print()
{
	for (int i = 0; i < data.getCapacity(); i++)
	{
		cout << data[i].getKey() << " " << data[i].getValue() << endl;
	}
}

template <typename T, typename U>
bool GenericDictionary<T, U>::isEmpty()
{
	return data.getCapacity() == 0;
}

template <typename T, typename U>
bool GenericDictionary<T, U>::isFull()
{
	return true;
}

template <typename T, typename U>
void GenericDictionary<T, U>::reSize(int newCap)
{
	data.reSize(newCap);
}

template <typename T, typename U>
int GenericDictionary<T, U>::getKeyIndex(T key)
{
	for (int i = 0; i < data.getCapacity(); i++)
	{
		if (data[i].getKey() == key)
			return i;
	}
	return -1;
}
#endif // !DICTIONARY_PAIR