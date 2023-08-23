#include <iostream>

using namespace std;

class Polynomial
{
	float *data;
	int degree;
	void reSize(int newDegree)
	{
		float *temp = new float[newDegree + 1];
		for (int i = 0; i <= newDegree; i++)
			temp[i] = 0;
		int size = newDegree < degree ? newDegree : degree;
		for (int i = 0; i <= size; i++)
			temp[i] = data[i];
		delete[] data;
		data = temp;
		degree = newDegree;
	}

public:
	Polynomial()
	{
		data = nullptr;
		degree = 0;
	}

	Polynomial(int n) : Polynomial()
	{
		if (n <= 0)
			return;
		degree = n;
		data = new float[degree + 1];
		for (int i = 0; i <= degree; i++)
			data[i] = 0;
	}

	Polynomial(const Polynomial &p) : Polynomial()
	{
		degree = p.degree;
		data = new float[degree + 1];
		for (int i = 0; i <= degree; i++)
			data[i] = p.data[i];
	}

	Polynomial &operator=(const Polynomial &p)
	{
		if (this == &p)
			return *this;
		if (degree != p.degree)
		{
			delete[] data;
			degree = p.degree;
			data = new float[degree + 1];
		}
		for (int i = 0; i <= degree; i++)
			data[i] = p.data[i];
		return *this;
	}

	~Polynomial()
	{
		if (data)
			delete[] data;
		data = nullptr;
		degree = 0;
	}

	void setCoefficient(int i, float c)
	{
		if (i < 0)
			return;
		else if (i > degree)
			reSize(i);
		data[i] = c;
	}

	float getCoefficient(int i)
	{
		if (i < 0 || i > degree)
			return 0;
		return data[i];
	}

	int getDegree()
	{
		return degree;
	}

	void addTerm(float c, int e)
	{
		if (e < 0)
			return;
		if (e > degree)
			reSize(e);
		data[e] += c;
	}

	Polynomial operator+(Polynomial &p)
	{
		int size = degree > p.degree ? degree : p.degree;
		Polynomial temp(size);
		for (int i = 0; i <= size; i++)
			temp.data[i] = data[i] + p.data[i];
		return temp;
	}

	float operator()(float x)
	{
		float result = 0;
		for (int i = 0; i <= degree; i++)
			result = result * x + data[i];
		return result;
	}

	void clear()
	{
		degree = 0;
		data = nullptr;
	}

	void addToCoefficient(int i, float c)
	{
		if (i < 0)
			return;
		else if (i > degree)
			reSize(i);
		data[i] += c;
	}

	void display()
	{
		if (data == nullptr)
		{
			cout << "Polynomial is empty";
			return;
		}
		for (int i = degree; i >= 0; i--)
		{
			if (data[i] == 0)
				continue;
			// else if (data[i] == 1)
			// 	cout << "x^" << i;
			if (i == 0)
				cout << data[i];
			else if (i == 1 && data[i] != 1)
				cout << data[i] << "x ";
			else if (i == 1 && data[i] == 1)
				cout << "x ";
			else if (data[i] == 1)
				cout << "x^" << i;
			else
				cout << data[i] << "x^" << i;
			if (i != 0)
				cout << " + ";
		}
		cout << endl;
	}

	Polynomial Derivative()
	{
		Polynomial temp(degree - 1);
		for (int i = 0; i < degree; i++)
			temp.data[i] = data[i + 1] * (i + 1);
		return temp;
	}

	Polynomial AntiDerivative()
	{
		Polynomial temp(degree + 1);
		for (int i = 1; i <= degree + 1; i++)
			temp.data[i] = data[i - 1] / i;
		return temp;
	}
};

int main()
{
	Polynomial p(10);
	p.addTerm(2, 1);
	p.addTerm(1, 1);
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
}
