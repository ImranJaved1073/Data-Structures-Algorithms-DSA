#ifndef POLYNOMIAL_CPP
#define POLYNOMIAL_CPP

#include "Polynomial.h"

template <typename T>
Polynomial<T>::Polynomial(const initializer_list<pair<T, int>>& list)
{
	if (list.size() == 0)
	{
		head = tail = nullptr;
		return;
	}
	head = tail = nullptr;
	for (auto& p : list)
		addTerm(p.first, p.second);
}

template <typename T>
Polynomial<T>::Polynomial(const Polynomial& p)
{
	head = tail = nullptr;
	Term<T>* p1 = p.head;
	while (p1)
	{
		addTerm(p1->coeff, p1->exp);
		p1 = p1->next;
	}
}

template <typename T>
Polynomial<T>& Polynomial<T>::operator=(const Polynomial& p)
{
	if (this == &p) return *this;
	clear();
	Term<T>* p1 = p.head;
	while (p1)
	{
		addTerm(p1->coeff, p1->exp);
		p1 = p1->next;
	}
	return *this;
}

template <typename T>
void Polynomial<T>::insertAtLast(T c, int e)
{
	if (c == 0) return;
	if (!head)
	{
		head = tail = new Term<T>(c, e);
		return;
	}
	tail->next = new Term<T>(c, e);
	tail = tail->next;
}

template<typename T>
void Polynomial<T>::insertAtFirst(T c, int e)
{
	if (c == 0) return;
	if (!head)
	{
		head = tail = new Term<T>(c, e);
		return;
	}
	Term<T>* temp = new Term<T>(c, e);
	temp->next = head;
	head = temp;
}

template <typename T>
void Polynomial<T>::removeAtFirst()
{
	if (!head) return;
	Term<T>* temp = head;
	head = head->next;
	delete temp;
}

template <typename T>
void Polynomial<T>::addTerm(T c, int e)
{
	if (c == 0) return;
	if (!head)
	{
		head = tail = new Term<T>(c, e);
		return;
	}
	if (e >= head->exp)
	{
		if (e > head->exp)
			insertAtFirst(c, e);
		else
		{
			head->coeff += c;
			if (head->coeff == 0)
				removeAtFirst();
		}
		return;
	}
	Term<T>* p = head;
	while (p->next)
	{
		if (e >= p->next->exp)
		{
			if (e > p->next->exp)
			{
				Term<T>* newTerm = new Term<T>(c, e);
				newTerm->next = p->next;
				p->next = newTerm;
			}
			else
			{
				p->next->coeff += c;
				if (p->next->coeff == 0)
				{
					Term<T>* p1 = p->next;
					p->next = p->next->next;
					delete p1;
					if (!p->next)
						tail = p;
				}
			}
			return;
		}
		p = p->next;
	}
	insertAtLast(c, e);
}

template <typename T>
int Polynomial<T>::getDegree()
{
	if (!head) return 0;
	/*Term<T>* p = head->next;
	int maxDegree = head->exp;
	while (p)
	{
		if (maxDegree < p->exp)
			maxDegree = p->exp;
		p = p->next;
	}
	return maxDegree;*/
	return head->exp;
}

template <typename T>
T Polynomial<T>::getCoefficient(int power)
{
	if (!head) exit(0);
	Term<T>* p = head;
	while (p)
	{
		if (p->exp == power)
			return p->coeff;
		p = p->next;
	}
	return 0;
}

template <typename T>
void Polynomial<T>::addToCoefficient(T c, int power)
{
	if (!head) return;
	if (head->exp == power)
	{
		head->coeff += c;
		if (head->coeff == 0)
			removeAtFirst();
		return;
	}
	Term<T>* p = head;
	while (p->next)
	{
		if (p->next->exp == power)
		{
			p->next->coeff += c;
			if (p->next->coeff == 0)
			{
				Term<T>* p1 = p->next;
				p->next = p->next->next;
				delete p1;
				if (!p->next)
					tail = p;
			}
			return;
		}
		p = p->next;
	}
	addTerm(c, power);
}

template <typename T>
const Polynomial<T>& Polynomial<T>::derivative()
{
	if (!head) return *this;
	Term<T>* p = head;
	while (p)
	{
		p->coeff = p->coeff * p->exp;
		p->exp--;
		p = p->next;
	}
	return *this;
}

template<typename T>
T Polynomial<T>::evaluate(T x)
{
	if (!head) return 0;
	Term<T>* p = head;
	T result = 0;
	while (p)
	{
		result += p->coeff * pow(x, p->exp);
		p = p->next;
	}
	return result;
}

template <typename T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial<T>& p)
{
	Polynomial<T> result;
	Term<T>* p1 = head;
	while (p1)
	{
		result.addTerm(p1->coeff, p1->exp);
		p1 = p1->next;
	}
	p1 = p.head;
	while (p1)
	{
		result.addTerm(p1->coeff, p1->exp);
		p1 = p1->next;
	}
	return result;
}

template <typename T>
Polynomial<T> Polynomial<T>::operator-(const Polynomial<T>& p)
{
	Polynomial<T> result;
	Term<T>* p1 = head;
	while (p1)
	{
		result.addTerm(p1->coeff, p1->exp);
		p1 = p1->next;
	}
	p1 = p.head;
	while (p1)
	{
		result.addTerm(-p1->coeff, p1->exp);
		p1 = p1->next;
	}
	return result;
	/*Polynomial<T> result;
	Term<T>* p1 = head;
	Term<T>* p2 = p.head;
	while (p1 && p2)
	{
		if (p1->exp > p2->exp)
		{
			result.addTerm(p1->coeff, p1->exp);
			p1 = p1->next;
		}
		else if (p1->exp < p2->exp)
		{
			result.addTerm(-p2->coeff, p2->exp);
			p2 = p2->next;
		}
		else
		{
			result.addTerm(p1->coeff - p2->coeff, p1->exp);
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	while (p1)
	{
		result.addTerm(p1->coeff, p1->exp);
		p1 = p1->next;
	}
	while (p2)
	{
		result.addTerm(-p2->coeff, p2->exp);
		p2 = p2->next;
	}
	return result;*/
}

template <typename T>
void Polynomial<T>::display()
{
	if (!head)
	{
		cout << "NaN" << endl;
		return;
	}
	Term<T>* p = head;
	while (p)
	{
		if (p->coeff != 0)
		{
			if (p != head && p->coeff > 0)
				cout << " + ";
			if (p->coeff < 0)
				cout << " - ";
			if (abs(p->coeff) != 1)
				cout << abs(p->coeff);
			if (p->exp != 0)
				cout << "x";
			if (p->exp > 1)
				cout << "^" << p->exp;
		}
		p = p->next;
	}
	cout << endl;
}

template <typename T>
void Polynomial<T>::clear()
{
	while (head)
		removeAtFirst();
	head = tail = nullptr;
}

#endif // !POLYNOMIAL_CPP