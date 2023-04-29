#ifndef LDLL_H
#define LDLL_H // Liner Doubly Linked List

#include <iostream>

using namespace std;

template <typename T>
struct DNode
{
    T info;
    DNode<T>* next;
    DNode<T>* prev;

    DNode() { next = prev = nullptr; }

    DNode(T val)
    {
        info = val;
        next = prev = nullptr;
    }
};

//LDLL = Linear Doubly Linked List
template <typename T>
class LDLL
{
    DNode<T>* head;

public:
    class Iterator;
    LDLL() { head = nullptr; }
    void insertAtHead(T);
    void insertAtTail(T);
    void insertAfter(T, T);
    void insertBefore(T, T);
    void removeAtHead();
    void removeAtTail();
    void removeAfter(T);
    void removeBefore(T);
    void remove(T);
    bool search(T);
    void printList();
    ~LDLL();
    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};

template <typename T>
class LDLL<T>::Iterator
{
	friend class LDLL;
	DNode<T>* current;
	Iterator(DNode<T>* ptr = nullptr) : current(ptr) {}
public:
    Iterator& operator++()
    {
		current = current->next;
		return *this;
	}
    Iterator& operator--()
    {
		current = current->prev;
		return *this;
	}
    bool operator==(const Iterator& rhs) const
    {
		return current == rhs.current;
	}
    bool operator!=(const Iterator& rhs) const
    {
		return current != rhs.current;
	}
    T& operator*()
    {
		return current->info;
	}
};

// Insert DNode at the beginning of the list
template <typename T>
void LDLL<T>::insertAtHead(T val)
{
    DNode<T>* newDNode = new DNode<T>(val);
    if (!head)
    {
        head = newDNode;
        return;
    }
    newDNode->next = head;
    head->prev = newDNode;
    head = newDNode;
}

// Insert DNode at the end of the list
template <typename T>
void LDLL<T>::insertAtTail(T val)
{
    DNode<T>* newDNode = new DNode<T>(val);
    if (!head)
    {
        head = newDNode;
        return;
    }
    DNode<T>* current = head;
    while (current->next != nullptr)
        current = current->next;
    current->next = newDNode;
    newDNode->prev = current;
}

// Insert DNode after the DNode with the given value
template <typename T>
void LDLL<T>::insertAfter(T key, T val)
{
    if (!head)
        return;
    
    DNode<T>* current = head;
    while (current != nullptr && current->info != key)
        current = current->next;

    if (!current)
		return;

    DNode<T>* newDNode = new DNode<T>(val);
    newDNode->next = current->next;
    current->next = newDNode;
    newDNode->prev = current;
    if (newDNode->next != nullptr)
        newDNode->next->prev = newDNode;
}

// Insert DNode before the DNode with the given value
template <typename T>
void LDLL<T>::insertBefore(T key, T val)
{
    if (!head)
        return;
    if (head->info == key)
    {
		insertAtHead(val);
		return;
	}

    DNode<T>* p = head;
    while (p != nullptr && p->info != key)
		p = p->next;

    if (!p)
        return;

    DNode<T>* x = new DNode<T>(val);
    x->next = p;
    p->prev->next = x;
    x->prev = p->prev;
    p->prev = x;
}

// Remove the DNode at the beginning of the list
template <typename T>
void LDLL<T>::removeAtHead()
{
    if (!head)
        return;
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    DNode<T>* temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
}

// Remove the DNode at the end of the list
template <typename T>
void LDLL<T>::removeAtTail()
{
    if (!head)
        return;
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    DNode<T>* current = head;
    while (current->next != nullptr)
        current = current->next;
    current->prev->next = nullptr;
    delete current;
}

// Remove the DNode with the given value
template <typename T>
void LDLL<T>::removeAfter(T key)
{
    if (!head)
		return;

    DNode<T>* current = head;
    while (current != nullptr && current->info != key)
        current = current->next;
    if (!current || !current->next)
		return;

    DNode<T>* temp = current->next;
    current->next = current->next->next;
    if (current->next != nullptr)
		current->next->prev = current;
    delete temp;
}

// Remove the DNode with the given value
template <typename T>
void LDLL<T>::removeBefore(T key)
{
    if(!head || !head->next)
		return;

    if (head->next->info == key)
    {
        removeAtHead();
        return;
    }

    DNode<T>* current = head;
    while(current != nullptr && current->info != key)
		current = current->next;
    if (!current) return;

    DNode<T>* x = current->prev;
    x->prev->next = current;
    current->prev = x->prev;
    delete x;
}

// Remove the DNode with the given value
template <typename T>
void LDLL<T>::remove(T key)
{
    if (!head)
        return;
    if (head->info == key)
    {
        removeAtHead();
        return;
    }
    DNode<T>* current = head;
    while (current->next != nullptr && current->next->info != key)
        current = current->next;

    if (!current->next)
		return;

    DNode<T>* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

template <typename T>
bool LDLL<T>::search(T key)
{
    if (!head)
        return false;
    DNode<T>* current = head;
    while (current != nullptr)
    {
        if (current->info == key)
            return true;
        current = current->next;
    }
    return false;
}

// Print the contents of the linked list
template <typename T>
void LDLL<T>::printList()
{
    if (!head)
        return;
    DNode<T>* current = head;
   // DNode<T>* tail = head;
    while (current != nullptr)
    {
        cout << current->info << " ";
        //tail = current;
        current = current->next;
    }
    cout << endl;
 //   while (tail != nullptr)
 //   {
	//	cout << tail->info << " ";
	//	tail = tail->prev;
	//}
 //   cout << endl;
}

template <typename T>
LDLL<T>::~LDLL()
{
    while (head)
        removeAtHead();
    head = nullptr;
}

#endif // !LDLL_H