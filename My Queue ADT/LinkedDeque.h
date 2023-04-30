#ifndef LINKEDDEQUE
#define LINKEDDEQUE

#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	T info;
	Node<T>* next;
	Node<T>* prev;
	Node() { next = prev = nullptr; }
	Node(T val)
	{
		info = val;
		next = prev = nullptr;
	}
};

template <typename T>
class LinkedDeque
{
	Node<T>* head;
	Node<T>* tail;
	int noOfElements;

public:
class Iterator;
	LinkedDeque() { head = tail = nullptr; noOfElements = 0; }
	LinkedDeque(const LinkedDeque<T>&);
	LinkedDeque<T>& operator=(const LinkedDeque<T>&);
	void enqueueAtFront(T);
	void enqueueAtBack(T);
	T dequeueAtFront();
	T dequeueAtBack();
	T getElementAtFront() const;
	T getElementAtBack() const;
	bool isEmpty() const { return head == nullptr; }
	int getNumberOfElements() const { return noOfElements; }
	void printDeque();
	~LinkedDeque();
	Iterator begin() { return Iterator(head); }
	Iterator end() { return Iterator(nullptr); }
};

template <typename T>
LinkedDeque<T>::LinkedDeque(const LinkedDeque<T>& other)
{
	head = tail = nullptr;
	noOfElements = 0;
	Node<T>* temp = other.head;
	while (temp != nullptr)
	{
		enqueueAtBack(temp->info);
		temp = temp->next;
	}
}

template <typename T>
LinkedDeque<T>& LinkedDeque<T>::operator=(const LinkedDeque<T>& other)
{
	if (this != &other)
	{
		while (!isEmpty())
			dequeueAtFront();
		Node<T>* temp = other.head;
		while (temp != nullptr)
		{
			enqueueAtBack(temp->info);
			temp = temp->next;
		}
	}
	return *this;
}

template <typename T>
void LinkedDeque<T>::enqueueAtFront(T val)
{
	Node<T>* newNode = new Node<T>(val);
	if (isEmpty())
	{
		head = tail = newNode;
		noOfElements++;
		return;
	}
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
	noOfElements++;
}

template <typename T>
void LinkedDeque<T>::enqueueAtBack(T val)
{
	Node<T>* newNode = new Node<T>(val);
	if (isEmpty())
	{
		head = tail = newNode;
		noOfElements++;
		return;
	}
	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;
	noOfElements++;
}

template <typename T>
T LinkedDeque<T>::dequeueAtFront()
{
	if (isEmpty())
		exit(0);
	T val = head->info;
	if (head == tail)
	{
		delete head;
		head = tail = nullptr;
		noOfElements--;
		return val;
	}
	Node<T>* temp = head;
	head = head->next;
	head->prev = nullptr;
	delete temp;
	temp = nullptr;
	noOfElements--;
	return val;
}

template <typename T>
T LinkedDeque<T>::dequeueAtBack()
{
	if (isEmpty())
		exit(0);
	T val = tail->info;
	if (head == tail)
	{
		delete head;
		head = tail = nullptr;
		noOfElements--;
		return val;
	}
	Node<T>* temp = tail;
	tail = tail->prev;
	tail->next = nullptr;
	delete temp;
	temp = nullptr;
	noOfElements--;
	return val;
}

template <typename T>
T LinkedDeque<T>::getElementAtFront() const
{
	if (isEmpty())
		exit(0);
	return head->info;
}

template <typename T>
T LinkedDeque<T>::getElementAtBack() const
{
	if (isEmpty())
		exit(0);
	return tail->info;
}

template <typename T>
void LinkedDeque<T>::printDeque()
{
	if (isEmpty())
	{
		cout << "Deque is empty!" << endl;
		return;
	}
	Node<T>* temp = head;
	while (temp != nullptr)
	{
		cout << temp->info << " ";
		temp = temp->next;
	}
	cout << endl;
}

template <typename T>
LinkedDeque<T>::~LinkedDeque()
{
	while (!isEmpty())
		dequeueAtFront();
	head = tail = nullptr;
}

template <typename T>
class LinkedDeque<T>::Iterator
{
	Node<T>* current;
	friend class LinkedDeque<T>;
	Iterator(Node<T>* ptr) : current(ptr) {}
public:
	Iterator& operator++()
	{
		if (current == nullptr)
			exit(0);
		current = current->next;
		return *this;
	}
	Iterator operator++(int)
	{
		Iterator temp = *this;
		++(*this);
		return temp;
	}
	Iterator& operator--()
	{
		if (current == nullptr)
			exit(0);
		current = current->prev;
		return *this;
	}
	Iterator operator--(int)
	{
		Iterator temp = *this;
		--(*this);
		return temp;
	}
	T operator*() const
	{
		if (current == nullptr)
			exit(0);
		return current->info;
	}
	bool operator==(const Iterator& other) const { return current == other.current; }
	bool operator!=(const Iterator& other) const { return current != other.current; }
};

#endif // !LINKEDDEQUE

