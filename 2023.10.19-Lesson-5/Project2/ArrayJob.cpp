#include "ArrayJob.h"

void expandArray(int*& arr, int& len)
{
	int* newArr = new int[len + 1] { 0 };
	if (arr != nullptr)
	{
		for (int i = 0; i < len; ++i)
		{
			newArr[i] = arr[i];
		}
		delete[] arr;
	}
	arr = newArr;
	++len;
}

void contractArray(int*& arr, int& len)
{
	int* newArr = nullptr;
	if (len > 1)
	{
		newArr = new int[len - 1] { 0 };
		for (int i = 0; i < len - 1; ++i)
		{
			newArr[i] = arr[i];
		}
	}
	delete[] arr;
	arr = newArr;
	--len;
}

void appendElement(int*& arr, int& len, int element)
{
	expandArray(arr, len);
	arr[len - 1] = element;
}

bool indexValid(int index, int len)
{
	return (index >= 0 && index < len);
}

int extractElementByIndex(int*& arr, int& len, int index)
{
	int res = -1;
	if (indexValid(index, len))
	{
		res = arr[index];
		for (int i = index; i < len - 1; ++i)
		{
			arr[i] = arr[i + 1];
		}
		contractArray(arr, len);
	}
	return res;
}