#include<iostream>
#include<string>

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
	int _num; // int                  n / m | n - real and m > 0
	int _dem; // unsinged int
	int _whole;
	std::string cash;

	void reduce() {
		int gc = gcd(_num, _dem);
		_num /= gc;
		_dem /= gc;
		if (_num >= _dem) {
			_whole += _num / _dem;
			_num %= _dem;
		}
	};

public:
	Fraction(int w, int n, int d) : _whole(w), _num(n), _dem(d) {
		reduce();
		if (_dem == 0) {
			std::cerr << "Error: Denominator cannot be zero." << std::endl;
			exit(EXIT_FAILURE);
		}
	};
	Fraction(int n, int d) : _whole(0), _num(n), _dem(d) {
		reduce();
		if (_dem == 0) {
			std::cerr << "Error: Denominator cannot be zero." << std::endl;
			exit(EXIT_FAILURE);
		}
	};
	Fraction(const Fraction& other) : _whole(other._whole), _num(other._num), _dem(other._dem) {};
	Fraction(Fraction&& other) noexcept :
		_num(std::exchange(other._num, 0)),
		cash(std::move(other.cash))
	{
		_whole = other._whole;
		_dem = other._dem;
	};
	~Fraction() {
	}

	Fraction operator=(const Fraction& other)
	{
		_whole = other._whole;
		_num = other._num;
		_dem = other._dem;
	}

	Fraction operator==(const Fraction& other)
	{
		return (_whole == other._whole) && (_num == other._num) && (_dem == other._dem);
	}

	Fraction operator+(const Fraction& other) const {
		int num = _whole * _dem + _num;
		int den = _dem;
		num = num * other._dem + (other._whole * other._dem + other._num) * den;
		return Fraction(num, den * other._dem);
	}

	Fraction operator-(const Fraction& other) const {
		int num = _whole * _dem + _num;
		int den = _dem;
		num = num * other._dem - (other._whole * other._dem + other._num) * den;
		return Fraction(num, den * other._dem);
	}

	Fraction operator*(const Fraction& other) const {
		int num = (_whole * _dem + _num) * (other._whole * other._dem + other._num);
		int den = _dem * other._dem;
		return Fraction(num, den);
	}

	Fraction operator/(const Fraction& other) const {
		int num = (_whole * _dem + _num) * other._dem;
		int den = _dem * (other._whole * other._dem + other._num);
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
			os << fraction._num << "/" << fraction._dem;
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
