#include<iostream>
#include<string>

int main(int argc, char* argv[])
{
	std::string str1 = "Hello";
	std::string str2 = "world";
	std::string str = "Hello, world!";

	std::cout << "str : " << str << "\n";
	std::cout << "Concatanation: " + str1 + " " + str2 + "\n";
	std::cout << "find " << str2 << " : " << str.find(str2) << "\n";
	std::cout << "find " << str1 << " : " << str.find(str1) << "\n";
	std::cout << str.substr(3, 6) << "\n";
	std::cout << str.insert(4, "banana") << "\n";


	std::cin >> str1; //1 word (space is separator)
	std::getline(std::cin, str2);
	std::cout << "str1 : " << str1 << "\n";
	std::cout << "str2 : " << str2 << "\n";

	return EXIT_SUCCESS;
}
