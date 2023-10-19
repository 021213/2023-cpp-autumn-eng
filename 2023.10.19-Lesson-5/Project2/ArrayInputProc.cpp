#include "ArrayInputProc.h"

#include<iostream>
#include"ArrayJob.h"

void printMenu()
{
	std::cout << "0 - Exit" << std::endl;
	std::cout << "1 - Print the array" << std::endl;
	std::cout << "2 - Append element to the array" << std::endl;
	std::cout << "3 - Extract element from the array" << std::endl;
}

void printInterface(int* arr, int len)
{
	system("cls");
	printMenu();
	std::cout << "Current state of the array : ";
	printArray(arr, len);
}

void readInput(int& choice)
{
	std::cin >> choice;
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

void appendElementProc(int*& arr, int& len)
{
	std::cout << "Input the element to append : ";
	int element = 0;
	std::cin >> element;
	appendElement(arr, len, element);
}

void extractElementProc(int*& arr, int& len)
{
	std::cout << "Input the index to extract : ";
	int index = 0;
	std::cin >> index;
	std::cout << "Extracted element : " << extractElementByIndex(arr, len, index) << std::endl;
	system("pause");
}

void exitProc(bool& exit)
{
	exit = true;
}

void printProc(int* arr, int len)
{
	printArray(arr, len);
	system("pause");
}

void defaultProc()
{
	std::cout << "Command unknown" << std::endl;
	system("pause");
}

void processInput(int*& arr, int& len, bool& exit, int choice)
{
	switch (choice)
	{
	case 0:
		exitProc(exit);
		break;
	case 1:
		printProc(arr, len);
		break;
	case 2:
		appendElementProc(arr, len);
		break;
	case 3:
		extractElementProc(arr, len);
		break;
	default:
		defaultProc();
		break;
	}
}