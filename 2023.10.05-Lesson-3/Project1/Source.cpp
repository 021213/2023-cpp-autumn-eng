#include<iostream>
#define NN 10
//static arrays
int main(int argc, char* argv[])
{
	const int N = 10;
	int a[N]{ 1, 2, 3, 4 };

	std::cout << sizeof(a) << " " << sizeof(a) / sizeof(int) << std::endl;
	a[5] = a[0] + a[1];
	std::cout << a << std::endl;
	int* b = a;			//b - address
	std::cout << *b << std::endl;	//*b - data in address b
	for (int i = 0; i < N; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;

	return EXIT_SUCCESS;
}