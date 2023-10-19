#include<iostream>

#include "ArrayJob.h"
#include "ArrayInputProc.h"

int main(int argc, char* argv[])
{
	//implement a programm that processes a dynamic array

	int* a = nullptr;
	int n = 0;

	bool exit = false;
	int choice = 0;

	while (!exit)
	{
		printInterface(a, n);
		readInput(choice);
		processInput(a, n, exit, choice);
	}

	delete[] a;

	return EXIT_SUCCESS;
}
