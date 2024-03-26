#include<iostream>
#include<fstream>

int main(int argc, char* argv[])
{
	int s = 0;
	std::ifstream fin;
	fin.open("in.txt");
	while(!fin.eof())
	{
		int x = 0;
		fin >> x;
		s += x;
	}
	fin.close();

	std::ofstream fout;
	fout.open("out.txt");
	fout << s;
	fout.close();
	return EXIT_SUCCESS;
}