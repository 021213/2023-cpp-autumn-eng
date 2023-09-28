#include<iostream>
#include<string>

int main(int argc, char* argv[])
{
	int day = 4;
	switch (day % 7)
	{
	case 0:
		std::cout << "SUN" << std::endl;
		break;
	case 1:
		std::cout << "MON" << std::endl;
		break;
	case 2:
		std::cout << "TUE" << std::endl;
		break;
	case 3:
		std::cout << "WED" << std::endl;
		break;
	case 4:
		std::cout << "THU" << std::endl;
		break;
	case 5:
		std::cout << "FRI" << std::endl;
		break;
	case 6:
		std::cout << "SAT" << std::endl;
		break;
	default:
		std::cout << "NaN" << std::endl;
		break;
	}

	std::string dayName[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	std::cout << dayName[day % 7] << std::endl;
	
	day = 1;
	switch (day)
	{
	case 1:
		std::cout << "one";
	case 2:
	case 3:
		std::cout << "two or three";
		break;
	default:
		std::cout << "NaN";
	}

	return 0;
}