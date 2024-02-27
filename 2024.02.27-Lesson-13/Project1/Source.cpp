#include<iostream>
#include<cmath>

// create a program that can evaluate complex expressions

struct Complex { //definition of a structure
	//fields of structure
	double re;
	double im;

	//default constructor
	Complex()
	{
		re = 0;
		im = 0;
	}

	//parametrized constructor
	Complex(double a, double b, bool algForm = true)
	{
		if (algForm)
		{
			re = a;
			im = b;
		}
		else
		{
			//if it is not algebraic but trigonometric form
			double rho = a;
			double arg = b;
			re = rho * cos(arg);
			im = rho * sin(arg);
		}
	}

	//destructor
	~Complex()
	{
	}

	//methods - functions inside
	void print()
	{
		printf("(%3.1lf) + i * (%3.1lf)\n", re, im);
	}
};

Complex sum(Complex z1, Complex z2)
{
	return Complex(z1.re + z2.re, z1.im + z2.im);
}
Complex diff(Complex z1, Complex z2)
{
	return Complex(z1.re - z2.re, z1.im - z2.im);
}

int main(int argc, char* argv[])
{
	// a + i * b
	// rho(z) (cos(z) + i * sin(z))
	Complex z1; //default constructor
	z1.re = 5;
	z1.im = 9;

	Complex z2{ 3, -5 }; //assigning fields

	Complex z3(-5, 10); //parametrized constructor of algebraic form

	//atan(double) -> the result between (- pi / 2; pi / 2)
	//atan2(double, double) -> the result between (- pi; pi)
	Complex z4(5, atan2(4, 3), false); //parametrized constructor of trigonometric form

	z1.print();
	z2.print();
	z3.print();
	z4.print();

	sum(z1, z2).print();
	diff(z1, z2).print();
	return EXIT_SUCCESS;
}