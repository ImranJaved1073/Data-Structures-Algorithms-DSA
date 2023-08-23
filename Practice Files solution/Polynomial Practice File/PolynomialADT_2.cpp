#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Term
{
	float coeff;
	int exp;

public:
	Term() : coeff(0), exp(0) {}
	Term(float c, int e) : coeff(c), exp(e) {}

	void setExponent(int e) { exp = e; }
	int getExponent() { return exp; }
	void setCoefficient(float c) { coeff = c; }
	float getCoefficient() { return coeff; }
	void setTerm(float c, int e) { coeff = c; exp = e; }

};

class Polynomial
{
	Term* data;
	int noOfTerms;
	int capacity;
	//maintains the list of terms in sorted order
	//of exponent
	void reSize(int newCapacity)
	{
		int newNoOfTerms = noOfTerms;
		Term* temp = new Term[newCapacity];
		if (capacity > 0)
		{
			int size = newCapacity < capacity ? newCapacity : capacity;
			for (int i = 0; i < size; i++)
				temp[i] = data[i];
		}
		this->~Polynomial();
		capacity = newCapacity;
		noOfTerms = newNoOfTerms;
		data = temp;
	}

public:

	Polynomial()
	{
		data = nullptr;
		noOfTerms = 0;
		capacity = 0;
	}

	Polynomial(int n) :Polynomial()
	{
		if (n <= 0)
			return;
		capacity = n;
		data = new Term[capacity];
		noOfTerms = 0;
	}

	~Polynomial()
	{
		if (data)
			delete[]data;
		data = nullptr;
		noOfTerms = 0;
		capacity = 0;
	}

	int findTerm(int exp)
	{
		for (int i = 0; i < noOfTerms; i++)
		{
			if (data[i].getExponent() == exp)
				return i;
		}
		return -1;
	}

	void addTerm(float coeff, int exp)
	{
		if (coeff == 0)
			return;
		if (noOfTerms == capacity)
			reSize(capacity + 1);
		int i = 0;
		for (i = 0; i < noOfTerms; i++)
		{
			if (data[i].getExponent() == exp)
			{
				data[i].setCoefficient(data[i].getCoefficient() + coeff);// here adding coefficients when exponents are same 
				// here if coefficients are 0 just removing the term 
				if (data[i].getCoefficient() == 0)
				{
					for (int j = i; j < noOfTerms - 1; j++)
						data[j] = data[j + 1];
					noOfTerms--;
				}
				return;
			}
			//sort the data
			else if (data[i].getExponent() < exp)
			{
				for (int j = noOfTerms; j > i; j--)
					data[j] = data[j - 1];
				data[i].setTerm(coeff, exp);
				noOfTerms++;
				return;
			}
		}
		// if there is no term with coefficient just simply add the term to polynomial
		data[i].setTerm(coeff, exp);
		noOfTerms++;
	}

	void display()
	{
		for (int i = 0; i < noOfTerms; i++)
		{
			if (data[i].getExponent() > 0)
				cout << data[i].getCoefficient() << "x^" << data[i].getExponent();
			else
				cout << data[i].getCoefficient();

			if (i < noOfTerms - 1)
				cout << " + ";
		}
		cout << endl;
	}

	int getDegree()
	{
		return data[0].getExponent();
	}

	Polynomial operator+(Polynomial& p)
	{
		Polynomial result;
		int i = 0, j = 0;
		while (i < noOfTerms && j < p.noOfTerms)
		{
			if (data[i].getExponent() == p.data[j].getExponent())
			{
				result.addTerm(data[i].getCoefficient() + p.data[j].getCoefficient(), data[i].getExponent());
				i++;
				j++;
			}
			else if (data[i].getExponent() > p.data[j].getExponent())
			{
				result.addTerm(data[i].getCoefficient(), data[i].getExponent());
				i++;
			}
			else
			{
				result.addTerm(p.data[j].getCoefficient(), p.data[j].getExponent());
				j++;
			}
		}
		for (; i < noOfTerms; i++)
			result.addTerm(data[i].getCoefficient(), data[i].getExponent());
		for (; j < p.noOfTerms; j++)
			result.addTerm(p.data[j].getCoefficient(), p.data[j].getExponent());
		return result;
	}

	void setCoefficient(float coeff, int exp)
	{
		int index = findTerm(exp);
		if (index == -1)
			addTerm(coeff, exp);
		else
			data[index].setCoefficient(coeff);
	}

	float getCoefficient(int power)
	{
		int index = findTerm(power);
		if (index == -1)
			return 0;
		else
			return data[index].getCoefficient();
	}

	void addToCoefficient(float coeff, int exp)
	{
		int index = findTerm(exp);
		if (index == -1)
			addTerm(coeff, exp);
		else
			data[index].setCoefficient(data[index].getCoefficient() + coeff);
	}

	void clear()
	{
		noOfTerms = 0;
	}

	float operator()(float x)
	{
		float result = 0;
		for (int i = 0; i < noOfTerms; i++)
			result = result * x + data[i].getCoefficient();
		return result;
	}
	/*float operator()(float x)
	{
		float result = 0;
		for (int i = 0; i < noOfTerms; i++)
			result += data[i].getCoefficient() * pow(x, data[i].getExponent());
		return result;
	}*/

	Polynomial Derivative()
	{
		Polynomial result;
		for (int i = 0; i < noOfTerms; i++)
		{
			if (data[i].getExponent() > 0)
				result.addTerm(data[i].getCoefficient() * data[i].getExponent(), data[i].getExponent() - 1);
		}
		return result;
	}

	Polynomial AntiDerivative()
	{
		srand(time(0));
		Polynomial result;
		int i;
		for (i = 0; i < noOfTerms; i++)
			result.addTerm(data[i].getCoefficient() / (data[i].getExponent() + 1), data[i].getExponent() + 1);
		result.addTerm(static_cast<float>((rand() % 500) + 1), 0);
		return result;
	}
	
};


int main()
{
	//Polynomial p(10);
	//p.addTerm(1, 2);
	//p.addTerm(2, 1);
	//p.addTerm(3, 0);
	//p.addTerm(4, 3);
	//p.addTerm(5, 4);
	//p.addTerm(6, 5);
	//p.addTerm(7, 6);
	//p.addTerm(8, 7);
	//p.addTerm(9, 8);
	//p.addTerm(10, 9);
	//p.addTerm(12, 9);
	//p.addTerm(12, 7);
	////p.addTerm(-20, 7);
	//p.display();

	//cout << p(1) << endl;



	/*Polynomial p(10);
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

	Polynomial p1(10);
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

	Polynomial p2 = p + p1;
	cout << "Polynomial 1 + Polynomial 2: ";
	p2.display();

	cout << "Degree of Polynomial 1: " << p.getDegree() << endl;
	cout << "Degree of Polynomial 2: " << p1.getDegree() << endl;

	cout << "Enter the new coefficient to set of desired exponent : ";
	float coeff;
	int exp;
	cin >> coeff >> exp;
	p.setCoefficient(coeff, exp);
	cout << "Polynomial 1: ";
	p.display();

	cout << "Enter the exponent to get its coefficient: ";
	cin >> exp;
	cout << "Coefficient of exponent " << exp << " is " << p.getCoefficient(exp) << endl;

	cout << "Enter the amount to add in coefficient of desired exponent : ";
	cin >> coeff >> exp;
	p.addToCoefficient(coeff, exp);
	cout << "Polynomial 1: ";
	p.display();*/

	Polynomial p(10);
	p.addTerm(1, 2);
	p.addTerm(2, 1);
	p.addTerm(3, 0);
	p.addTerm(4, 3);
	p.addTerm(5, 4);
	p.addTerm(6, 5);
	p.addTerm(7, 6);
	p.addTerm(8, 7);
	p.addTerm(9, 8);
	p.addTerm(10, 9);
	p.addTerm(12, 9);
	p.addTerm(12, 7);
	p.addTerm(12, 10);
	p.addTerm(11, 10);
	p.addTerm(33, 16);

	cout << "Enter the value of x to evaluate the polynomial:";
	float x;
	cin >> x;
	cout << "p(x) = ";
	p.display();
	
	cout << "p(" << x << ") = " << p(x) << endl;
	cout << "Derivative:";
	cout << "\np'(x) = ";
	Polynomial p1 = p.Derivative();
	p1.display();
	
	cout << "p(" << x << ") = " << p(x) << endl;
	cout << "AntiDerivative = ";
	Polynomial p2 = p1.AntiDerivative();
	p2.display();

	p.clear();
	cout << "Polynomial 1: ";
	p.display();
	

	return 0;
}