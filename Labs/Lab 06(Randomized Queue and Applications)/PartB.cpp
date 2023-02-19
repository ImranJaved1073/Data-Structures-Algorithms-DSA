#include <iostream>
#include "RandomizedQueue.h"

using namespace std;

int main()
{
    {// Sample Run 1
        RandomizedQueue<int> rq;
        rq.enQueue(1);
        rq.enQueue(2);
        rq.enQueue(3);
        rq.enQueue(4);
        rq.enQueue(5);
        rq.enQueue(6);
        rq.enQueue(7);
        rq.enQueue(8);
        rq.enQueue(9);

        RandomizedQueue<int>::Iterator i(rq);
        RandomizedQueue<int>::Iterator j(rq);
        while (i.hasNext())
        {
            cout << *i << ",";
            ++i;
        }
        cout << endl;
        while (j.hasNext())
        {
            cout << *j << ",";
            ++j;
        }
        cout << *i;
    }

    {// Sample Run 2
        RandomizedQueue<int> rq;
        rq.enQueue(1);
        rq.enQueue(2);
        rq.enQueue(3);
        rq.enQueue(4);
        rq.enQueue(5);
        rq.enQueue(6);
        rq.enQueue(7);
        rq.enQueue(8);
        rq.enQueue(9);
        rq.enQueue(10);

        RandomizedQueue<int>::Iterator i(rq);
        cout << rq.deQueue() << ':' << rq.deQueue() << '\n';
        while (i.hasNext())
        {
            cout << *i << ",";
            ++i;
        }

        RandomizedQueue<int>::Iterator j(rq);
        cout << endl;
        while (j.hasNext())
        {
            cout << *j << ",";
            ++j;
        }
    }
}