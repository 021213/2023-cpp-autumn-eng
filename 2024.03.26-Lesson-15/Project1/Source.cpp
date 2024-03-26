#include<iostream>

//incapsulation
//struct -> public by default
//class -> private by default
class ArrayList {
public:
	ArrayList(int capacity = 1) : _capacity(capacity), _size(0), _data(new int[capacity] { 0 }), _err(0) {}
	
	ArrayList(const ArrayList& src) : _capacity(src._size), _size(src._size), _data(new int[_size] { 0 }), _err(0)
	{
		for (int i = 0; i < _size; _data[i] = src._data[i++]);
	}

	~ArrayList()
	{
		delete[] _data;
	}

	void print(std::ostream& stream)
	{
		stream << "[" << _size << "/" << _capacity << "] : ";
		for(int i = 0; i < _size; ++i)
		{
			stream << _data[i] << " ";
		}
		stream << std::endl;
	}

	void push_back(int el)
	{
		while (_size >= _capacity)
		{
			expand();
		}
		_data[_size++] = el;
	}

	int size() //getter
	{
		return _size;
	}

	void setSize(int newSize)
	{
		if (indexValid(newSize))
		{
			_size = newSize;
		}
		else if (_size <= newSize && newSize < _capacity)
		{
			_size = newSize;
		}
		else
		{
			expand(newSize - _capacity + 1);
			_size = newSize;
		}
	}

	void set(int index, int val)
	{
		if (indexValid(index))
		{
			_data[index] = val;
		}
		else if (index == _size)
		{
			push_back(val);
		}
	}

	int& cell(int index)
	{
		if (indexValid(index))
		{
			return _data[index];
		}
		else if (index == _size)
		{
			push_back(0);
			return _data[index];
		}
		else
		{
			return _err;
		}
	}

	int& operator[](int index)
	{
		if (indexValid(index))
		{
			return _data[index];
		}
		else if (index == _size)
		{
			push_back(0);
			return _data[index];
		}
		else
		{
			return _err;
		}
	}

	ArrayList& operator+=(int el)
	{
		push_back(el);
		return *this;
	}

	ArrayList& operator=(const ArrayList& src)
	{
		delete[] _data;
		_size = src._size;
		_capacity = src._capacity;
		_data = new int[_capacity];
		for (int i = 0; i < _size; _data[i] = src._data[i++]);
		return *this;
	}
	
	friend std::ostream& operator<<(std::ostream& stream, ArrayList& list);

private:
	bool indexValid(int index)
	{
		return (0 <= index && index < _size);
	}
	void expand(int add = 0)
	{
		add = (add == 0 ? _capacity : add);
		int* newdata = new int[_capacity + add]{ 0 };
		for (int i = 0; i < _size; newdata[i] = _data[i++]);
		delete[] _data;
		_data = newdata;
		_capacity += add;
	}
	int _capacity;
	int _size;
	int* _data;
	int _err;
};

std::ostream& operator<<(std::ostream& stream, ArrayList& list)
{
	stream << "[" << list.size() << "/" << list._capacity << "] : ";
	for (int i = 0; i < list.size(); ++i)
	{
		stream << list[i] << " ";
	}
	return stream;
}

int main(int argc, char* argv[])
{
	ArrayList list;
	list.push_back(1);
	list.print(std::cout);
	list.push_back(2);
	list.print(std::cout);
	list.push_back(3);
	list.print(std::cout);
	list.push_back(4);
	list.print(std::cout);
	//list.capacity = 1;
	list.print(std::cout);
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.print(std::cout);
	list.setSize(9);
	list.set(8, 10);
	list.print(std::cout);
	list.cell(7) = 20;
	list.print(std::cout);

	for (int i = 0; i < list.size(); ++i)
	{
		std::cout << list.cell(i) << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < list.size(); ++i)
	{
		std::cout << list[i] << " ";
	}
	std::cout << std::endl;

	(list += 30) += 40;
	list.print(std::cout);

	ArrayList list2;
	list2[0] = 0;
	list2[1] = 1;
	list2[2] = 2;

	ArrayList list3;
	list3[0] = 3;
	list3[1] = 4;
	list3[2] = 5;

	std::cout << std::endl << "= operator test" << std::endl << "BEFORE" << std::endl;
	list.print(std::cout);
	list2.print(std::cout);
	list3.print(std::cout);
	std::cout << "AFTER" << std::endl;
	list3 = list = list2;
	std::cout << list << std::endl;
	std::cout << list2 << std::endl;
	std::cout << list3 << std::endl;
	std::cout << std::endl;

	return EXIT_SUCCESS;
}