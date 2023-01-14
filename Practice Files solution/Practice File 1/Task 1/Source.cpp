#include <iostream>
#include "Set.h"

using namespace std;

void validSetNumber(int& a, int& b, int n)
{
	cout << "Enter first set: ";
	cin >> a;
	while (a > n)
	{
		cout << "Enter valid set number: ";
		cin >> a;
	}
	cout << "Enter second set: ";
	cin >> b;
	while (b > n)
	{
		cout << "Enter valid set number: ";
		cin >> b;
	}
}

int main()
{
	cout << "How many sets you want to create? ";
	int n;
	cin >> n;
	Set<int>* s = new Set<int>[n];
	for (int i = 0; i < n; i++)
	{
		cout << "How many elements you want to insert in set " << i + 1 << "? ";
		int m;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			int temp;
			cout << "Enter element " << j + 1 << ": ";
			cin >> temp;
			s[i].insert(temp);
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Set " << i + 1 << ": ";
		s[i].print();
	}
	int choice;
	do
	{
		system("pause");
		system("cls");
		for (int i = 0; i < n; i++)
		{
			cout << "Set " << i + 1 << ": ";
			s[i].print();
		}
		cout << "1. Union" << endl;
		cout << "2. Intersection" << endl;
		cout << "3. Difference" << endl;
		cout << "4. Subset" << endl;
		cout << "5. Equality" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int a, b;
			validSetNumber(a, b, n);
			Set<int> temp = s[a - 1] + s[b - 1];
			cout << "UNION of set " << a << " and set " << b << " is: ";
			temp.print();
			break;
		}
		case 2:
		{
			int a, b;
			validSetNumber(a, b, n);
			Set<int> temp = s[a - 1].calcIntersection(s[b - 1]);
			cout << "INTERSECTION of set " << a << " and set " << b << " is: ";
			temp.print();
			break;
		}
		case 3:
		{
			int a, b;
			validSetNumber(a, b, n);
			Set<int> temp = s[a - 1] - s[b - 1];
			cout << "DIFFERENCE of set " << a << " and set " << b << " is: ";
			temp.print();
			break;
		}
		case 4:
		{
			int a, b;
			validSetNumber(a, b, n);
			if (s[a - 1].isSubset(s[b - 1]))
				cout << "Set " << a << " is SUBSET of set " << b << endl;
			else
				cout << "Set " << a << " is not SUBSET of set " << b << endl;
			break;
		}
		case 5:
		{
			int a, b;
			validSetNumber(a, b, n);
			if (s[a - 1] == s[b - 1])
				cout << "Set " << a << " is EQUAL to set " << b << endl;
			else
				cout << "Set " << a << " is NOT EQUAL to set " << b << endl;
			break;
		}
		case 6:
			break;
		default:
			cout << "Invalid choice" << endl;
		}
	} while (choice != 6);

}