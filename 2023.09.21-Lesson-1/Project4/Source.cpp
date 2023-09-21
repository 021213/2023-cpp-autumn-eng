#include<iostream>
#include<cmath>

#define N 10

int main(int argc, char* argv)
{
	int a = 213;
	std::cout << sqrt(a) << std::endl;
	std::cout << pow(a, 0.4) << std::endl;
	std::cout << cos(a) << std::endl;
	std::cout << sinh(a) << std::endl;
	std::cout << exp(a) << std::endl;
	std::cout << N << std::endl;

	const int B = 123;
	std::cout << B << std::endl;

	return EXIT_SUCCESS;
}