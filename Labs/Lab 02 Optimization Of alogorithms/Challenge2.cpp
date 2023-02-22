#include <iostream>
#include <string>

using namespace std;

string removeDuplicateSymbols(string a)
{
	string temp;
	int countArr[256] = { 0 };
	for (int i = 0; a[i] != '\0'; i++)
	{
		if (countArr[a[i]] == 0)
		{
			temp += a[i];
			countArr[a[i]]++;
		}
	}
	return temp;
}

int main()
{
	string s;
	cin >> s;
	s = removeDuplicateSymbols(s);
	cout << s;
}