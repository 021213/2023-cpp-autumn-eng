#include<iostream>
#include<string>

struct Subject {
	//fields
	std::string name;
	int* marks;
	//contructors
	Subject(std::string name = "DEFAULT") :
		//fields init
		name(name), marks(new int[10])
	{}
	//destructor
	~Subject()
	{
		delete[] marks;
	}
};

struct Student {
	std::string name;
	Subject* subjects;
	Student(std::string name = "Bob") :
		name(name), subjects(new Subject[10])
	{

	}
	~Student()
	{
		delete[] subjects;
	}
};

int main(int argc, char* argv[])
{

	return EXIT_SUCCESS;
}