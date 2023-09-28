#include<iostream>

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
	// <if> ? <then> : <else>
	std::cout << (a > 0 ? "POS" : a < 0 ? "NEG" : "ZERO") << std::endl;


	return EXIT_SUCCESS;
}