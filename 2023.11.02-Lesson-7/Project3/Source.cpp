#include<iostream>

struct Point {
	int x;
	int y;
	int z;

	Point(int x = 0, int y = 0, int z = 0) :
		x(x), y(y), z(z)
	{
		/*
		this->x = x;
		this->y = y;
		this->z = z;
		*/
	}
	~Point() //destructor
	{
	}
};

void Print(Point p)
{
	std::cout << "(" << p.x << "; " << p.y << "; " << p.z << ")" << std::endl;
}

int main(int argc, char* argv[])
{
	Point p1;
	Point p2(1, 2, 3);
	Print(p1);
	return EXIT_SUCCESS;
}