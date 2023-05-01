#ifndef CDLL_H // Circular Doubly Linked List
#define CDLL_H

#include <iostream>

using namespace std;

template <typename T>
class DNode {
public:
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

// Circular Doubly Linked List(CDLL)
template <typename T>
class CDLL {

	DNode<T>* head;
	bool isEmpty() { return head == nullptr; }

public:

	CDLL() { head = nullptr; }
	void insertAtHead(T);
	void insertAtTail(T);
	void removeAtHead();
	void removeAtTail();
	void remove(T);
	void removeBefore(T);
	void removeAfter(T);
	void insertAfter(T, T);
	void insertBefore(T, T);
	bool search(T);
	void printList();
	void printReverseList();
	~CDLL();
};

template<typename T>
void CDLL<T>::insertAtHead(T val)
{
	if (isEmpty())
	{
		head->next = head->prev = head = new DNode<T>(val);
		return;
	}

	DNode<T>* newHead = new DNode<T>(val);
	newHead->next = head;
	newHead->prev = head->prev;
	head->prev->next = newHead;
	head->prev = newHead;
	head = newHead;
}

template<typename T>
void CDLL<T>::insertAtTail(T val)
{
	if (isEmpty())
	{
		head->next = head->prev = head = new DNode<T>(val);
		return;
	}
	DNode<T>* newTail = new DNode<T>(val);
	newTail->next = head;
	newTail->prev = head->prev;
	head->prev->next = newTail;
	head->prev = newTail;
}

template<typename T>
void CDLL<T>::removeAtHead()
{
	if (isEmpty()) return;
	if (head == head->next)
	{
		delete head;
		head = nullptr;
		return;
	}
	DNode<T>* oldHead = head;
	head->prev->next = head->next;
	head->next->prev = head->prev;
	head = head->next;
	delete oldHead;
	oldHead = nullptr;
}

template<typename T>
void CDLL<T>::removeAtTail()
{
	if (isEmpty()) return;
	if (head == head->next)
	{
		delete head;
		head = nullptr;
		return;
	}
	DNode<T>* oldTail = head->prev;
	oldTail->prev->next = oldTail->next;
	oldTail->next->prev = oldTail->prev;
	delete oldTail;
	oldTail = nullptr;
}

template<typename T>
void CDLL<T>::insertAfter(T key, T val)
{
	if (isEmpty()) return;
	
	DNode<T>* p = head;
	do
	{
		if (p->info == key)
		{
			DNode<T>* newNode = new DNode<T>(val);
			newNode->next = p->next;
			newNode->prev = p;
			p->next->prev = newNode;
			p->next = newNode;
			return;
		}
		p = p->next;
	} 
	while (p != head);
}

template<typename T>
void CDLL<T>::removeAfter(T key)
{
	if (isEmpty() || head->next == head) return;

	else if (head->prev->info == key)
	{
		removeAtHead();
		return;
	}

	DNode<T>* p = head;
	do
	{
		if (p->info == key)
		{
			DNode<T>* toDelNode = p->next;
			p->next = toDelNode->next;
			toDelNode->next->prev = p;
			delete toDelNode;
			toDelNode = nullptr;
			return;
		}
		p = p->next;
	} while (p != head);
}

template<typename T>
void CDLL<T>::insertBefore(T key, T val)
{
	if (isEmpty()) return;
	if (head->info == key)
	{
		insertAtHead(val); 
		return;
	}

	DNode<T>* p = head;
	do
	{
		if (p->info == key)
		{
			DNode<T>* newNode = new DNode<T>(val);
			newNode->next = p;
			newNode->prev = p->prev;
			p->prev->next = newNode;
			p->prev = newNode;
			return;
		}
		p = p->next;
	} while (p != head);
}

template<typename T>
void CDLL<T>::removeBefore(T key)
{
	if (isEmpty() || head->next == head) return;
	
	else if (head->next->info == key)
	{
		removeAtHead();
		return;
	}

	DNode<T>* p = head;
	do
	{
		if (p->info == key)
		{
			DNode<T>* toDelNode = p->prev;
			toDelNode->prev->next = p;
			p->prev = toDelNode->prev;
			delete toDelNode;
			toDelNode = nullptr;
			return;
		}
		p = p->next;
	} while (p != head);
}

template<typename T>
void CDLL<T>::remove(T key)
{
	if (isEmpty()) return;

	else if (head->info == key)
	{
		removeAtHead();
		return;
	}

	DNode<T>* p = head;
	do
	{
		if (p->info == key)
		{
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			p = nullptr;
			return;
		}
		p = p->next;
	} while (p != head);
}

template<typename T>
bool CDLL<T>::search(T key)
{
	if (isEmpty()) exit(0);

	DNode<T>* p = head;
	do
	{
		if (p->info == key)
			return true;
		p = p->next;
	} while (p != head);
	return false;
}

template<typename T>
void CDLL<T>::printList()
{
	if (isEmpty()) exit(0);

	DNode<T>* p = head;
	do
	{
		cout << p->info << ":";
		p = p->next;
	} 
	while (p != head);
}

template<typename T>
void CDLL<T>::printReverseList()
{
	if (isEmpty()) exit(0);

	DNode<T>* p = head->prev;
	do
	{
		cout << p->info << ":";
		p = p->prev;
	} while (p != head->prev);
}

template <typename T>
CDLL<T>::~CDLL()
{
	while (head)
		removeAtHead();
	head = nullptr;
}

#endif // !CDLL_H
