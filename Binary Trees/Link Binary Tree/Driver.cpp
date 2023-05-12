#include <iostream>
#include <stack>
#include "BTNode.h"
#include "LinkBinaryTree.cpp"

using namespace std;

void Menu()
{
	cout << "\t\t\t\t1. Set Root" << endl;
	cout << "\t\t\t\t2. Set Left Child" << endl;
	cout << "\t\t\t\t3. Set Right Child" << endl;
	cout << "\t\t\t\t4. Get Root" << endl;
	cout << "\t\t\t\t5. Get Left Child" << endl;
	cout << "\t\t\t\t6. Get Right Child" << endl;
	cout << "\t\t\t\t7. Get Parent" << endl;
	cout << "\t\t\t\t8. Remove" << endl;
	cout << "\t\t\t\t9. Is Empty" << endl;
	cout << "\t\t\t\t10. Preorder Traversal" << endl;
	cout << "\t\t\t\t11. Inorder Traversal" << endl;
	cout << "\t\t\t\t12. Postorder Traversal" << endl;
	cout << "\t\t\t\t13. Get Height" << endl;
	cout << "\t\t\t\t14. Get Tree Height" << endl;
	cout << "\t\t\t\t15. Print Decendants" << endl;
	cout << "\t\t\t\t16. Print Ancestors" << endl;
	cout << "\t\t\t\t17. Count Nodes" << endl;
	cout << "\t\t\t\t18. Search" << endl;
	cout << "\t\t\t\t19. Exit" << endl;
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
		case 4:
			cout << "Root: " << tree.getRoot() << endl;
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
		case 10:
			cout << "Preorder traversal: ";
			tree.preOrderTraversal();
			cout << endl;
			break;
		case 11:
			cout << "Inorder traversal: ";
			tree.inOrderTraversal();
			cout << endl;
			break;
		case 12:
			cout << "Postorder traversal: ";
			tree.postOrderTraversal();
			cout << endl;
			break;
		case 13:
			cout << "Enter node: ";
			cin >> node;
			cout << "Height: " << tree.getHeight(node) << endl;
			break;
		case 14:
			cout << "Tree height: " << tree.getTreeHeight() << endl;
			break;
		case 15:
			cout << "Enter node: ";
			cin >> node;
			tree.printDescendants(node);
			break;
		case 16:
			cout << "Enter node: ";
			cin >> node;
			tree.printAncestors(node);
			break;
		case 17:
			cout << "Number of nodes: " << tree.countTreeNodes() << endl;
			break;
		case 18:
			cout << "Enter key: ";
			cin >> key;
			if (tree.search(key))
				cout << "Found" << endl;
			else
				cout << "Not found" << endl;
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
