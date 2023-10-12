#include<iostream>
#include<ctime>

void randomizeArray(int* a, int n)
{
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % 19 - 9;
	}
}
void readArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a[i];
	}
}
void printArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}
void printReverseArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << a[n - i - 1] << " ";
	}
	std::cout << std::endl;
}void printReverseArray2(int* a, int n)
{
	for (int i = n - 1; i >= 0; --i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}
int findMaxArray(int* a, int n)
{
	int mx = a[0];
	for (int i = 0; i < n; ++i)
	{
		mx = (a[i] > mx ? a[i] : mx);
	}
	return mx;
}

int main(int argc, char* argv[])
{
	int n = 10;
	int* a = new int[n] { 0 };

	randomizeArray(a, n);
	printArray(a, n);
	std::cout << "max = " << findMaxArray(a, n);

	delete[] a;
	return EXIT_SUCCESS;
}