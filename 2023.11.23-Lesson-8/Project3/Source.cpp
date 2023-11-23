#include<iostream>
/*
hanoi towers

1
2
3
4
5 . .


	1
	2
	3
	4
. . 5

*/

void hanoi(int n, int from = 1, int to = 3)
{
	//static int step = 0;
	if (n == 0)
	{
		return;
	}

	if (from + to == 4)
	{
		hanoi(n, from, 2);
		hanoi(n, 2, to);
	}
	else
	{
		/*
		* 1
		* 2
		* 3
		* 4 . .
		*
		*   1
		*   2
		* 4 3 .
		*
		*   1
		*   2
		* . 3 4
		*
		*     1
		*     2
		*     3
		* . . 4
		*/

		int res = 6 - to - from;
		hanoi(n - 1, from, res); // hanoi(3, 1, 2);
		//printf("%d %d %d\tstep : %d\n", n, from, to, ++step);
		printf("%d %d %d\n", n, from, to);
		hanoi(n - 1, res, to); //hanoi(3, 2, 3);
	}
}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	hanoi(n);
	return EXIT_SUCCESS;
}