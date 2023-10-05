#include<iostream>
#include<ctime>

int main(int argc, char* argv[])
{
	srand(time(nullptr));
	int n = 0;
	std::cin >> n;
	int* a = nullptr;
	a = new int[n] { 0 }; //a = (int*)malloc(sizeof(int) * n); 
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		a[i] = rand() % 90 + 10;
	}
	for (i = 0; i < n; ++i)
	{
		std::cout << a[i] << " ";
	}
	delete[] a; //free(a);
	return EXIT_SUCCESS;
}
