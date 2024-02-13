#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
using namespace std;

template <typename T>
class Polynomial;

template <typename T>
class Term
{
	friend Polynomial<T>;
private:
	int exp;
	T coeff;
	Term<T>* next;

public:
	Term() { next = nullptr; }
	Term(T c, int e) { coeff = c; exp = e; next = nullptr; }
};

template <typename T>
class Polynomial
{
private:
	Term<T>* head;
	Term<T>* tail;
	void insertAtLast(T, int);
	void insertAtFirst(T, int);
	void removeAtFirst();
public:
	//Polynomial() { head = tail = nullptr; }
	Polynomial(const initializer_list<pair<T,int>>& = {});
	Polynomial(const Polynomial&);
	Polynomial& operator=(const Polynomial&);
	~Polynomial() { clear(); }
	void addTerm(T, int);
	int getDegree();
	T getCoefficient(int);
	void clear();
	void addToCoefficient(T, int);
	const Polynomial& derivative();
	T evaluate(T);
	Polynomial operator+(const Polynomial&);
	Polynomial operator-(const Polynomial&);
	T operator()(T val) { return evaluate(val); }
	void display();
};

#include "Polynomial.cpp"

#endif // !POLYNOMIAL_H
