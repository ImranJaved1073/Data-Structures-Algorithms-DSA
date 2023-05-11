#include <iostream>
#include <stack>
#include "BTNode.h"
#include "LinkBinaryTree.cpp"

using namespace std;

void Menu()
{
	cout << "1. Set Root" << endl;
	cout << "2. Set Left Child" << endl;
	cout << "3. Set Right Child" << endl;
	cout << "4. Get Root" << endl;
	cout << "5. Get Left Child" << endl;
	cout << "6. Get Right Child" << endl;
	cout << "7. Get Parent" << endl;
	cout << "8. Remove" << endl;
	cout << "9. Is Empty" << endl;
	cout << "10. Preorder Traversal" << endl;
	cout << "11. Inorder Traversal" << endl;
	cout << "12. Postorder Traversal" << endl;
	cout << "13. Get Height" << endl;
	cout << "14. Get Tree Height" << endl;
	cout << "15. Print Decendants" << endl;
	cout << "16. Print Ancestors" << endl;
	cout << "17. Count Nodes" << endl;
	cout << "18. Search" << endl;
	cout << "19. Exit" << endl;
}

int main()
{
	LinkBinaryTree<int> tree;
	int choice, node, child, parent, key;

	tree.setRoot(1);
	tree.setRightChild(1, 3);
	tree.setLeftChild(1, 2);
	tree.setRightChild(2, 5);
	tree.setLeftChild(2, 4);
	tree.setLeftChild(4, 7);
	tree.setRightChild(5, 8);
	tree.setLeftChild(3, 6);
	tree.setRightChild(6, 9);
	tree.setLeftChild(9, 10);
	tree.setRightChild(9, 11);
	do
	{
		Menu();
		tree.preOrderTraversal();
		cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter node: ";
			cin >> node;
			tree.setRoot(node);
			break;
		case 2:
			cout << "Enter parent: ";
			cin >> parent;
			cout << "Enter child: ";
			cin >> child;
			tree.setLeftChild(parent, child);
			break;
		case 3:
			cout << "Enter parent: ";
			cin >> parent;
			cout << "Enter child: ";
			cin >> child;
			tree.setRightChild(parent, child);
			break;
		case 5:
			cout << "Enter parent: ";
			cin >> parent;
			cout << "Left child: " << tree.getLeftChild(parent) << endl;
			break;
		case 6:
			cout << "Enter parent: ";
			cin >> parent;
			cout << "Right child: " << tree.getRightChild(parent) << endl;
			break;
		case 7:
			cout << "Enter node: ";
			cin >> node;
			cout << "Parent: " << tree.getParent(node) << endl;
			break;
		case 4:
			cout << "Root: " << tree.getRoot() << endl;
			break;
		case 18:
			cout << "Enter key: ";
			cin >> key;
			cout << "Node: " << tree.search(key) << endl;
			break;
		case 16:
			cout << "Enter node: ";
			cin >> node;
			tree.printAncestors(node);
			break;
		case 15:
			cout << "Enter node: ";
			cin >> node;
			tree.printDescendants(node);
			break;
		case 13:
			cout << "Enter node: ";
			cin >> node;
			cout << "Height: " << tree.getHeight(node) << endl;
			break;
		case 14:
			cout << "Tree height: " << tree.getTreeHeight() << endl;
			break;
		case 11:
			cout << "Inorder traversal: ";
			tree.inOrderTraversal();
			cout << endl;
			break;
		case 10:
			cout << "Preorder traversal: ";
			tree.preOrderTraversal();
			cout << endl;
			break;
		case 12:
			cout << "Postorder traversal: ";
			tree.postOrderTraversal();
			cout << endl;
			break;
		case 8:
			cout << "Enter node: ";
			cin >> node;
			tree.remove(node);
			break;
		case 9:
			if (tree.isEmpty())
				cout << "Tree is empty\n";
			else
				cout << "Tree is not empty\n";
			break;
		case 17:
			cout << "Number of nodes: " << tree.countNodes() << endl;
			break;
		case 19:
			break;
		default:
			cout << "Invalid choice\n";
		}
		system("pause");
		system("cls");
	} while (choice != 19);
}