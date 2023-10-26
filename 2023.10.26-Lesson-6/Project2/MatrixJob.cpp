#include "MatrixJob.h"

#include<cstdlib>

int** initMatr(int rows, int cols)
{
	int** res = nullptr;
	res = new int* [rows] { 0 };
	for (int i = 0; i < rows; ++i)
	{
		res[i] = new int[cols] { 0 };
	}
	return res;
}
void randomizeMatr(int** matr, int rows, int cols, int start, int end)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			matr[i][j] = rand() % (end - start + 1) + start;
		}
	}
}
void deleteMatr(int** & matr, int rows)
{
	if (matr == nullptr)
	{
		return;
	}
	for (int i = 0; i < rows; ++i)
	{
		delete[] matr[i];
	}
	delete[] matr;
	matr = nullptr;
}

void resizeMatr(int**& matr, int& rows, int& cols, int newRows, int newCols)
{
	int** res = initMatr(newRows, newCols);
	int minRows = (rows < newRows ? rows : newRows);
	int minCols = (cols < newCols ? cols : newCols);
	for (int i = 0; i < minRows; ++i)
	{
		for (int j = 0; j < minCols; ++j)
		{
			res[i][j] = matr[i][j];
		}
	}
	deleteMatr(matr, rows);
	rows = newRows;
	cols = newCols;
	matr = res;
}

bool add(
	int** matr1, int rows1, int cols1,
	int** matr2, int rows2, int cols2,
	int**& matrRes, int& rowsRes, int& colsRes)
{
	if (rows1 != rows2 || cols1 != cols2)
	{
		return false;
	}
	
	deleteMatr(matrRes, rowsRes);

	rowsRes = rows1;
	colsRes = cols1;
	matrRes = initMatr(rowsRes, colsRes);

	for (int i = 0; i < rowsRes; ++i)
	{
		for (int j = 0; j < colsRes; ++j)
		{
			matrRes[i][j] = matr1[i][j] + matr2[i][j];
		}
	}
	return true;
}