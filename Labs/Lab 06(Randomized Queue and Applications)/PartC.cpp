#include <iostream>
#include <string>
#include <initializer_list>
#include "RandomizedQueue.h"

using namespace std;

class Permutation
{
public:
    static void printKItemsRandomly(initializer_list<string> list, int a)
    {
        if (a > list.size())
            return;
        RandomizedQueue<string> rq;
        for (auto i : list)
            rq.enQueue(i);
        for (int i = 0; i < a; i++)
            cout << rq.deQueue() << " ";
        cout << endl;
    }
};

int main()
{
    Permutation::printKItemsRandomly({"aslam", "jerry", "tom", "javed", "babar"}, 3);
    Permutation::printKItemsRandomly({"aslam", "jerry", "tom", "javed", "babar"}, 3);
    Permutation::printKItemsRandomly({"aslam", "jerry", "tom", "javed", "babar"}, 5);
}