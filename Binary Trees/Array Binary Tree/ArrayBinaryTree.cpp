#include <iostream>
#include "ArrayBinaryTree.h"
#include <cmath>
using namespace std;

template <typename T>
void ArrayBinaryTree<T>::VLR(int i)
{
    if (i >= arraySize && nodesStatus[i] == false)
        return;
    cout << nodes[i] << ":";
    if (2 * i + 1 < arraySize && nodesStatus[2 * i + 1])
        VLR(2 * i + 1);
    if (2 * i + 2 < arraySize && nodesStatus[2 * i + 2])
        VLR(2 * i + 2);
    return;
}

template <typename T>
void ArrayBinaryTree<T>::LRV(int i)
{
    if (i >= arraySize && nodesStatus[i] == false)
        return;
    if (2 * i + 1 < arraySize && nodesStatus[2 * i + 1])
        LRV(2 * i + 1);
    if (2 * i + 2 < arraySize && nodesStatus[2 * i + 2])
        LRV(2 * i + 2);
    cout << nodes[i] << ":";
    return;
}

template <typename T>
void ArrayBinaryTree<T>::LVR(int i)
{
    if (i >= arraySize && nodesStatus[i] == false)
        return;
    if (2 * i + 1 < arraySize && nodesStatus[2 * i + 1])
        LVR(2 * i + 1);
    cout << nodes[i] << ":";
    if (2 * i + 2 < arraySize && nodesStatus[2 * i + 2])
        LVR(2 * i + 2);
    return;
}

template <typename T>
int ArrayBinaryTree<T>::search(int i, T key)
{
    int temp = -1;
    if (i >= arraySize || !nodesStatus[i])
        return -1;
    if (nodes[i] == key)
        temp = i;
    if (temp == -1 && 2 * i + 1 < arraySize && nodesStatus[2 * i + 1])
        temp = search(2 * i + 1, key);
    if (temp == -1 && 2 * i + 2 < arraySize && nodesStatus[2 * i + 2])
        temp = search(2 * i + 2, key);
    return temp;
}

template <typename T>
void ArrayBinaryTree<T>::Delete(int i)
{
    if (i >= arraySize)
        return;
    nodesStatus[i] = false;
    if (2 * i + 1 < arraySize && nodesStatus[2 * i + 1])
        Delete(2 * i + 1);
    if (2 * i + 2 < arraySize && nodesStatus[2 * i + 2])
        Delete(2 * i + 2);
    return;
}

template <typename T>
ArrayBinaryTree<T>::ArrayBinaryTree(int h)
{
    maxHeight = h;
    arraySize = pow(2, h) - 1;
    nodes = new T[arraySize];
    nodesStatus = new bool[arraySize];
    for (int i = 0; i < arraySize; i++)
        nodesStatus[i] = false;
}

template <typename T>
void ArrayBinaryTree<T>::setRoot(T val)
{
    nodes[0] = val;
    nodesStatus[0] = true;
}

template <typename T>
void ArrayBinaryTree<T>::setLeftChild(T par, T ch)
{
    int idx = search(0, par);
    if (idx == -1)
        return;
    if (2 * idx + 1 < arraySize)
    {
        nodes[2 * idx + 1] = ch;
        nodesStatus[2 * idx + 1] = true;
    }
}

template <typename T>
void ArrayBinaryTree<T>::setRightChild(T par, T ch)
{
    int idx = search(0, par);
    if (idx == -1)
        return;
    if (2 * idx + 2 < arraySize)
    {
        nodes[2 * idx + 2] = ch;
        nodesStatus[2 * idx + 2] = true;
    }
}

template <typename T>
void ArrayBinaryTree<T>::printDescendents(T par)
{
    int i = search(0, par);
    if (i == -1)
        return;
    else
        VLR(i);
}

template <typename T>
int ArrayBinaryTree<T>::getHeight(int i)
{
    if (!(i < arraySize && nodesStatus[i]))
        return -1;

    int l = 0, r = 0;

    if (2 * i + 1 < arraySize && nodesStatus[2 * i + 1])
        l = getHeight(2 * i + 1);
    if (2 * i + 2 < arraySize && nodesStatus[2 * i + 2])
        r = getHeight(2 * i + 2);

    if (l > r)
        return l + 1;
    else
        return r + 1;
}

template <typename T>
void ArrayBinaryTree<T>::remove(T key)
{
    int i = search(0, key);
    if (i == -1)
        return;
    Delete(i);
}

template <typename T>
T ArrayBinaryTree<T>::getParent(T ch)
{
    if (nodes[0] == ch)
        exit(0);
    int i = searchNode(ch);
    if (i == -1)
        exit(0);
    return nodes[(i - 1) / 2];
}

template <typename T>
ArrayBinaryTree<T>::~ArrayBinaryTree()
{
    if (nodes)
        delete[] nodes;
    if (nodesStatus)
        delete[] nodesStatus;
    nodes = nullptr;
    nodesStatus = nullptr;
    maxHeight = 0;
    arraySize = 0;
}

template <typename T>
void ArrayBinaryTree<T>::printAncestors(T ch)
{
	int i = searchNode(ch);
	if (i == -1)
		return;
    while (i != 0)
    {
		cout << nodes[(i - 1) / 2] << ":";
		i = (i - 1) / 2;
	}
}

template <typename T>
void ArrayBinaryTree<T>::setParent(T ch, T par)
{
	int i = searchNode(ch);
	if (i == -1)
		return;
	if (i == 0)
		return;
	nodes[(i - 1) / 2] = par;
}

template <typename T>
T ArrayBinaryTree<T>::getLeftChild(T par)
{
	int i = searchNode(par);
	if (i == -1)
		exit(0);
	if (2 * i + 1 < arraySize && nodesStatus[2 * i + 1])
		return nodes[2 * i + 1];
	else
		exit(0);
}

template <typename T>
T ArrayBinaryTree<T>::getRightChild(T par)
{
	int i = searchNode(par);
	if (i == -1)
		exit(0);
	if (2 * i + 2 < arraySize && nodesStatus[2 * i + 2])
		return nodes[2 * i + 2];
	else
		exit(0);
}