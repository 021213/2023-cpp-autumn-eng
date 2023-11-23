#include<iostream>

typedef unsigned long long uint;
const int N = 40;

uint C(uint n, uint k)
{
	static uint c[N][N]{ 0 };

	if (c[n][k] == 0)
	{
		if (k == n || k == 0)
		{
			c[n][k] = 1;
		}
		else
		{
			c[n][k] = C(n - 1, k - 1) + C(n - 1, k);
		}
	}
	return c[n][k];
}

int main(int argc, char* argv[])
{
	for (uint i = 0; i < N; ++i)
	{
		for (uint j = 0; j < i; ++j)
		{
			std::cout << C(i, j) << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}