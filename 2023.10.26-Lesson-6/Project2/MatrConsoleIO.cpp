#include "MatrConsoleIO.h"
#include<iostream>

void printMatr(int** matr, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			std::cout << matr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void demoSum()
{
	std::cout << "___________________________________" << std::endl;
	std::cout << "Sum of 2 random matrixes demo : " << std::endl;
	int rows = 3;
	int cols = 4;
	int** matr = initMatr(rows, cols); //2-dimentional array;
	int** matr1 = initMatr(rows, cols);
	int** matr2 = nullptr;
	int matr2R = 0;
	int matr2C = 0;
	randomizeMatr(matr, rows, cols);
	randomizeMatr(matr1, rows, cols);
	add(matr, rows, cols, matr1, rows, cols, matr2, matr2R, matr2C);
	printMatr(matr, rows, cols);
	std::cout << " + " << std::endl;
	printMatr(matr1, rows, cols);
	std::cout << " = " << std::endl;
	printMatr(matr2, rows, cols);

	deleteMatr(matr, rows);
	deleteMatr(matr1, rows);
	deleteMatr(matr2, matr2R);
	std::cout << "___________________________________" << std::endl;
}