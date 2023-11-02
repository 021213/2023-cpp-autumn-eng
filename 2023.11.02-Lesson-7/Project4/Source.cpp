#include<iostream>
#include<cmath>

struct Complex {
	double re;
	double im;

	//todo: define the default and parametrized constructor
	//todo: define a destructor
};

void Print(Complex z);
void Arg(Complex z); //argument of a complex number
void Abs(Complex z); //absolute value of a complex number
void Sum(Complex z1, Complex z2, Complex& res)
{
	res.re = z1.re + z2.re;
	res.im = z1.im + z2.im;
}
void Difference(Complex z1, Complex z2, Complex& res);
void Product(double d, Complex z, Complex& res);
void Product(Complex z1, Complex z2, Complex& res);
void Div(Complex z1, Complex z2, Complex& res);

int main(int argc, char* argv[])
{
	/*
	Complex z1(3, -4);
	Complex z2(-5, 2);
	//todo: evaluate (2 * z1 + 3 * z2 - z1 * z2) / (z1 * z2)
	*/
	return EXIT_SUCCESS;
}