#include <iostream>
#include <stack>
#include "BTNode.h"
#include "LinkBinaryTree.h"
using namespace std;

template <typename T>
BTNode<T>* LinkBinaryTree<T>::findNode(BTNode<T>* p, T key)
{
	if (!p) return 0;
	BTNode<T>* status = nullptr;
	if (p->info == key)
		status = p;
	if (!status && p->left)
		status = findNode(p->left, key);
	if (!status && p->right)
		status = findNode(p->right, key);
	return status;

}

template <typename T>
void LinkBinaryTree<T>::removeNode(BTNode<T>* x)
{
	if (!x) return;
	if (x->left)
		removeNode(x->left);
	if (x->right)
		removeNode(x->right);
	delete x;
}

template <typename T>
void LinkBinaryTree<T>::VLR(BTNode<T>* p)
{
	if (!p)
		return;

	cout << p->info << ":";
	if (p->left)
		VLR(p->left);
	if (p->right)
		VLR	(p->right);
}

template <typename T>
void LinkBinaryTree<T>::LRV(BTNode<T>* p)
{
	if (!p)
		return;

	if (p->left)
		VLR(p->left);
	if (p->right)
		VLR(p->right);
	cout << p->info << ":";
}

template <typename T>
void LinkBinaryTree<T>::LVR(BTNode<T>* p)
{
	if (!p)
		return;

	if (p->left)
		VLR(p->left);
	cout << p->info << ":";
	if (p->right)
		VLR(p->right);
}

template <typename T>
BTNode<T>* LinkBinaryTree<T>::getParent(BTNode<T>* p, T key)
{
	if (!p && p == root)
		return nullptr;
	BTNode<T>* status = nullptr;
	if ((p->left && p->left->info == key) || (p->right && p->right->info == key))
		status = p;
	if (!status && p->left)
		status = getParent(p->left, key);
	if (!status && p->right)
		status = getParent(p->right, key);
	return status;
}

template <typename T>
void LinkBinaryTree<T>::setRoot(T par)
{
	if (!root)
		root = new BTNode<T>(par);
	else
		root->info = par;
}

template <typename T>
void LinkBinaryTree<T>::setLeftChild(T par, T ch)
{
	BTNode<T>* p = findNode(root, par);
	if (!p) return;
	if (!p->left)
		p->left = new BTNode<T>(ch);
	else
		p->left->info = ch;
}

template <typename T>
void LinkBinaryTree<T>::setRightChild(T par, T ch)
{
	BTNode<T>* p = findNode(root, par);
	if (!p) return;
	if (!p->right)
		p->right = new BTNode<T>(ch);
	else
		p->right->info = ch;
}

template <typename T>
T LinkBinaryTree<T>::getLeftChild(T par) 
{
	BTNode<T>* p = findNode(root, par);
	if (!p || !p->left) return 0;
	return p->left->info;
}

template <typename T>
T LinkBinaryTree<T>::getRightChild(T par) 
{
	BTNode<T>* p = findNode(root, par);
	if (!p || !p->right) return 0;
	return p->right->info;
}

template <typename T>
T LinkBinaryTree<T>::getParent(T key) 
{
	BTNode<T>* p = getParent(root, key);
	if (!p) return 0;
	return p->info;
}


template <typename T>
void LinkBinaryTree<T>::remove(T key)
{
	if (root->info == key)
	{
		removeNode(root);
		root = nullptr;
		return;
	}
	BTNode<T>* p = getParent(root, key);
	if (!p) return;
	if (p->left && p->left->info == key)
	{
		removeNode(p->left);
		p->left = nullptr;
	}
	else
	{
		removeNode(p->right);
		p->right = nullptr;
	}
}

template <typename T>
int LinkBinaryTree<T>::getHeight(BTNode<T>* p) const
{
	if (!p) return 0;
	int leftHeight = getHeight(p->left);
	int rightHeight = getHeight(p->right);
	return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

template <typename T>
int LinkBinaryTree<T>::getHeight(T key) 
{
	BTNode<T>* p = findNode(root, key);
	if (!p) return 0;
	return getHeight(p);
}

template <typename T>
void LinkBinaryTree<T>::printDescendants(BTNode<T>* p, T key)
{
	if (!p) return;
	if (p->info == key)
	{
		VLR(p);
		return;
	}
	printDescendants(p->left, key);
	printDescendants(p->right, key);
}

template <typename T>
void LinkBinaryTree<T>::printAncestors(BTNode<T>* p, T key)
{
	if (!p) return;
	if (p->info == key)
	{
		cout << p->info << " ";
		return;
	}
	printAncestors(p->left, key);
	printAncestors(p->right, key);
}

template <typename T>
T LinkBinaryTree<T>::countNodes(BTNode<T>* p)
{
	if (!p) return 0;
	return countNodes(p->left) + countNodes(p->right) + 1;
}

template <typename T>
LinkBinaryTree<T>::~LinkBinaryTree()
{
	if (root)
		removeNode(root);
	root = nullptr;
}