#include <iostream>
#include "Polynomial.h"

using namespace std;

int main()
{
	Polynomial<float> p;
	cout << "Enter the number of terms in polynomial 1: ";
	int n;
	cin >> n;
	cout << "Enter the terms in the form of coefficient and exponent: " << endl;
	for (int i = 0; i < n; i++)
	{
		float coeff;
		int exp;
		cin >> coeff >> exp;
		p.addTerm(coeff, exp);
	}

	cout << "Polynomial 1: ";
	p.display();

	Polynomial<float> p1;
	cout << "Enter the number of terms in polynomial 2: ";
	cin >> n;
	cout << "Enter the terms in the form of coefficient and exponent: " << endl;
	for (int i = 0; i < n; i++)
	{
		float coeff;
		int exp;
		cin >> coeff >> exp;
		p1.addTerm(coeff, exp);
	}

	cout << "Polynomial 2: ";
	p1.display();

	Polynomial<float> p2 = p + p1;
	cout << "Polynomial 1 + Polynomial 2: ";
	p2.display();

	Polynomial<float> p3 = p - p1;
	cout << "Polynomial 1 - Polynomial 2: ";
	p3.display();

	cout << "Degree of Polynomial 1: " << p.getDegree() << endl;
	cout << "Degree of Polynomial 2: " << p1.getDegree() << endl;
	float coeff;
	int exp;

	cout << "Enter the exponent to get its coefficient: ";
	cin >> exp;
	cout << "Coefficient of exponent " << exp << " is " << p.getCoefficient(exp) << endl;

	cout << "Enter the amount to add in coefficient of desired exponent : ";
	cin >> coeff >> exp;
	p.addToCoefficient(coeff, exp);
	cout << "Polynomial 1: ";
	p.display();
}