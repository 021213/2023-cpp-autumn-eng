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
}
void printReverseArray2(int* a, int n)
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

/*
Implement functions according to the task.
Each task should be solved in a separate cpp file.
Each program should start with reading dynamic array from standard input (std::cin)

1). Count positive elements.
1 2 -3 -4 -5 6 -> 3
2). Remove negative elements.
1 2 -3 -4 -5 6 -> 1 2 6
3). Reverse the array (swap(a[0]; a[n - 1]), swap(a[1]; a[n - 2]), ...).
1 2 3 4 5 -> 5 4 3 2 1
4). Swap first maximum element and last minimum element.
1 1 1 2 2 2 2 -> 1 1 2 1 2 2 2
2 2 2 2 1 1 1 -> 1 2 2 2 1 1 2
5). Count sum of elements.
1 2 3 4 5 -> 15
6). Swap elements with odd indexes with elements with even indexes
1 2 3 4 5 6 -> 2 1 4 3 6 5

Don't forget to cleanup the memory.
*/