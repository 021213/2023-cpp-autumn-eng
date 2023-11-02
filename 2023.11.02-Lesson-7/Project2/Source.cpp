#include<iostream>

struct Point {
	int x;
	int y;
	int z;

	Point() //default constructor
	{
		x = 0;
		y = 0;
		z = 0;
	}
	Point(int xx, int yy, int zz) //parametrized constructor
	{
		x = xx;
		y = yy;
		z = zz;
	}
	Point(Point p1, Point p2) //parametrized constructor
	{
		x = p1.x + p2.x;
		y = p1.y + p2.y;
		z = p1.z + p2.z;
	}
	//copy constructor
	//move constructor
	~Point() //destructor
	{
	}
};

void dosomething()
{
	Point p(1, 2, 3);
}

int main(int argc, char* argv[])
{
	Point p1{ 1, 2, 3 };
	Point p2( 1, 2, 3 );
	Point p3(p1, p2);
	dosomething();
	return EXIT_SUCCESS;
}