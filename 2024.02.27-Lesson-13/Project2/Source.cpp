#include<iostream>
#include<cmath>

struct Complex {
	double re;
	double im;

	Complex(double a = 0, double b = 0, bool algForm = true) : re(a), im(b)
	{
		if (!algForm)
		{
			double rho = a;
			double arg = b;
			re = rho * cos(arg);
			im = rho * sin(arg);
		}
	}

	//copy constructor
	Complex(const Complex& z) : re(z.re), im(z.im)
	{
	}

	~Complex()
	{
	}

	void print()
	{
		printf("(%3.1lf) + (%3.1lf)i\n", re, im);
	}
};

Complex sum(Complex z1, Complex z2)
{
	return Complex(z1.re + z2.re, z1.im + z2.im);
}
Complex diff(Complex& z1, Complex& z2)
{
	return Complex(z1.re - z2.re, z1.im - z2.im);
}

int main(int argc, char* argv[])
{
	Complex z1(3, 2);
	Complex z2(9, -2);
	Complex z3(z1);
	z3.print();
	z3 = sum(z1, z2);
	z3.print();
	return EXIT_SUCCESS;
}

/*
Hometask
Create a structure Fraction.
Fraction consists of Numerator and Denominator (*also the whole part of a number)
Numerator can be negative (long long)
Denominator is always positive (unsigned long long)
*The whole part can be negative (long long)
The denominator can not be zero
Create all basic functions to work with fractions.
Sum, difference, product and quotient of fractions.
*/