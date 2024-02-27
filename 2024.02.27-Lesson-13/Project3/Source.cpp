#include<iostream>

typedef unsigned long long uint;

uint gcd(uint a, uint b)
{
	if (a * b == 0)
	{
		return a + b;
	}
	if (a < b)
	{
		return gcd(b, a);
	}
	return gcd(b, a % b);
}

uint lcm(uint a, uint b)
{
	return a / gcd(a, b) * b;
}

int main(int argc, char* argv[])
{

	return EXIT_SUCCESS;
}