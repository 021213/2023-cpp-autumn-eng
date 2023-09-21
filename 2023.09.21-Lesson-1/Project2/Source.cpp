#include<iostream>

int main(int argc, char* argv[])
{
	//integer
	char c = 0;
	short sh = 0;
	int i = 0;
	long l = 0;
	long long ll = 0;
	unsigned short ush = 0;
	unsigned int ui = 0;
	unsigned long ul = 0;
	unsigned long long ull = 0;

	std::cout << sizeof(short) << std::endl;
	std::cout << sizeof(int) << std::endl;
	std::cout << sizeof(long) << std::endl;
	std::cout << sizeof(long long) << std::endl;
	std::cout << sizeof(unsigned short) << std::endl;
	std::cout << sizeof(unsigned int) << std::endl;
	std::cout << sizeof(unsigned long) << std::endl;
	std::cout << sizeof(unsigned long long) << std::endl;

	float f = 0;
	double d = 0;

	bool bb = true; // true/false;

	int a = 0; //&a - address of variable a
	int b = 0;
	std::cin >> a >> b;
	std::cout << a << " + " << b << " = " << a + b << std::endl;

	scanf_s("%d", &a);
	scanf_s("%d", &b);	
	printf("%d + %d = %d\n", a, b, a + b);

	return EXIT_SUCCESS;
}