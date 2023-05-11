#ifndef BTNODE_H
#define BTNODE_H

template <typename T>
struct BTNode
{
	T info;
	BTNode<T>* left;
	BTNode<T>* right;

	BTNode()
	{
		left = right = nullptr;
	}

	BTNode(T val)
	{
		info = val;
		left = right = nullptr;
	}
};


#endif // !BTNODE_H

