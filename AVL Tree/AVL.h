#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class AVL;

template <typename T>
class Node
{
	friend class AVL<T>;
	T data;
	Node<T>* left;
	Node<T>* right;
	int height;

public:
	Node() { left = right = nullptr; }
	Node(T val)
	{
		data = val;
		left = right = nullptr;
		height = 1;
	}
};

template <typename T>
class AVL
{
	Node<T>* root;
	int height(Node<T>*);
	int getBalance(Node<T>*);
	Node<T>* LL(Node<T>*);
	Node<T>* RR(Node<T>*);
	Node<T>* LR(Node<T>*);
	Node<T>* RL(Node<T>*);
	Node<T>* insert(Node<T>*, T);
	void LVR(Node<T>*);
	void VLR(Node<T>*);
	void LRV(Node<T>*);
	void LevelOrder(Node<T>*);
	Node<T>* removeNode(Node<T>*, T);
	Node<T>* minValueNode(Node<T>*);
	Node<T>* maxValueNode(Node<T>*);
	Node<T>* searchNode(Node<T>*, T);
	Node<T>* findParent(Node<T>*, T);
	Node<T>* findLeftChild(T);
	Node<T>* findRightChild(T);
	void printAncestors(Node<T>*, T);
	void printDescendants(Node<T>*, T);
	int countNodes(Node<T>*);
	int countLeafNodes(Node<T>*);
	int countParentNodes(Node<T>*);

public:
	AVL() { root = nullptr; }
	void insert(T data) { root = insert(root, data); }
	void InOrder() { LVR(root); }
	void PreOrder() { VLR(root); }
	void PostOrder() { LRV(root); }
	void LevelOrderTraversal() { LevelOrder(root); }
	void remove(T data) { root = remove(root, data); }
	T getLeftChild(T);
	T getRightChild(T);
	T getParent(T);

};

#include "AVL.cpp"


#endif // !AVL_H


