#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node
{
	T info;
	Node<T>* left;
	Node<T>* right;

	Node()
	{
		left = right = nullptr;
	}

	Node(T val)
	{
		info = val;
		left = right = nullptr;
	}
};

#endif // !NODE_H
