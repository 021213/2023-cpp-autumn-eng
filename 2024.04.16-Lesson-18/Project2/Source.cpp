#include<iostream>

class SubjectMark
{
	int mark;
	int coeff;
	//all types of constructors, destructor and operators == = 
	// operator <<
};

class Subject {
	std::string name;
	SubjectMark* marks;
	//copy it correctly in copy and move constructor
	//all types of constructors destructor and operators. == =
	//   operator Subject + SubjectMark
	//   operator Subject += SubjectMark
	// operator <<
};

class Student {
private:
	std::string name;	// who to write it in move constructor?  std::move
	int age;			// std::exchange
	Subject* subjects;	//copy it correctly in copy and move constructor

public:
	//all types of constructors
	//destructor
	//all types of needed operators:
	// = assign operator - assign one Student to another;
	// == equal - compare Students
	//  Student += Subject
	//  Student + Subject
	// operator <<
};

int main(int argc, char* argv[])
{
	return EXIT_SUCCESS;
}