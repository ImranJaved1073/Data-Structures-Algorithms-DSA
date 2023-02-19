#include <iostream>
#include "RandomizedQueue.h"

using namespace std;

int main()
{
    RandomizedQueue<int> rq;
    rq.enQueue(5);
    rq.enQueue(6);
    rq.enQueue(7);
    rq.enQueue(53);
    rq.enQueue(10);
    rq.enQueue(8);
    rq.enQueue(90);
    rq.enQueue(1);
    rq.enQueue(295);

    cout << rq.sample() << ":" << rq.sample() << ":" << rq.sample() << ":" << rq.sample() << "\n";
    cout << rq.deQueue() << ":" << rq.deQueue() << ":" << rq.deQueue() << "\n";
    cout << rq.sample() << ":" << rq.sample() << ":" << rq.sample() << ":" << rq.sample() << "\n";
    while (!rq.isEmpty())
        cout << rq.deQueue() << ":";
}