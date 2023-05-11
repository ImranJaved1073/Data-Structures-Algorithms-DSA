#include <iostream>
#include "ArrayBinaryTree.cpp"

using namespace std;

void displayMenu()
{
	cout << "\t\t\t\t1. Set root\n";
	cout << "\t\t\t\t2. Set left child\n";
	cout << "\t\t\t\t3. Set right child\n";
	cout << "\t\t\t\t4. Get left child\n";
	cout << "\t\t\t\t5. Get right child\n";
	cout << "\t\t\t\t6. Get parent\n";
	cout << "\t\t\t\t7. Get root\n";
	cout << "\t\t\t\t8. Search node\n";
	cout << "\t\t\t\t9. Print ancestors\n";
	cout << "\t\t\t\t10. Print descendents\n";
	cout << "\t\t\t\t11. Get height\n";
	cout << "\t\t\t\t12. Get tree height\n";
	cout << "\t\t\t\t13. Inorder traversal\n";
	cout << "\t\t\t\t14. Preorder traversal\n";
	cout << "\t\t\t\t15. Postorder traversal\n";
	cout << "\t\t\t\t16. Remove node\n";
	cout << "\t\t\t\t17. Exit\n";
}

int main()
{
	ArrayBinaryTree <int> tree(5);
	int choice, node, parent, child, key;
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
		displayMenu();
		tree.inOrder();
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
			cout << "Enter parent: ";
			cin >> parent;
			cout << "Left child: " << tree.getLeftChild(parent) << endl;
			break;
		case 5:
			cout << "Enter parent: ";
			cin >> parent;
			cout << "Right child: " << tree.getRightChild(parent) << endl;
			break;
		case 6:
			cout << "Enter node: ";
			cin >> node;
			cout << "Parent: " << tree.getParent(node) << endl;
			break;
		case 7:
			cout << "Root: " << tree.getRoot() << endl;
			break;
		case 8:
			cout << "Enter key: ";
			cin >> key;
			cout << "Node: " << tree.searchNode(key) << endl;
			break;
		case 9:
			cout << "Enter node: ";
			cin >> node;
			tree.printAncestors(node);
			break;
		case 10:
			cout << "Enter node: ";
			cin >> node;
			tree.printDescendents(node);
			break;
		case 11:
			cout << "Enter node: ";
			cin >> node;
			cout << "Height: " << tree.getHeight(node) << endl;
			break;
		case 12:
			cout << "Tree height: " << tree.getTreeHeight() << endl;
			break;
		case 13:
			cout << "Inorder traversal: ";
			tree.inOrder();
			cout << endl;
			break;
		case 14:
			cout << "Preorder traversal: ";
			tree.preOrder();
			cout << endl;
			break;
		case 15:
			cout << "Postorder traversal: ";
			tree.postOrder();
			cout << endl;
			break;
		case 16:
			cout << "Enter node: ";
			cin >> node;
			tree.remove(node);
			break;
		case 17:
			break;
		default:
			cout << "Invalid choice\n";
		}
		system("pause");
		system("cls");
	} while (choice != 17);
}
