#include <iostream>
#include "Stack.h"
#include "GenericArray.h"
using namespace std;

template <typename T>
class UndoArray
{
private:
    unsigned int size;
    GenericArray<Stack<T>> values;

public:
    UndoArray():size(0),values(0){}

    UndoArray(unsigned int size):size(size),values(size){}

    int getSize()
    {
        return size;
    }

    void set(unsigned int index, T element)
    {
        if (index >= size)
            exit(0);
        values[index].push(element);
    }

    T get(unsigned int index)
    {
        if (index >= size)
            exit(0);
        return values[index].stackTop();
    }

    T operator[](unsigned int index)
    {
        if (index >= size)
            exit(0);
        return values[index].getNumberOfElements();
    }

    void undo(unsigned int index)
    {
        if (index >= size)
            exit(0);
        values[index].pop();
    }

    ~UndoArray()
    {
        size = 0;
    }
};

int main()
{
    UndoArray<int> u(5);
    cout << u.getSize()<<endl;
    u.set(0, 12);
    u.set(0, 45);
    u.set(2, 68);
    u.set(0, 783);
    u.set(3,33);
    u.undo(0);
    u.undo(0);
    u.set(0, 191);
    cout << u.get(0)<<endl;
    cout<<u[0];
}