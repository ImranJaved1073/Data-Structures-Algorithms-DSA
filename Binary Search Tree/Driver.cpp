#include <iostream>
#include "BST.cpp"

using namespace std;

void Menu()
{
	cout << "1. Insert" << endl;
	cout << "2. Remove" << endl;
	cout << "3. Search" << endl;
	cout << "4. In Order Traversal" << endl;
	cout << "5. Post Order Traversal" << endl;
	cout << "6. Pre Order Traversal" << endl;
	cout << "7. Get Tree Height" << endl;
	cout << "8. Get Height" << endl;
	cout << "9. Get Min" << endl;
	cout << "10. Get Max" << endl;
	cout << "11. Get In Order Successor" << endl;
	cout << "12. Get In Order Predecessor" << endl;
	cout << "13. Get Root" << endl;
	cout << "14. Get Parent" << endl;
	cout << "15. Get Left Child" << endl;
	cout << "16. Get Right Child" << endl;
	cout << "17. Print Ancestors" << endl;
	cout << "18. Print Descendants" << endl;
	cout << "19. Delete Tree" << endl;
	cout << "20. Count Tree Nodes" << endl;
	cout << "21. Count Nodes" << endl;
	cout << "22. Count Leaf Nodes" << endl;
	cout << "23. Count Parent Nodes" << endl;
	cout << "24. Exit" << endl;
}

int main()
{
	BST <int> bst;
	int choice, key;
	bst.insert(100);
	bst.insert(50);
	bst.insert(210);
	bst.insert(40);
	bst.insert(70);
	bst.insert(150);
	bst.insert(300);
	bst.insert(110);
	bst.insert(190);
	bst.insert(170);
	bst.insert(200);
	bst.insert(160);
	bst.insert(180);
	do
	{
		Menu();
		cout << endl;
		bst.inOrderTraversal();
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter key to insert: ";
			cin >> key;
			bst.insert(key);
			break;
		case 2:
			cout << "Enter key to remove: ";
			cin >> key;
			bst.remove(key);
			break;
		case 3:
			cout << "Enter key to search: ";
			cin >> key;
			if (bst.search(key))
				cout << "Found" << endl;
			else
				cout << "Not Found" << endl;
			break;
		case 4:
			bst.inOrderTraversal();
			break;
		case 5:
			bst.postOrderTraversal();
			break;
		case 6:
			bst.preOrderTraversal();
			break;
		case 7:
			cout << "Tree Height: " << bst.getTreeHeight() << endl;
			break;
		case 8:
			cout << "Enter key to get height: ";
			cin >> key;
			cout << "Height: " << bst.getHeight(key) << endl;
			break;
		case 9:
			try
			{
				cout << "Min: " << bst.getMin() << endl;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		case 10:
			try
			{
				cout << "Max: " << bst.getMax() << endl;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		case 11:
			cout << "Enter key to get in order successor: ";
			cin >> key;
			try
			{
				cout << bst.getInOrderSuccessor(key);
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		case 12:
			cout << "Enter key to get in order predecessor: ";
			cin >> key;
			try
			{
				cout << bst.getInOrderPredecessor(key);
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		case 13:
			try
			{
				cout << "Root: " << bst.getRoot() << endl;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		case 14:
			cout << "Enter key to get parent: ";
			cin >> key;
			try
			{
				cout << "Parent: " << bst.getParent(key) << endl;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		case 15:
			cout << "Enter key to get left child: ";
			cin >> key;
			try
			{
				cout << "Left Child: " << bst.getLeftChild(key) << endl;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		case 16:
			cout << "Enter key to get right child: ";
			cin >> key;
			try
			{
				cout << "Right Child: " << bst.getRightChild(key) << endl;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		case 17:
			cout << "Enter key to print ancestors: ";
			cin >> key;
			try
			{
				bst.printAncestors(key);
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		case 18:
			cout << "Enter key to print descendants: ";
			cin >> key;
			try
			{
				bst.printDescendants(key);
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		case 19:
			bst.deleteTree();
			break;
		case 20:
			cout << "Tree Nodes: " << bst.countTreeNodes() << endl;
			break;
		case 21:
			cout << "Enter key to count nodes: ";
			cin >> key;
			cout << "Nodes: " << bst.countNodes(key) << endl;
			break;
		case 22:
			cout << "Leaf Nodes: " << bst.countLeafNodes() << endl;
			break;
		case 23:
			cout << "Parent Nodes: " << bst.countParentNodes() << endl;
			break;
		case 24:
			break;
		default:
			cout << "Invalid Choice" << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (choice != 24);
}