#include<iostream>

using namespace std;

class Fraction {
public:
	Fraction(int num, int den) : _numerator(), _denomenator() {};
	Fraction(int whole, int num, int den) : _numerator(), _denomenator() {};
	Fraction operator+(Fraction f);
	Fraction operator-(Fraction f);
	Fraction operator*(Fraction f);
	Fraction operator/(Fraction f);
	friend ostream& operator<<(std::ostream& stream, Fraction f);
private:
	int _numerator;
	int _denomenator;
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
	std::cout << r3;
	std::cout << (
		(
			Fraction(3, 8, 10) * Fraction(1, 4, 7) -
			Fraction(2, 5, 10) * Fraction(3, 8, 10)
		) * Fraction(4, 3, 14) - Fraction(1, 14)
		) / Fraction(2, 5, 10);
	return EXIT_SUCCESS;
}