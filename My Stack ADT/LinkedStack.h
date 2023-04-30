#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

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
class LinkedStack
{
    Node<T>* head;
    int noOfElements;

public:
	class Iterator;
    LinkedStack() { head = nullptr; noOfElements = 0; }
    LinkedStack (const LinkedStack<T>&);
    LinkedStack<T>& operator=(const LinkedStack<T>&);
	void push(T);
	T pop();
	T stackTop();
	bool isEmpty();
    int getNumberOfElements();
	void printStack();
	~LinkedStack();
	Iterator begin() { return Iterator(head); }
	Iterator end() { return Iterator(nullptr); }
};

template <typename T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& other)
{
	head = nullptr;
	noOfElements = 0;
	Node<T>* temp = other.head;
    while (temp != nullptr)
    {
		push(temp->info);
		temp = temp->next;
	}
}

template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& other)
{
    if (this != &other)
    {
		Node<T>* temp = head;
        while (temp != nullptr)
        {
			Node<T>* temp2 = temp;
			temp = temp->next;
			delete temp2;
		}
		head = nullptr;
		noOfElements = 0;
		temp = other.head;
		while (temp != nullptr)
		{
			push(temp->info);
			temp = temp->next;
		}
	}
	return *this;
}

template <typename T>
void LinkedStack<T>::push(T val)
{
	Node<T>* newNode = new Node<T>(val);
	newNode->next = head;
	head = newNode;
	noOfElements++;
}

template <typename T>
T LinkedStack<T>::pop()
{
	if (isEmpty()) exit(0);

	Node<T>* temp = head;
	head = head->next;
	T val = temp->info;
	delete temp;
	noOfElements--;
	return val;
}

template <typename T>
T LinkedStack<T>::stackTop()
{
	if (isEmpty()) exit(0);
	return head->info;
}

template <typename T>
bool LinkedStack<T>::isEmpty()
{
	return head == nullptr;
}

template <typename T>
int LinkedStack<T>::getNumberOfElements()
{
	return noOfElements;
}

template <typename T>
void LinkedStack<T>::printStack()
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
LinkedStack<T>::~LinkedStack()
{
	Node<T>* temp = head;
	while (temp != nullptr)
	{
		Node<T>* temp2 = temp;
		temp = temp->next;
		delete temp2;
	}
	head = nullptr;
	noOfElements = 0;
}

template <typename T>
class LinkedStack<T>::Iterator
{
	Node<T>* current;
	friend class LinkedStack<T>;
	Iterator (Node<T>* ptr) : current(ptr) {}

public:
	Iterator& operator++() 
	{ 
		if (current != nullptr)
			current = current->next;
		return *this;
	}
	bool operator==(const Iterator& other) { return current == other.current; }
	bool operator!=(const Iterator& other) { return current != other.current; }
	T operator*() { return current->info; }
};

#endif // !LINKEDSTACK_H
