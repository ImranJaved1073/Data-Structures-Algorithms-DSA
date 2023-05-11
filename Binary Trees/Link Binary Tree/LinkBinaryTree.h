#ifndef LINKBINARYTREE_H
#define LINKBINARYTREE_H

#include <iostream>
#include "BTNode.h"
using namespace std;

template <typename T>
class LinkBinaryTree
{
	BTNode<T>* root;
	BTNode<T>* findNode(BTNode<T>*, T);
	void removeNode(BTNode<T>*);
	void VLR(BTNode<T>*);
	void LVR(BTNode<T>*);
	void LRV(BTNode<T>*);
	BTNode<T>* getParent(BTNode<T>*, T);
	void printAncestors(BTNode<T>*, T);
	void printDescendants(BTNode<T>*, T);
	int getHeight(BTNode<T>*) const;
	T countNodes(BTNode<T>*);
public:
	LinkBinaryTree() { root = nullptr; }
	void setRoot(T);
	void setLeftChild(T, T);
	void setRightChild(T, T);
	T getRoot() const { return root->info; }
	T getLeftChild(T) ;
	T getRightChild(T) ;
	T getParent(T) ;
	void remove(T);
	bool isEmpty() const { return root == nullptr; }
	void preOrderTraversal() { VLR(root); }
	void inOrderTraversal() { LVR(root); }
	void postOrderTraversal() { LRV(root); }

	int getHeight(T key) ;
	int getTreeHeight() const { return getHeight(root); }
	void printDescendants(T key) { printDescendants(root, key); }
	void printAncestors(T key) { printAncestors(root, key); }
	T countNodes() { return countNodes(root); }
	bool search(T  key) { return findNode(root, key) != nullptr; }
	~LinkBinaryTree();
};


#endif // !ARRAYBINARYTREE_H

