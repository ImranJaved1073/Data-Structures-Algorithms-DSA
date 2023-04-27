#ifndef LSLL_H
#define LSLL_H

#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T info;
    Node<T>* next;

    Node() { next = nullptr; }

    Node(T val)
    {
        info = val;
        next = nullptr;
    }
};

template <typename T>
class LSLL
{
    Node<T>* head;

public:
    class Iterator;
    LSLL() { head = nullptr; }
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
    ~LSLL();
    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};

template <typename T>
class LSLL<T>::Iterator
{
    friend class LSLL;
    Node<T>* current;
    Iterator(Node<T>* ptr = nullptr) : current(ptr) {}

public:
    Iterator& operator++()
    {
        current = current->next;
        return *this;
    }
    Iterator operator++(int)
    {
        Iterator temp = *this;
        current = current->next;
        return temp;
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

// Insert node at the beginning of the list
template <typename T>
void LSLL<T>::insertAtHead(T val)
{
    Node<T>* newNode = new Node<T>(val);
    newNode->next = head;
    head = newNode;
}

// Insert node at the end of the list
template <typename T>
void LSLL<T>::insertAtTail(T val)
{
    if (!head)
    {
        head = new Node<T>(val);
        return;
    }
    Node<T>* current = head;
    while (current->next != nullptr)
        current = current->next;
    current->next = new Node<T>(val);
}

// Insert node after the node with the given value
template <typename T>
void LSLL<T>::insertAfter(T key, T val)
{
    if (!head)
        return;
    Node<T>* newNode = new Node<T>(val);
    Node<T>* current = head;
    while (current != nullptr && current->info != key)
        current = current->next;

    if (!current)
        return;

    newNode->next = current->next;
    current->next = newNode;
}

// Insert node before the node with the given value
template <typename T>
void LSLL<T>::insertBefore(T key, T val)
{
    if (!head)
        return;
    if (head->info == key)
    {
        insertAtHead(val);
        return;
    }
    Node<T>* prev = head;
    Node<T>* after = head->next;
    while (after != nullptr && after->info != key)
    {
        prev = after;
        after = after->next;
    }
    if (after)
    {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = after;
        prev->next = newNode;
    }
}

// Remove the node at the beginning of the list
template <typename T>
void LSLL<T>::removeAtHead()
{
    if (!head)
        return;
    Node<T>* x = head;
    head = head->next;
    delete x;
}

// Remove the node at the end of the list
template <typename T>
void LSLL<T>::removeAtTail()
{
    if (!head)
        return;
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node<T>* current = head;
    while (current->next->next != nullptr)
        current = current->next;
    delete current->next;
    current->next = nullptr;
}

// Remove the node with the given value
template <typename T>
void LSLL<T>::removeAfter(T key)
{
    if (!head)
        return;

    Node<T>* current = head;
    while (current != nullptr && current->info != key)
        current = current->next;
  
    if (!current || !current->next)
		return;

    Node<T>* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

// Remove the node with the given value
template <typename T>
void LSLL<T>::removeBefore(T key)
{
    if (!head || head->next == nullptr)
        return;

    /*if (head->info == key)
        return;*/

    if (head->next->info == key)
    {
        removeAtHead();
        return;
    }

    Node<T>* current = head;
    while (current->next->next != nullptr && current->next->next->info != key)
        current = current->next;

    if (current->next->next == nullptr)
        return;

    Node<T>* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

// Remove the node with the given value
template <typename T>
void LSLL<T>::remove(T key)
{
    if (!head)
		return;

    if (head->info == key)
    {
        removeAtHead();
        return;
    }

    Node<T>* current = head;
    while (current->next != nullptr && current->next->info != key)
        current = current->next;

    if (!current->next)
		return;

    Node<T>* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

template <typename T>
bool LSLL<T>::search(T key)
{
    if (!head)
        return false;

    Node<T>* current = head;
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
void LSLL<T>::printList()
{
    Node<T>* current = head;
    while (current != nullptr)
    {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;
}

template <typename T>
LSLL<T>::~LSLL()
{
    while (head)
        removeAtHead();
    head = nullptr;
}

#endif // !LSLL_H
