#include<iostream>

int main(int argc, char* argv[])
{
	{
		int i = 0;
		while (i < 10)
		{
			std::cout << i << " ";
			++i;
		}
		std::cout << std::endl;
	}
	{
		int i = 0;
		do
		{
			std::cout << i << " ";
			++i;
		} while (i < 10);
		std::cout << std::endl;
	}
	{
		int i = 0;
	start:
		std::cout << i << " ";
		++i;
		if (i < 10) { goto start; }
		std::cout << std::endl;
	}
	{
		for (int i = 0; i < 10; ++i)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
	
	{
		int a = 1;
		{
			std::cout << a << " ";
			int a = 2;
			std::cout << a << " ";
			for (int a = 3; a < 5; ++a)
			{
				std::cout << a << " ";
			}
			std::cout << a << " ";
		}
		std::cout << a << std::endl;

		{
			std::cout << a << " ";
			a = 2;
			std::cout << a << " ";
			for (a = 3; a < 5; ++a);
			{
				std::cout << a << " ";
			}
			std::cout << a << " ";
		}
		std::cout << a << std::endl;
	}
	return EXIT_SUCCESS;
}