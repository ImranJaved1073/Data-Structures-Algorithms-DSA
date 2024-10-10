#ifndef AVL_CPP
#define AVL_CPP

#include "AVL.h"

template <typename T>
int AVL<T>::height(Node<T>* node)
{
	if (!node) return 0;
	return node->height;
}

template <typename T>
int AVL<T>::getBalance(Node<T>* node)
{
	if (!node) return 0;
	return height(node->left) - height(node->right);
}

template <typename T>
Node<T>* AVL<T>::LL(Node<T>* node) // rightRotate
{
	Node<T>* leftChild = node->left;
	Node<T>* rightGrandChild = leftChild->right;

	leftChild->right = node;
	node->left = rightGrandChild;

	node->height = 1 + max(height(node->left), height(node->right));
	leftChild->height = 1 + max(height(leftChild->left), height(leftChild->right));

	return leftChild;
}

template <typename T>
Node<T>* AVL<T>::RR(Node<T>* node) // leftRotate
{
	Node<T>* rightChild = node->right;
	Node<T>* leftGrandChild = rightChild->left;

	rightChild->left = node;
	node->right = leftGrandChild;

	node->height = 1 + max(height(node->left), height(node->right));
	rightChild->height = 1 + max(height(rightChild->left), height(rightChild->right));

	return rightChild;
}

template <typename T>
Node<T>* AVL<T>::LR(Node<T>* node) // leftRotate + rightRotate
{
	node->left = RR(node->left);
	return LL(node);
}

template <typename T>
Node<T>* AVL<T>::RL(Node<T>* node) // rightRotate + leftRotate
{
	node->right = LL(node->right);
	return RR(node);
}


template <typename T>
Node<T>* AVL<T>::insert(Node<T>* node, T val)
{
	if (!node) return new Node<T>(val);

	if (val < node->data) node->left = insert(node->left, val);
	else if (val > node->data) node->right = insert(node->right, val);
	else return node;

	node->height = 1 + max(height(node->left), height(node->right));

	int balance = getBalance(node);

	if (balance > 1 && val < node->left->data) return LL(node);
	if (balance < -1 && val > node->right->data) return RR(node);
	if (balance > 1 && val > node->left->data) return LR(node);
	if (balance < -1 && val < node->right->data) return RL(node);

	return node;
}

template <typename T>
Node<T>* AVL<T>::minValueNode(Node<T>* node)
{
	Node<T>* p = node;
	while (p->left) p = p->left;
	return p;
}

template <typename T>
Node<T>* AVL<T>::maxValueNode(Node<T>* node)
{
	Node<T>* p = node;
	while (p->right) p = p->right;
	return p;
}

template <typename T>
Node<T>* AVL<T>::searchNode(Node<T>* node, T key)
{
	if (!node) return nullptr;
	if (key == node->data) return node;
	if (key < node->data) return searchNode(node->left, key);
	return searchNode(node->right, key);
}

template <typename T>
Node<T>* AVL<T>::removeNode(Node<T>* node, T key)
{
	if (!node) return node;

	if (key < node->data) node->left = removeNode(node->left, key);
	else if (key > node->data) node->right = removeNode(node->right, key);
	else
	{
		if (!node->left || !node->right)
		{
			Node<T>* temp = node->left ? node->left : node->right;
			if (!temp)
			{
				temp = node;
				node = nullptr;
			}
			else *node = *temp;
			delete temp;
		}
		else
		{
			Node<T>* temp = minValueNode(node->right);
			node->data = temp->data;
			node->right = removeNode(node->right, temp->data);
		}
	}

	if (!node) return node;

	node->height = 1 + max(height(node->left), height(node->right));

	int balance = getBalance(node);

	if (balance > 1 && getBalance(node->left) >= 0) return LL(node);
	if (balance > 1 && getBalance(node->left) < 0) return LR(node);
	if (balance < -1 && getBalance(node->right) <= 0) return RR(node);
	if (balance < -1 && getBalance(node->right) > 0) return RL(node);

	return node;
}

template <typename T>
void AVL<T>::VLR(Node<T>* p)
{
	if (!p) return;
	cout << p->data << " ";
	VLR(p->left);
	VLR(p->right);
}

template <typename T>
void AVL<T>::LVR(Node<T>* p)
{
	if (!p) return;
	LVR(p->left);
	cout << p->data << " ";
	LVR(p->right);
}

template <typename T>
void AVL<T>::LRV(Node<T>* p)
{
	if (!p) return;
	LRV(p->left);
	LRV(p->right);
	cout << p->data << " ";
}

template <typename T>
void AVL<T>::LevelOrder(Node<T>* p)
{
	if (!p) return;
	queue<Node<T>*> q;
	q.push(p);
	while (!q.empty())
	{
		Node<T>* temp = q.front();
		q.pop();
		cout << temp->data << " ";
		if (temp->left) q.push(temp->left);
		if (temp->right) q.push(temp->right);
	}
}

template <typename T>
Node<T>* AVL<T>::findParent(Node<T>* node, T key)
{
	if (!node) return nullptr;
	if (key == node->data) return nullptr;
	if (key < node->data)
	{
		if (node->left && key == node->left->data) return node;
		return findParent(node->left, key);
	}
	if (node->right && key == node->right->data) return node;
	return findParent(node->right, key);
}

template <typename T>
Node<T>* AVL<T>::findLeftChild(T key)
{
	Node<T>* p = searchNode(root, key);
	if (!p) return nullptr;
	return p->left;
}

template <typename T>
Node<T>* AVL<T>::findRightChild(T key)
{
	Node<T>* p = searchNode(root, key);
	if (!p) return nullptr;
	return p->right;
}

template <typename T>
void AVL<T>::printAncestors(Node<T>* node, T key)
{
	if (!node) return;
	if (key == node->data) return;
	if (key < node->data) return printAncestors(node->left, key);
	cout << node->data << " ";
	return printAncestors(node->right, key);
}

template <typename T>
void AVL<T>::printDescendants(Node<T>* node, T key)
{
	if (!node) return;
	if (key == node->data)
	{
		printLevelOrder(node);
		return;
	}
	if (key < node->data) return printDescendants(node->left, key);
	return printDescendants(node->right, key);
}

template <typename T>
int AVL<T>::countNodes(Node<T>* node)
{
	if (!node) return 0;
	return 1 + countNodes(node->left) + countNodes(node->right);
}

template <typename T>
int AVL<T>::countLeafNodes(Node<T>* node)
{
	if (!node) return 0;
	if (!node->left && !node->right) return 1;
	return countLeafNodes(node->left) + countLeafNodes(node->right);
}

template <typename T>
int AVL<T>::countParentNodes(Node<T>* node)
{
	if (!node) return 0;
	return countNodes(node) - countLeafNodes(node);
}

template <typename T>
T AVL<T>::getLeftChild(T key)
{
	Node<T>* p = findLeftChild(key);
	if (p) return p->data;
}

template <typename T>
T AVL<T>::getRightChild(T key)
{
	Node<T>* p = findRightChild(key);
	if (p) return p->data;
}

template <typename T>
T AVL<T>::getParent(T key)
{
	Node<T>* p = findParent(root, key);
	if (p) return p->data;
}

#endif // !AVL_CPP
