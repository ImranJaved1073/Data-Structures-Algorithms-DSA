#include <iostream>
#include "Queue.h"
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;
	Queue<string> bns;
	bns.enQueue("1");
	for (int i = 0; i < N; i++)
	{
		string front = bns.deQueue();
		cout << front << " ";
		bns.enQueue(front + "0");
		bns.enQueue(front + "1");
	}
	while (!bns.isEmpty())
	{
		bns.deQueue();
	}
	
	/*front = bns.deQueue();
	cout << front << " ";
	bns.enQueue(front + "0");
	bns.enQueue(front + "1");

	front = bns.deQueue();
	cout << front << " ";
	bns.enQueue(front + "0");
	bns.enQueue(front + "1");

	front = bns.deQueue();
	cout << front << " ";
	bns.enQueue(front + "0");
	bns.enQueue(front + "1");

	front = bns.deQueue();
	cout << front << " ";
	bns.enQueue(front + "0");
	bns.enQueue(front + "1");*/

}