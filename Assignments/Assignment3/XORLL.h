#ifndef XORLL_H
#define XORLL_H

#include <iostream>
using namespace std;

template <class T>
class XORLL;

template <class T>
class Node 
{
	friend XORLL<T>;
	int data;
	Node* npx;

public:
	Node(){ npx = nullptr; }
	Node(int val)
	{
		data = val;
		npx = nullptr;
	}
};

template <class T>
class XORLL
{
	Node<T>* head;
	Node<T>* tail;

public:
	XORLL() { head = tail = nullptr; }
    ~XORLL()
    {
        Node<T>* current = head;
        Node<T>* prev = nullptr;
        Node<T>* next;
        while (current)
        {
            next = (Node<T>*)((uintptr_t)(prev) ^ (uintptr_t)(current->npx));
            prev = current;
            delete current;
            current = next;
        }
    }

	
    void insertAtHead(T val)
    {
        Node<T>* newNode = new Node<T>(val);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->npx = head;
            head->npx = (Node<T>*)((uintptr_t)(head->npx) ^ (uintptr_t)(newNode));
            head = newNode;
        }
    }

    void insertAtTail(T val)
	{
		Node<T>* newNode = new Node<T>(val);
		if (!head)
		{
			head = tail = newNode;
		}
		else
		{
			newNode->npx = tail;
			tail->npx = (Node<T>*)((uintptr_t)(tail->npx) ^ (uintptr_t)(newNode));
			tail = newNode;
		}
	}

    void insertAfter(T key, int val)
    {
        Node<T>* current = head;
        while (current && current->data != key) {
            current = current->npx;
        }
        if (!current) {
            return;
        }
        Node<T>* newNode = new Node<T>(val);
        newNode->npx = current->npx;
        current->npx = (Node<T>*)((uintptr_t)(current->npx) ^ (uintptr_t)(newNode));
        if (newNode->npx) {
            newNode->npx = (Node<T>*)((uintptr_t)(newNode->npx) ^ (uintptr_t)(current));
        }
    }

  void deleteBefore( T key)
	{
		Node<T>* current = head;
		Node<T>* prev = nullptr;
		Node<T>* next;
		while (current && current->data != key)
		{
			next = (Node<T>*)((uintptr_t)(prev) ^ (uintptr_t)(current->npx));
			prev = current;
			current = next;
		}

		if (!current || !prev) return;

		Node<T>* prevPrev = (Node<T>*)((uintptr_t)(prev->npx) ^ (uintptr_t)(current));
		prevPrev->npx = (Node<T>*)((uintptr_t)(prevPrev->npx) ^ (uintptr_t)(prev) ^ (uintptr_t)(current));
		if (!prevPrev->npx) tail = prevPrev;
		delete prev;
	}

   
    T deleteAtHead()
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return -1;
        }
        Node<T>* current = head;
        Node<T>* next = (Node<T>*)((uintptr_t)(head->npx) ^ (uintptr_t)(nullptr));
        if (next)
        {
            next->npx = (Node<T>*)((uintptr_t)(next->npx) ^ (uintptr_t)(head));
        }
        head = next;
        int data = current->data;
        delete current;
        return data;
    }

    
    T deleteAtTail()
    {
		if (!tail)
		{
			cout << "List is empty!" << endl;
			return -1;
		}
		Node<T>* current = tail;
		Node<T>* prev = (Node<T>*)((uintptr_t)(tail->npx) ^ (uintptr_t)(nullptr));
		if (prev)
		{
			prev->npx = (Node<T>*)((uintptr_t)(prev->npx) ^ (uintptr_t)(tail));
		}
		tail = prev;
		int data = current->data;
		delete current;
		return data;
    }

    void printList()
    {
		Node<T>* current = head;
		Node<T>* prev = nullptr;
		Node<T>* next;
		cout << "NULL<-";
        while (current)
        {
            cout << current->data << "<->";
            next = (Node<T>*)((uintptr_t)(prev) ^ (uintptr_t)(current->npx));
            prev = current;
            current = next;
        }
        cout << "NULL" << endl;
    }

    void printListReverse()
    {
        Node<T>* current = tail;
        Node<T>* prev = nullptr;
        Node<T>* next;
        cout << "NULL<-";
        while (current)
        {
            cout << current->data << "<->";
            next = (Node<T>*)((uintptr_t)(prev) ^ (uintptr_t)(current->npx));
            prev = current;
            current = next;
        }
        cout << "NULL" << endl;
    }


};



#endif // !XORLL_H