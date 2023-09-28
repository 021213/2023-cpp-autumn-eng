#include<iostream>
#include<vector>
#include<string>

int main(int argc, char* argv[])
{
	int a = 10;
	if (a > 0)
	{
		std::cout << "POS" << std::endl;
	}
	else if (a == 0)
	{
		std::cout << "ZERO" << std::endl;
	}
	else
	{
		std::cout << "NEG" << std::endl;
	}
	int b = 0;
	std::cin >> b;

	std::pair<int, int> p;
	std::vector<int> v;
	std::string s;

	return EXIT_SUCCESS;
}