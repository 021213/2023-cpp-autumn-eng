#include "Expression.h"
#include<stdexcept>

double Expression::eval() {
	switch (args.size()) {
	case 2: {
		double a = args[0].eval();
		double b = args[1].eval();
		if (token == "+") return a + b;
		if (token == "-") return a - b;
		if (token == "*") return a * b;
		if (token == "/") return a / b;
		if (token == "**") return pow(a, b);
		if (token == "mod") return (int)a % (int)b;
		if (token == "%") return (int)a % (int)b;
		throw std::runtime_error("Unknown binary operator");
	}

	case 1: {
		auto a = args[0].eval();
		if (token == "+") return +a;
		if (token == "-") return -a;
		if (token == "abs") return abs(a);
		if (token == "sin") return sin(a);
		if (token == "cos") return cos(a);
		throw std::runtime_error("Unknown unary operator");
	}

	case 0:
		return strtod(token.c_str(), nullptr);
	}

	throw std::runtime_error("Unknown expression type");
}
