#include<iostream>

int gcd(int a, int b)
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

class Fraction {
private:
	int _num;
	int _den;
	int _whole;


	void reduce() {
		int gc = gcd(_num, _den);
		_num /= gc;
		_den /= gc;
		if (_num >= _den) {
			_whole += _num / _den;
			_num %= _den;
		}
	};
public:
	Fraction(int w, int n, int d) : _whole(w), _num(n), _den(d) {
		reduce();
		if (_den == 0) {
			std::cerr << "Error: Denominator cannot be zero." << std::endl;
			exit(EXIT_FAILURE);
		}
	};

	Fraction(int n, int d) : _whole(0), _num(n), _den(d) {
		reduce();
		if (_den == 0) {
			std::cerr << "Error: Denominator cannot be zero." << std::endl;
			exit(EXIT_FAILURE);
		}
	};

	Fraction(const Fraction& other) : Fraction(other._whole, other._num, other._den)
	{
	}

	Fraction(Fraction&& other) noexcept :
		_whole(std::exchange(other._whole, 0)),
		_num(std::exchange(other._num, 0)),
		_den(std::exchange(other._den, 0))
	{
	}

	~Fraction() {
	}

	Fraction operator+(const Fraction& other) const {
		int num = _whole * _den + _num;
		int den = _den * other._den;
		num = num * other._den + (other._whole * other._den + other._num) * _den;
		return Fraction(num, den);
	}
	Fraction operator-(const Fraction& other) const {
		int num = _whole * _den + _num;
		int den = _den * other._den;
		num = num * other._den - (other._whole * other._den + other._num) * _den;
		return Fraction(num, den);
	}

	Fraction operator*(const Fraction& other) const {
		int num = (_whole * _den + _num) * (other._whole * other._den + other._num);
		int den = _den * other._den;
		return Fraction(num, den);
	}

	Fraction operator/(const Fraction& other) const {
		int num = (_whole * _den + _num) * other._den;
		int den = _den * (other._whole * other._den + other._num);
		return Fraction(num, den);
	}
	friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
		if (fraction._whole != 0)
		{
			os << fraction._whole;
		}
		if (fraction._num != 0) {
			if (fraction._whole != 0)
			{
				os << " ";
			}
			os << fraction._num << "/" << fraction._den;
		}
		return os;
	}
};

int main(int argc, char* argv)
{
	//    ((3,8  * 1 4/7 - 2,5 * 3,8) * 4 3/14 - 1/14) / 2,5
	//    3,8  * 1 4/7 - 2,5 * 3,8
	Fraction r1(Fraction(3, 8, 10) * Fraction(1, 4, 7) - Fraction(2, 5, 10) * Fraction(3, 8, 10));
	//    r1 * 4 3/14 - 1/14
	Fraction r2(r1 * Fraction(4, 3, 14) - Fraction(1, 14));
	//    r2 / 2,5
	Fraction r3(r2 / Fraction(2, 5, 10));
	//std::cout << r3;
	std::cout << (
		(
			Fraction(3, 8, 10) * Fraction(1, 4, 7) -
			Fraction(2, 5, 10) * Fraction(3, 8, 10)
			) * Fraction(4, 3, 14) - Fraction(1, 14)
		) / Fraction(2, 5, 10);
	/*Fraction r1(Fraction(3, 8, 10) * Fraction(1, 4, 7));
	std::cout << r1;*/
	return EXIT_SUCCESS;
}
