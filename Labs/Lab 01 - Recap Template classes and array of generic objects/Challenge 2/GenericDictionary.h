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
	int noOfPairs;
	int getKeyIndex(T key);
	void reSize();

public:
	GenericDictionary();
	//~GenericDictionary();
	void addPair(T key, U value);
	U getValue(T key);
	void print();
	bool isEmpty();
	bool isFull();
};

template <typename T, typename U>
GenericDictionary<T, U>::GenericDictionary()
{
	noOfPairs = 0;
}

template <typename T, typename U>
int GenericDictionary<T, U>::getKeyIndex(T key)
{
	for (int i = 0; i < noOfPairs; i++)
	{
		if (data[i].getKey() == key)
			return i;
	}
	return -1;
}

template <typename T, typename U>
void GenericDictionary<T, U>::reSize()
{
	GenericArray<DictionaryPair<T, U>> temp(data.getCapacity() == 0 ? 1 : data.getCapacity() * 2);
	for (int i = 0; i < noOfPairs; i++)
		temp[i] = data[i];
	data = temp;
}

template <typename T, typename U>
void GenericDictionary<T, U>::addPair(T key, U value)
{
	if (noOfPairs == data.getCapacity())
		reSize();

	int index = getKeyIndex(key);
	if (index == -1)
		data[noOfPairs++] = DictionaryPair<T, U>(key, value);
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
	for (int i = 0; i < noOfPairs; i++)
		cout << data[i].getKey() << " " << data[i].getValue() << endl;
}

template <typename T, typename U>
bool GenericDictionary<T, U>::isEmpty()
{
	return noOfPairs == 0;
}

template <typename T, typename U>
bool GenericDictionary<T, U>::isFull()
{
	return noOfPairs == data.getCapacity();
}

#endif // !DICTIONARY_PAIR