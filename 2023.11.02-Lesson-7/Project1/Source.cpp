#include<iostream>

struct Point{
	int x;
	int y;
	int z;
};

void printPoint(Point p)
{
	std::cout << "(" << p.x << "; " << p.y << "; " << p.z << ")" << std::endl;
}

void readPointPassByValue(Point p)
{
	std::cin >> p.x >> p.y >> p.z;
}

void readPointPassAddress(Point* p)
{
	//std::cin >> (*p).x >> (*p).y >> (*p).z;
	std::cin >> p->x >> p->y >> p->z;
}

void readPointByReference(Point& p)
{
	std::cin >> p.x >> p.y >> p.z;
}

int main(int argc, char* argv[])
{
	Point p;
	p.x = 3;
	p.y = 5;
	p.z = 9;

	Point p1{ 3, 2, 1 };
	printPoint(p);
	printPoint(p1);

	Point p2{ 0, 0, 0 };
	std::cout << "Pass value" << std::endl;
	readPointPassByValue(p2);
	printPoint(p2);
	std::cout << "Pass reference" << std::endl;
	readPointByReference(p2);
	printPoint(p2);
	std::cout << "Pass address" << std::endl;
	readPointPassAddress(&p2);
	printPoint(p2);

	return EXIT_SUCCESS;
}