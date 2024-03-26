#include<iostream>

struct ArrayList {
	//fields
	int capacity;
	int count;
	int* data;
	
	//constructor is a function that is invoked when the element is created
	// the constructor has no return value and its' name is the same as struct name
	// all the fields should be initialized inside of the constructor
	//ArrayList() //default constructor - no parameters
	//{
	//	count = 0;
	//	capacity = 10;
	//	data = new int[10];
	//}

	//ArrayList(int cap = 10) //parametrized construct - 1 parameter
	//{
	//	count = 0;
	//	capacity = cap;
	//	data = new int[capacity];
	//}

	ArrayList(int capacity = 1) :
		capacity(capacity), count(0), data(new int[capacity] { 0 })
	{}

	//copy constructor
	ArrayList(const ArrayList& src) :
		capacity(src.count), count(src.count), data(new int[src.count] { 0 })
	{
		for (int i = 0; i < src.count; ++i)
		{
			data[i] = src.data[i];
		}
	}

	//desctructor
	~ArrayList()
	{
		delete[] data;
	}

	//methods
	void expand()
	{
		int newCapacity = capacity * 2;
		int* newData = new int[newCapacity] { 0 };
		for (int i = 0; i < capacity; ++i)
		{
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		capacity = newCapacity;
	}

	void push_back(int element)
	{
		while (count >= capacity) {
			expand();
		}
		data[count++] = element;
	}

	void print()
	{
		std::cout << count << "/" << capacity << ": ";
		for (int i = 0; i < count; ++i)
		{
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}

};

void increaseElements(ArrayList list, int add = 1)
{
	for (int i = 0; i < list.count; ++i)
	{
		list.data[i] += add;
	}
	list.print();
}

int main(int argc, char* argv[])
{
	ArrayList list;
	{
		list.push_back(5);
		list.print();
		list.push_back(4);
		list.print();
		list.push_back(3);
		list.print();
		list.push_back(2);
		list.print();
		list.push_back(2);
		list.print();
		list.push_back(2);
		list.print();
	}
	int a = 1;
	// 6/8: 5 4 3 2 2 2
	increaseElements(list, a);
	// 6/8: 5 4 3 2 2 2
	list.print();
	std::cout << a << std::endl; // 1

	ArrayList list1(10);
	ArrayList list2(4);
	ArrayList list3;
	ArrayList list4(list3);
	ArrayList list5(list2);
	ArrayList list6(list1);


	return EXIT_SUCCESS;
}