#include <iostream>
#include "BST.h"

using namespace std;

template <typename T>
BST<T>::BST(const BST<T>& other)
{
	root = nullptr;
	*this = other;
}

template <typename T>
BST<T>& BST<T>::operator=(const BST<T>& other)
{
	if (this != &other)
	{
		if (root)
			deleteTree(root);
		root = copyTree(other.root);
	}
	return *this;
}

template <typename T>
void BST<T>::copyTree(Node<T>* p)
{
	if (!p)
		return;
	insert(p->info);
	copyTree(p->left);
	copyTree(p->right);
}

template <typename T>
void BST<T>::LVR(Node<T>* p)
{
	if (!p)
		return;
	if (p->left)
		LVR(p->left);
	cout << p->info << ":";
	if (p->right)
		LVR(p->right);
}

template <typename T>
void BST<T>::LRV(Node<T>* p)
{
	if (!p)
		return;
	if (p->left)
		LRV(p->left);
	if (p->right)
		LRV(p->right);
	cout << p->info << ":";
}

template <typename T>
void BST<T>::VLR(Node<T>* p)
{
	if (!p)
		return;
	cout << p->info << ":";
	if (p->left)
		VLR(p->left);
	if (p->right)
		VLR(p->right);
}

template <typename T>
Node<T>* BST<T>::findNode(Node<T>* p, T key)
{
	if (!p)
		return nullptr;
	if (p->info == key)
		return p;
	if (key < p->info)
		return findNode(p->left, key);
	else
		return findNode(p->right, key);
}

template <typename T>
int BST<T>::getHeight(Node<T>* p)
{
	if (!p)
		return 0;
	int leftHeight = getHeight(p->left);
	int rightHeight = getHeight(p->right);
	return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

template <typename T>
T BST<T>::getMin(Node<T>* p)
{
	if (!p)
		throw "Empty tree";
	if (!p->left)
		return p->info;
	return getMin(p->left);
}

template <typename T>
T BST<T>::getMax(Node<T>* p)
{
	if (!p)
		throw "Empty tree";
	if (!p->right)
		return p->info;
	return getMax(p->right);
}

template <typename T>
T BST<T>::getInOrderSuccessor(Node<T>* p, T key)
{
	Node<T>* node = findNode(p, key);
	if (!node)
		throw "Node not found";
	if (node->right)
		return getMin(node->right);
	Node<T>* successor = nullptr;
	Node<T>* ancestor = p;
	while (ancestor != node)
	{
		if (node->info < ancestor->info)
		{
			successor = ancestor;
			ancestor = ancestor->left;
		}
		else
			ancestor = ancestor->right;
	}
	if (!successor)
		throw "No successor";
	return successor->info;
}

template <typename T>
T BST<T>::getInOrderPredecessor(Node<T>* p, T key)
{
	Node<T>* node = findNode(p, key);
	if (!node)
		throw "Node not found";
	if (node->left)
		return getMax(node->left);
	Node<T>* predecessor = nullptr;
	Node<T>* ancestor = p;
	while (ancestor != node)
	{
		if (node->info > ancestor->info)
		{
			predecessor = ancestor;
			ancestor = ancestor->right;
		}
		else
			ancestor = ancestor->left;
	}
	if (!predecessor)
		throw "No predecessor";
	return predecessor->info;
}

template <typename T>
Node<T>* BST<T>::getParent(Node<T>* p, T key)
{
	if (!p)
		return nullptr;
	if (p->left && p->left->info == key)
		return p;
	if (p->right && p->right->info == key)
		return p;
	if (key < p->info)
		return getParent(p->left, key);
	else
		return getParent(p->right, key);
}

template <typename T>
T BST<T>::getLeftChild(T parent)
{
	Node<T>* node = findNode(root, parent);
	if (!node)
		throw "Node not found";
	if (!node->left)
		throw "No left child";
	return node->left->info;
}

template <typename T>
T BST<T>::getRightChild(T parent)
{
	Node<T>* node = findNode(root, parent);
	if (!node)
		throw "Node not found";
	if (!node->right)
		throw "No right child";
	return node->right->info;
}

template <typename T>
void BST<T>::printAncestors(Node<T>* p, T key)
{
	if (!p)
		return;
	if (p->info == key)
		return;
	if (key < p->info)
	{
		cout << p->info << ":";
		printAncestors(p->left, key);
	}
	else
	{
		cout << p->info << ":";
		printAncestors(p->right, key);
	}
}

template <typename T>
void BST<T>::printDescendants(Node<T>* p, T key)
{
	if (!p)
		return;
	if (p->info == key)
	{
		if (p->left)
			cout << p->left->info << ":";
		if (p->right)
			cout << p->right->info << ":";
		return;
	}
	if (key < p->info)
		printDescendants(p->left, key);
	else
		printDescendants(p->right, key);
}

template <typename T>
void BST<T>::deleteTree(Node<T>* p)
{
	if (!p)
		return;
	deleteTree(p->left);
	deleteTree(p->right);
	delete p;
}

template <typename T>
int BST<T>::countLeafNodes(Node<T>* p)
{
	if (!p)
		return 0;
	if (!p->left && !p->right)
		return 1;
	return countLeafNodes(p->left) + countLeafNodes(p->right);
}

//template <typename T>
//int BST<T>::countParentNodes(Node<T>* p)
//{
//	if (!p)
//		return 0;
//	if (!p->left && !p->right)
//		return 0;
//	return countParentNodes(p->left) + countParentNodes(p->right) + 1;
//}

template <typename T>
void BST<T>::insert(T val)
{
	Node<T>* newNode = new Node<T>(val);
	if (!root)
	{
		root = newNode;
		return;
	}
	Node<T>* temp = root;
	while (temp)
	{
		if (val < temp->info)
		{
			if (!temp->left)
			{
				temp->left = newNode;
				return;
			}
			temp = temp->left;
		}
		else
		{
			if (!temp->right)
			{
				temp->right = newNode;
				return;
			}
			temp = temp->right;
		}
	}
}

template <typename T>
void BST<T>::remove(T val)
{
	Node<T>* p = root;
	Node<T>* parent = nullptr;
	while (p && p->info != val)
	{
		parent = p;
		if (val < p->info)
			p = p->left;
		else
			p = p->right;
	}
	if (!p)
		return;
	if (!p->left && !p->right)
	{
		if (p == root)
			root = nullptr;
		else if (parent->left == p)
			parent->left = nullptr;
		else
			parent->right = nullptr;
		delete p;
	}
	else if ((!p->left && p->right) || (p->left && !p->right))
	{
		Node<T>* subTree = p->left ? p->left : p->right;
		if (p == root)
			root = subTree;
		else if (parent->left == p)
			parent->left = subTree;
		else
			parent->right = subTree;
		delete p;
	}
	else
	{
		Node<T>* successor = p->right;
		parent = nullptr;
		while (successor->left)
		{
			parent = successor;
			successor = successor->left;
		}
		p->info = successor->info;
		if (parent)
			parent->left = successor->right;
		else
			p->right = successor->right;
		delete successor;
	}
}

template <typename T>
int BST<T>::getHeight(T val)
{
	Node<T>* p = findNode(root, val);
	if (!p)
		throw "Node not found";
	return getHeight(p);
}

template <typename T>
T BST<T>::getParent(T val)
{
	Node<T>* p = getParent(root, val);
	if (!p)
		throw "Node not found";
	return p->info;
}

template <typename T>
int BST<T>::countNodes(T val)
{
	Node<T>* p = findNode(root, val);
	if (!p)
		throw "Node not found";
	return countNodes(p);
}

template <typename T>
bool BST<T>::search(T val)
{
	Node<T>* temp = root;
	while (temp)
	{
		if (val == temp->info)
			return true;
		else if (val < temp->info)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return false;
}

template <typename T>
BST<T>::~BST()
{
	deleteTree(root);
	root = nullptr;
}