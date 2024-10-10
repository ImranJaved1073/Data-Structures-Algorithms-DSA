#include <iostream>
#include "Queue.h"
#include "Stack.h"

using namespace std;

void sumArrayTriangular(int* arr, int size)
{
	Queue<int> q;
	Stack<Queue<int>> s;
	int sum = 0;
	int tempSize = size - 1;

	for (int i = 0; i < size; i++)
		q.enQueue(arr[i]);
	s.push(q);
	while (!q.isEmpty())
		q.deQueue();
	while (tempSize)
	{
		for (int i = 0; i < tempSize; i++)
		{
			sum = arr[i] + arr[i + 1];
			arr[i] = sum;
			q.enQueue(sum);
		}
		s.push(q);
		while (!q.isEmpty())
			q.deQueue();
		tempSize--;
	}

	while (!s.isEmpty())
	{
		q = s.peek();
		s.pop();
		cout << "[";
		while (!q.isEmpty())
		{
			cout << q.getElementAtFront() << ",";
			q.deQueue();
		}
		cout << "]";
		cout << endl;
	}
}

int main()
{
	int arr[] = { 10, 20, 30, 40, 50 };
	int size = sizeof(arr) / sizeof(arr[0]);

	sumArrayTriangular(arr, size);

}