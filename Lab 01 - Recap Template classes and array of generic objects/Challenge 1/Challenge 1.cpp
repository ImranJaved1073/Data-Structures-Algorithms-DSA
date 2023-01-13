#include <iostream>
#include <string>
#include "GenericDictionary.h"

using namespace std;

int main()
{
	GenericDictionary<string, int> grocery;
	cout << "Grocery List";
	cout << "\n=====================\n";
	grocery.addPair("Oranges", 12);
	grocery.addPair("Apples", 18);
	grocery.addPair("Bananas", 78);
	grocery.addPair("Apricot",316);

	grocery.print();

	cout << "\nGrocery List After Modification";
	cout << "\n=========================================\n";
	grocery.addPair("Apples", 9);
	grocery.print();
	
	cout << '\n' << grocery.getValue("Apples") << endl;
	cout << '\n' << grocery.getValue("Mangoes") << endl;
}
	