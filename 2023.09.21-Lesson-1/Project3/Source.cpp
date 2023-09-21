#include<iostream>

int main(int argc, char* argv[])
{
	int a = 10;
	int b = 24;
	int c = 0;

	c = a + b;
	c = a - b;
	c = a * b;
	c = a / b; // div   17 / 5 = 3
	c = a % b; // mod   17 % 5 = 2

	float fa = 1.5f;
	double da = 1.5;

	da = da / fa;

	a += b; //a = a + b
	a *= b;
	a -= b;
	a /= b;
	a %= b;

	//logic operators
	bool ba = true;
	bool bb = false;
	bool bc = 1; //0 = false, 1 = true

	bc = ba || bb; // or, logic sum
	bc = ba && bb; //and, logic mult
	bc = ba == bb; //equals
	bc = ba != bb; //not equals, xor
	bc = !ba; //inverse. NOT

	//binary operations
	a = 5;									//		a = 0101 = 5
	b = 9;									//      b = 1001 = 9
	c = a & b;	// binary AND operation					0001 = 1
	c = a | b;	// binary OR operation					1101 = 13
	c = a ^ b;	// binary XOR operation					1100 = 12
	c = ~a;		// binary INVERSE operation				1010 = 10
	c = a << 1; // left shift						   01010 = 10
	c = b >> 1; // right shift                            100 = 4
	c = ((a >> 2) & 1); //								0_1_01 = 1


	a = 1234;
	int code = 323;
	b = a ^ code;
	std::cout << a << " -> " << b << " -> " << (b ^ code) << std::endl;

	std::cout << a << " " << b << std::endl;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	std::cout << a << " " << b << std::endl;
	a ^= b ^= a ^= b;
	std::cout << a << " " << b << std::endl;




	return EXIT_SUCCESS;
}