#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

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
class LinkedQueue
{
	Node<T>* head;
	Node<T>* tail;
	int noOfElements;

public:
	class Iterator;
	LinkedQueue() { head = tail = nullptr; noOfElements = 0; }
	LinkedQueue(const LinkedQueue<T>&);
	LinkedQueue<T>& operator=(const LinkedQueue<T>&);
	void enqueue(T);
	T dequeue();
	T getElementAtFront() const;
	bool isEmpty() const;
	int getNumberOfElements() const;
	void printQueue();
	~LinkedQueue();
	Iterator begin() { return Iterator(head); }
	Iterator end() { return Iterator(nullptr); }
};

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& other)
{
	head = tail = nullptr;
	noOfElements = 0;
	Node<T>* temp = other.head;
	while (temp != nullptr)
	{
		enqueue(temp->info);
		temp = temp->next;
	}
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& other)
{
	if (this != &other)
	{
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			Node<T>* toDelete = temp;
			temp = temp->next;
			delete toDelete;
		}
		head = tail = nullptr;
		noOfElements = 0;
		temp = other.head;
		while (temp != nullptr)
		{
			enqueue(temp->info);
			temp = temp->next;
		}
	}
	return *this;
}

template <typename T>
void LinkedQueue<T>::enqueue(T val)
{
	Node<T>* newNode = new Node<T>(val);
	if (isEmpty())
	{
		head = tail = newNode;
		noOfElements++;
		return;
	}
	tail->next = newNode;
	tail = newNode;
	noOfElements++;
}

template <typename T>
T LinkedQueue<T>::dequeue()
{
	if (!isEmpty())
	{
		Node<T>* toDelete = head;
		T val = head->info;
		head = head->next;
		delete toDelete;
		noOfElements--;
		return val;
	}
}

template <typename T>
T LinkedQueue<T>::getElementAtFront() const
{
	if (!isEmpty())
		return head->info;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const
{
	return head == nullptr;
}

template <typename T>
int LinkedQueue<T>::getNumberOfElements() const
{
	return noOfElements;
}

template <typename T>
void LinkedQueue<T>::printQueue()
{
	Node<T>* temp = head;
	while (temp != nullptr)
	{
		cout << temp->info << " ";
		temp = temp->next;
	}
	cout << endl;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
	Node<T>* temp = head;
	while (temp != nullptr)
	{
		Node<T>* toDelete = temp;
		temp = temp->next;
		delete toDelete;
	}
}

template <typename T>
class LinkedQueue<T>::Iterator
{
	Node<T>* current;
	friend class LinkedQueue<T>;
	Iterator(Node<T>* ptr = nullptr) : current(ptr) {}

public:
	Iterator& operator++()
	{
		if (current != nullptr)
			current = current->next;
		return *this;
	}
	bool operator==(const Iterator& rhs) const { return current == rhs.current; }
	bool operator!=(const Iterator& rhs) const { return  current != rhs.current; }
	T operator*() { return current->info; }
};

#endif // !LINKEDQUEUE_H


