#include<iostream>

template<class T>
class Array
{
	/*
	4 constructors
	destructor
	operators:
		Array<T> = Array<T>
		Array<T> == Array<T>
		Array<T> += T
		Array<T> += Array<T>
		operator[]
		std::cout << Array<T>
	push_back(T)
	push_head(T)
	insert(ind, T)
	pop_back()
	pop_head()
	extract(ind)
	swap(ind1, ind2)
	*/

private:
	T* data;
	int len;
};

int main(int argc, char* argv[])
{

	return EXIT_SUCCESS;
}