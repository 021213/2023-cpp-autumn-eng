#include <iostream>
#include "Expression.h"
#include "Parser.h"

int test(const char* input, double expected) {
	try {
		Parser p(input);
		double result = p.parse().eval();
		if (result == expected)
		{
			return 0;
		}
		std::cout << input << " = " << expected << " : error, got " << result << '\n';
	}
	catch (std::exception& e) {
		std::cout << input << " : exception: " << e.what() << '\n';
	}
	return 1;
}

int main() {
	int errors = 0;
	errors += test("0", 0);
	errors += test("1", 1);
	errors += test("9", 9);
	errors += test("10", 10);
	errors += test("+1", 1);
	errors += test("-1", -1);
	errors += test("(1)", 1);
	errors += test("(-1)", -1);
	errors += test("abs(-1)", 1);
	errors += test("1+20", 21);
	errors += test("1 + 20", 21);
	errors += test("1+20+300", 321);
	errors += test("1+20+300+4000", 4321);
	errors += test("-1+20", 19);
	errors += test("--1+20", 21);
	errors += test("---1+20", 19);
	errors += test("(1+20)", 21);
	errors += test("-2*3", -6);
	errors += test("2*-3", -6);
	errors += test("1++2", 3);
	errors += test("1+10*2", 21);
	errors += test("10*2+1", 21);
	errors += test("(1+20)*2", 42);
	errors += test("2*(1+20)", 42);
	errors += test("(1+2)*(3+4)", 21);
	errors += test("2*3+4*5", 26);
	errors += test("100+2*10+3", 123);
	errors += test("2**3", 8);
	errors += test("2**3*5+2", 42);
	errors += test("5*2**3+2", 42);
	errors += test("2+5*2**3", 42);
	errors += test("1+2**3*10", 81);
	errors += test("2**3+2*10", 28);
	errors += test("5 * 4 + 3 * 2 + 1", 27);
	std::cout << "Done with " << errors << " errors.\n";
}