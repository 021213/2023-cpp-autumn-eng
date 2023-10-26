#include<iostream>

int main(int argc, char* argv[])
{
	int m[3][4]{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	int rows = sizeof(m) / sizeof(m[0]);
	int cols = sizeof(m[0]) / sizeof(m[0][0]);
	std::cout << "Rows " << rows << std::endl;
	std::cout << "Columns " << cols << std::endl;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			std::cout << m[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return EXIT_SUCCESS;
}