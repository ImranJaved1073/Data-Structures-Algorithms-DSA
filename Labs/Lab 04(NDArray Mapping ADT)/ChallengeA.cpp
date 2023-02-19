#include <iostream>
using namespace std;

void printColMajND(int n)
{
    for (int i = n; i > 1; i--)
    {
        cout << "I" << i;
        for (int j = i - 1; j >= 1; j--)
        {
            cout << "*D" << j;
        }
        cout << " + ";
    }
    cout << "I1";
}

int main()
{
    printColMajND(1);
    cout << endl;
    printColMajND(2);
    cout << endl;
    printColMajND(5);
    cout << endl;
    printColMajND(4);
}
