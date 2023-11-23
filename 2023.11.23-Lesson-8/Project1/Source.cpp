#include<iostream>

int f(int n);
int g(int n);
int fact(int n);
int fib(int n);

int main(int argc, char* argv[])
{
	std::cout << f(5);
	return EXIT_SUCCESS;
}

int fact(int n)
{
	if (n == 0)
	{
		return 1;
	}
	return n * fact(n);
}

int fib(int n)
{
	if (n < 2)
	{
		return n;
	}
	return fib(n - 1) + fib(n - 2);
}

int f(int n)
{
	if (n < 1)
	{
		return n - 1;
	}
	return 2 * g(n - 1) + 3 * g(n - 2);
}

int g(int n)
{
	if (n < 1)
	{
		return 0;
	}
	return f(n - 1) + 3 * f(n - 2);
}