#ifndef BST_H
#define BST_H
#include "Node.h"

template <typename T>
class BST
{
	Node<T>* root;
	void LVR(Node<T>*);
	void LRV(Node<T>*);
	void VLR(Node<T>*);
	Node<T>* findNode(Node<T>*, T);
	int getHeight(Node<T>*);
	T getMin(Node<T>*);
	T getMax(Node<T>*);
	T getInOrderSuccessor(Node<T>*, T);
	T getInOrderPredecessor(Node<T>*, T);
	Node<T>* getParent(Node<T>*, T);
	
	void printAncestors(Node<T>*, T);
	void printDescendants(Node<T>*, T);
	void deleteTree(Node<T>*);
	int countNodes(Node<T>* p) { return (!p) ? 0 : countNodes(p->left) + countNodes(p->right) + 1; }
	int countLeafNodes(Node<T>*);
	int countParentNodes(Node<T>* p) { return countNodes(p) - countLeafNodes(p); }


public:
	BST() { root = nullptr; }
	BST (const BST<T>&);
	BST<T>& operator=(const BST<T>&);
	void copyTree (Node<T>*);
	void insert(T);
	void remove(T);
	bool search(T);
	void inOrderTraversal() { LVR(root); }
	void postOrderTraversal() { LRV(root); }
	void preOrderTraversal() { VLR(root); }
	int getTreeHeight() { return getHeight(root); }  
	int getHeight(T);
	T getMin() { return getMin(root); } 
	T getMax() { return getMax(root); } 
	T getInOrderSuccessor(T key) { return getInOrderSuccessor(root, key); } 
	T getInOrderPredecessor(T key) { return getInOrderPredecessor(root, key); } 
	T getRoot() { return root->info; } 
	T getParent(T); 
	T getLeftChild(T); 
	T getRightChild(T);
	bool isEmpty() const { return root == nullptr; }
	void printAncestors(T key ) { printAncestors(root, key); } 
	void printDescendants( T key) { printDescendants(root, key); } 
	void deleteTree() { deleteTree(root); }
	int countTreeNodes() { return countNodes(root); }
	int countNodes(T key);
	int countLeafNodes() { return countLeafNodes(root); }
	int countParentNodes() { return countParentNodes(root); }



	~BST();
};

#endif // !BST_H