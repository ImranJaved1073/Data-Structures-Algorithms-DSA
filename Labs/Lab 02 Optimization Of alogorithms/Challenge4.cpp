#include <iostream>
using namespace std;

int countOfPages(int N)
{
	int count = 0;
	int startDigitPosition = 1;
	int endDigitPosition = 9;
	int decimalDigit = 1;
	while (startDigitPosition <= N)
	{
		count += (min(N, endDigitPosition) - startDigitPosition + 1) * decimalDigit;
		startDigitPosition *= 10;
		endDigitPosition = endDigitPosition * 10 + 9;
		decimalDigit++;
	}
	return count;
}

int main()
{
    int n;
	cin >> n;
	cout << countOfPages(n);
}