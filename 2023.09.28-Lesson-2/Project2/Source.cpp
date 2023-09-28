#include<iostream>
#include<vector>
#include<string>

int main(int argc, char* argv[])
{
	int year = 0;
	std::cin >> year;
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
  //if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		std::cout << "366 days";
	}
	else
	{
		std::cout << "365 days";
	}

	return EXIT_SUCCESS;
}