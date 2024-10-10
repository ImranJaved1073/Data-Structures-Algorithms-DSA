#include <iostream>
#include <stack>
#include "AVL.h"

using namespace std;

int main()
{
	AVL<int> tree;
	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.insert(6);
	tree.insert(7);
	tree.insert(8);
	tree.insert(9);
	tree.printInOrder();
	cout << endl;
	tree.printPreOrder();
	cout << endl;
	tree.printPostOrder();
	cout << endl;
	tree.printLevelOrder();
}