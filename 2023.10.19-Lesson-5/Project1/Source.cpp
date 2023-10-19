#include<iostream>

void expandArray(int*& arr, int& len);
void contractArray(int*& arr, int& len);
void printArray(int* arr, int len);
void appendElement(int*& arr, int& len, int element);
bool indexValid(int index, int len);
int extractElementByIndex(int*& arr, int& len, int index);

int main(int argc, char* argv[])
{
	int* a = nullptr;
	int len = 0;

	printArray(a, len);
	appendElement(a, len, 0);
	appendElement(a, len, 1);
	appendElement(a, len, 2);
	appendElement(a, len, 3);
	appendElement(a, len, 4);
	appendElement(a, len, 5);
	printArray(a, len);
	std::cout << "Extracting [2] element " << extractElementByIndex(a, len, 2) << std::endl;
	std::cout << "Extracting last element " << extractElementByIndex(a, len, len - 1) << std::endl;
	std::cout << "Extracting first element " << extractElementByIndex(a, len, 0) << std::endl;
	std::cout << "Extracting [100] element " << extractElementByIndex(a, len, 100) << std::endl;
	printArray(a, len);

	return EXIT_SUCCESS;
}

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

void printArray(int* arr, int len)
{
	if (arr == nullptr)
	{
		std::cout << "EMPTY";
	}
	else
	{
		for (int i = 0; i < len; ++i)
		{
			std::cout << arr[i] << " ";
		}
	}
	std::cout << std::endl;
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
