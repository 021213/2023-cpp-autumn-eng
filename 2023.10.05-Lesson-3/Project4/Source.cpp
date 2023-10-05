#include<iostream>

int main(int argc, char** argv)
{
	int n = 3213;
	int* a = &n;

	std::cout << a << " " << &n << std::endl;
	std::cout << *a << " " << n << std::endl;
	*a = 1234;
	std::cout << *a << " " << n << std::endl;

	//while (1) malloc(1);

	return 0;
}
