#include <iostream>
#include "Queue.h"

using namespace std;

void pagingFIFOAlgo(int queueSize)
{
   Queue<int> pgingQueue;
   int pgFault = 0, pgHit = 0;

   bool status = true;

   cout << "--------------------------------------------------\n";
   cout << "FIFO PAGE REPLACEMENT ALGORITHM BEGINS\n";
   cout << "TO EXIT THE ALGORITHM JUST ENTER -1\n";
   cout << "--------------------------------------------------\n";

   while (status)
   {
       int pgNum;
       //cout << "\n_________________________________________________________________________\n";
       cout << "\nEnter the page number you want to load into the queue: ";
       cin >> pgNum;

       if (pgNum == -1)
           status = false;

       else if (pgingQueue.search(pgNum))
       {
           pgHit++;
           cout << "Page " << pgNum << " is already exists in memory,i.e;\"Page is Hit\"\n";
       }
       else
       {
           //if (pgNum > 0)
           //{
           if (pgingQueue.getNoOfElements() == queueSize)
               pgingQueue.deQueue();
           pgFault++;
           pgingQueue.enQueue(pgNum);
           cout << "Page " << pgNum << " is a \"Page Fault\" and has loaded in the memory\n";
           //}
       }

       cout << "Now Memory Paging Queue is: ";
       Queue<int> tempQ = pgingQueue;
       while (!tempQ.isEmpty())
           cout << tempQ.deQueue() << " ";

       cout << "\n_________________________________________________________________________\n";
   }

   cout << "--------------------------------------------------\n";
   cout << "Total number of page faults: " << pgFault << "\n";
   cout << "Total number of page hits: " << pgHit << "\n";
   cout << "--------------------------------------------------\n";
}

int main() 
{
   int size;
   cout << "Enter the size of memory queue: ";
   cin >> size;

   pagingFIFOAlgo(size);

   return 0;
}
