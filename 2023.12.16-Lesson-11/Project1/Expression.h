#pragma once
#include <string>
#include <vector>

class Expression
{
public:
	// 123    *     /    sin
	Expression(std::string token) : token(token) {} // 123
	Expression(std::string token, Expression a) : token(token), args{ a } {} // -1
	Expression(std::string token, Expression a, Expression b) : token(token), args{ a, b } {} //123 + 321
	double eval();

	std::string token;
	std::vector<Expression> args;
};

