#pragma once
#include"Expression.h"

class Parser {
public:
	Parser(const char* input) : input(input) {}
	Expression parse();

private:
	std::string parse_token();
	Expression parse_simple_expression(); //2+3  -2
	Expression parse_binary_expression(int min_priority = 0);  //2 * 4 + 1   1 + 2 * 4

	const char* input;
};