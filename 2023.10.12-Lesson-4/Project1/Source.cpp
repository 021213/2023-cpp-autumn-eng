#include<iostream>
#include<ctime>

int main(int argc, char* argv[])
{
	{
		int aStatic[10]{ 0 };
	}

	int n = 10;
	int* a = new int[n] { 0 };
	
	{
		srand(time(0));
		for (int i = 0; i < n; ++i)
		{
			a[i] = rand() % 19 - 9; // 0..18 -> -9 .. 9
		}
	}
	{
		for (int i = 0; i < n; ++i)
		{
			std::cout << a[i] << " ";
		}
		std::cout << std::endl;
	}
	{
		for (int i = 0; i < n; ++i)
		{
			std::cout << a[n - i - 1] << " ";
		}
		std::cout << std::endl;
	}
	{
		int mx = a[0];
		for (int i = 0; i < n; ++i)
		{
			mx = (a[i] > mx ? a[i] : mx);
		}
		std::cout << "max = " << mx << std::endl;
	}

	delete[] a;
	return EXIT_SUCCESS;
}