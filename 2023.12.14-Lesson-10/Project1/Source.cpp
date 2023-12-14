#include<iostream>
#include<ctime>

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void print(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

void mix(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		swap(a[i], a[rand() % n]);
	}
}

bool isSorted(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		if (a[i] > a[i + 1])
		{
			return false;
		}
	}
	return true;
}

void monkeySort(int* a, int n)
{
	int steps = 0;
	while (!isSorted(a, n))
	{
		mix(a, n);
		++steps;
	}
	std::cout << "STEPS : " << steps << std::endl;
}

void bubbleSort(int* a, int n) // O(n^2)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				print(a, n);
			}
		}
	}
}

void selectionSort(int* a, int n) // O(n^2)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int minInd = i;
		for (int j = i + 1; j < n; ++j)
		{
			minInd = a[minInd] < a[j] ? minInd : j;
		}
		swap(a[i], a[minInd]);
		print(a, n);
	}
}

//  4    3 2 8 7 0 9 1 5 6
//  3 4    2 8 7 0 9 1 5 6
//  2 3 4    8 7 0 9 1 5 6
//  2 3 4 8    7 0 9 1 5 6
//  2 3 4 7 8    0 9 1 5 6
//  0 2 3 4 7 8    9 1 5 6
//  0 2 3 4 7 8 9    1 5 6 
void insertionSort(int* a, int n) // O(n^2)
{
	for (int i = 1; i < n; ++i)
	{
		int j = i;
		while (j > 0 && a[j] < a[j - 1])
		{
			swap(a[j], a[j - 1]);
			--j;
		}
		print(a, n);
	}
}

void countSort(int* a, int n) // O(n)
{
	int mn = a[0];
	int mx = a[0];
	for (int i = 0; i < n; ++i)
	{
		mn = mn < a[i] ? mn : a[i];
		mx = mx > a[i] ? mx : a[i];
	}

	int* counts = new int[mx - mn + 1] { 0 };
	for (int i = 0; i < n; ++i)
	{
		counts[a[i] - mn]++;
	}

	for (int i = 0, j = 0; i < mx - mn + 1; ++i)
	{
		for (int k = 0; k < counts[i]; ++k, ++j)
		{
			a[j] = i + mn;
		}
	}
	print(a, n);

	delete[] counts;
}

//  4 3 2 8 7 0 9 1 5 6
//  4 3 2 0 1 5    _6_    8 7 9
//  4 3 2 0 1   _5_  _6_   8 7   _9_
//  4 3 2 0 1   _5_  _6_  _7_ _8_ _9_
//  _0_ _1_   _2_  _3_  _4_     _5_  _6_  _7_ _8_ _9_
int partition(int arr[], int low, int high, int pivot) {
	int i = low;
	int j = low;
	while (i <= high) {
		if (arr[i] >= pivot) {
			i++;
		}
		else {
			std::swap(arr[i], arr[j]);
			i++;
			j++;
		}
	}
	return j - 1;
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = arr[high];
		int pos = partition(arr, low, high, pivot);
		quickSort(arr, low, pos - 1);
		quickSort(arr, pos + 1, high);
	}
}

void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < leftSize && j < rightSize) {
		if (left[i] <= right[j]) {
			arr[k++] = left[i++];
		}
		else {
			arr[k++] = right[j++];
		}
	}
	while (i < leftSize) {
		arr[k++] = left[i++];
	}
	while (j < rightSize) {
		arr[k++] = right[j++];
	}
}

//  1 4 6 8     2 3 5 9
//  
//  1 2 3 4 5 6 8 9

void mergeSort(int arr[], int left, int right) {
	if (left >= right) {
		return;
	}
	int mid = (right + left) / 2;
	/*
	8 6 4 3 7 5 2 1

	
	8 6 4 3      7 5 2 1
	  1_2_3_4_5_6_7_8          

	8 6   4 3     7 5   2 1
	3_4_6_8        1_2_5_7

	8  6  4  3    7   5    2   1
	6_8   3_4       5_7      1_2
	*/
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);

	int leftLen = mid - left + 1;
	int* leftArr = new int[leftLen];
	for (int i = 0; i < leftLen; i++) {
		leftArr[i] = arr[left + i];
	}

	int rightLen = right - mid;
	int* rightArr = new int[rightLen];
	for (int i = 0; i < rightLen; i++) {
		rightArr[i] = arr[mid + 1 + i];
	}

	merge(arr, leftArr, leftLen, rightArr, rightLen);

	delete[] leftArr;
	delete[] rightArr;
}

int main(int argc, char* argv[])
{
	srand(time(0));
	const int n = 10;
	int a[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	for (int i = 0; i < n; ++i)
	{
		//a[i] = rand() % 90 + 10;
	}
	
	print(a, n);
	mix(a, n);
	print(a, n);

	std::cout << "Monkey sort : ";
	monkeySort(a, n);

	std::cout << "Bubble sort" << std::endl;
	mix(a, n);
	bubbleSort(a, n);
	std::cout << std::endl;

	std::cout << "Selection sort" << std::endl;
	mix(a, n);
	selectionSort(a, n);
	std::cout << std::endl;

	std::cout << "Insertion sort" << std::endl;
	mix(a, n);
	insertionSort(a, n);
	std::cout << std::endl;

	std::cout << "Count sort" << std::endl;
	mix(a, n);
	countSort(a, n);
	std::cout << std::endl;

	std::cout << "Quick sort" << std::endl;
	mix(a, n);
	quickSort(a, 0, n);
	std::cout << std::endl;

	std::cout << "Merge sort" << std::endl;
	mix(a, n);
	mergeSort(a, 0, n);
	std::cout << std::endl;

	return EXIT_SUCCESS;
}