#ifndef CSLL_H // Circular Singly Linked List
#define CSLL_H

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

// Circular Singly Linked List(CSLL)
template <typename T>
class CSLL
{
    Node<T>* tail;

public:
    class Iterator;
    CSLL() { tail = nullptr; }
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
    ~CSLL();
    Iterator begin(){ return Iterator(tail->next); }
    Iterator end() { return Iterator(tail); }
};

template <typename T>
class CSLL<T>::Iterator
{
    Node<T>* current;
    friend class CSLL<T>;
    Iterator(Node<T>* ptr = nullptr) : current(ptr) {}

public:
    Iterator& operator++()
    {
        if (current != nullptr)
            current = current->next;
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

template <typename T>
void CSLL<T>::insertAtHead(T val)
{
	Node<T>* newNode = new Node<T>(val);
    if (tail == nullptr)
    {
		tail = newNode;
		tail->next = tail;
	}
    else
    {
		newNode->next = tail->next;
		tail->next = newNode;
	}
}

template <typename T>
void CSLL<T>::insertAtTail(T val)
{
	Node<T>* newNode = new Node<T>(val);
    if (tail == nullptr)
    {
		tail = newNode;
		tail->next = tail;
	}
    else
    {
		newNode->next = tail->next;
		tail->next = newNode;
		tail = newNode;
	}
}

template <typename T>
void CSLL<T>::insertAfter(T key, T val)
{
	Node<T>* newNode = new Node<T>(val);
	if (!tail)
		return;

	Node<T>* temp = tail->next;
	while (temp != tail && temp->info != key)
		temp = temp->next;

	if (temp->info != key)
		return;
	newNode->next = temp->next;
	temp->next = newNode;
	if (temp == tail)
		tail = newNode;
}

template <typename T>
void CSLL<T>::insertBefore(T key, T val)
{
	Node<T>* newNode = new Node<T>(val);
	if (!tail) return;
	Node<T>* p = tail->next;
	while (p != tail && p->next->info != key)
		p = p->next;
	if (p->next->info != key)
		return;
	newNode->next = p->next;
	p->next = newNode;
}

template <typename T>
void CSLL<T>::removeAtHead()
{
	if (!tail) return;

	Node<T>* p = tail->next;
	if (p == tail)
	{
		delete p;
		tail = nullptr;
		return;
	}
	tail->next = p->next;
	delete p;
}

template <typename T>
void CSLL<T>::removeAtTail()
{
	if (!tail) return;

	Node<T>* p = tail->next;
	if (p == tail)
	{
		delete p;
		tail = nullptr;
		return;
	}
	while (p->next != tail)
		p = p->next;
	p->next = tail->next;
	delete tail;
	tail = p;
}

template <typename T>
void CSLL<T>::removeAfter(T key)
{
	if (!tail) return;

	Node<T>* p = tail->next;
	while (p != tail && p->info != key)
		p = p->next;
	if (p->info != key) return;

	Node<T>* temp = p->next;
	p->next = temp->next;
	if (temp == tail)
		tail = p;
	delete temp;
}

template <typename T>
void CSLL<T>::removeBefore(T key)
{
	if (!tail) return;

	Node<T>* p = tail->next;

	if (p->next->info == key)
	{
		removeAtHead();
		return;
	}

	while (p->next->next != tail && p->next->next->info != key)
		p = p->next;

	if (p->next->next->info != key)
		return;
	Node<T>* temp = p->next;
	p->next = temp->next;
	delete temp;
}

template <typename T>
void CSLL<T>::remove(T key)
{
	if (!tail) return;

	Node<T>* p = tail->next;
	if (p->info == key)
	{
		removeAtHead();
		return;
	}
	while (p->next != tail && p->next->info != key)
		p = p->next;
	if (p->next->info != key)
		return;
	Node<T>* temp = p->next;
	p->next = temp->next;
	if (temp == tail)
		tail = p;
	delete temp;
}

template <typename T>
void CSLL<T>::printList()
{
	if (!tail) return;

	Node<T>* p = tail->next;
	do
	{
		cout << p->info << " ";
		p = p->next;
	} while (p != tail->next);

}

template <typename T>
bool CSLL<T>::search(T key)
{
	if (!tail) return false;

	Node<T>* p = tail->next;
	do
	{
		if (p->info == key)
			return true;
		p = p->next;
	} while (p != tail->next);
	return false;
}

template <typename T>
CSLL<T>::~CSLL()
{
	if (!tail) return;
	Node<T>* p = tail->next;
	while (p != tail)
	{
		Node<T>* temp = p;
		p = p->next;
		delete temp;
	}
	delete tail;
	tail = nullptr;
}

#endif // !CSLL_H
