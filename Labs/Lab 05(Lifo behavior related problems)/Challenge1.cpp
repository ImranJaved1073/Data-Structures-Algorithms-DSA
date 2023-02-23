#include <iostream>
#include "Stack.h"

using namespace std;

void removeNonPrimaryColors(Stack<int> &);

int main()
{
    Stack<int> s;
    // int n;
    // int color;
    // cout << "Enter number of colors: ";
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> color;
    //     s.push(color);
    // }

    s.push(2);
    s.push(5);
    s.push(67);
    s.push(0);
    s.push(3);
    s.push(4);
    s.push(7);
    s.push(7);
    s.push(8);
    s.push(1);
    s.push(2);
    s.push(1);
    s.push(0);
    s.push(5);
    s.push(6);

    removeNonPrimaryColors(s);

    cout << "{";
    while (!s.isEmpty())
    {
        cout << s.pop() << ",";
    }
    cout << "}";
}

void removeNonPrimaryColors(Stack<int> &boxes)
{
    Stack<int> temp;
    int rem;
    while (!boxes.isEmpty())
    {
        rem = boxes.pop();
        if (rem >= 0 && rem <= 2)
        {
            temp.push(rem);
        }
    }
    while (!temp.isEmpty())
    {
        rem = temp.pop();
        boxes.push(rem);
    }
}