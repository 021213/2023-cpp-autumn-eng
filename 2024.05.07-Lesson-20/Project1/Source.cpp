#include<iostream>

template<class T>
struct Node
{
	T data;
	Node<T>* next;
	Node(T data, Node<T>* next = nullptr) :data(data), next(next) {}
	friend std::ostream& operator<<(std::ostream& stream, Node<T>* node)
	{
		stream << node->data;
		return stream;
	}
};

template<class T>
class CycleList
{
public:
	CycleList() : tail(nullptr), length(0) {}
	// copy and move constructor, destructor
	// assign operator
	// compare operator
	// all the same as in BiLinkedList
	friend std::ostream& operator<<(std::ostream& stream, CycleList<T>& list)
	{
		stream << "[" << list.length << "] ";
		if (list.tail == nullptr)
		{
			stream << "EMPTY";
			return stream;
		}
		Node<T>* temp = list.tail->next;
		do
		{
			stream << temp << " ";
			temp = temp->next;
		} while (temp != list.tail->next);
		return stream;
	}
	int PopHead()
	{
		return ExtractDataFromNode(ExtractNode(0));
	}
	int Extract(int index)
	{
		return ExtractDataFromNode(ExtractNode(index));
	}
	int PopTail()
	{
		return ExtractDataFromNode(ExtractNode(length - 1));
	}

	void PushHead(T data)
	{
		InsertNode(0, new Node<T>(data));
	}
	void Insert(int index, T data)
	{
		if (index == length)
		{
			PushTail(data);
		}
		else
		{
			InsertNode(index, new Node<T>(data));
		}
	}
	void PushTail(T data)
	{
		PushHead(data);
		tail = tail->next;
	}
private:
	Node<T>* tail;
	int length;
	bool IndexValid(int index)
	{
		return (0 <= index && index < length);
	}
	Node<T>* NodeAtIndex(int index)
	{
		Node<T>* temp = tail;
		while (index > 1)
		{
			index--;
			temp = temp->next;
		}
		return temp->next;
	}
	void InsertNode(Node<T>* prev, Node<T>* inserted)
	{
		inserted->next = prev->next;
		prev->next = inserted;
		this->length++;
	}
	void InsertNode(int index, Node<T>* inserted)
	{
		if (index == 0)
		{
			if (tail == nullptr)
			{
				tail = inserted;
				tail->next = tail;
				this->length++;
			}
			else
			{
				InsertNode(tail, inserted);
			}
			return;
		}
		if (!IndexValid(index))
		{
			return;
		}
		InsertNode(NodeAtIndex(index), inserted);
	}
	Node<T>* ExtractNode(int index)
	{
		if (!IndexValid(index))
		{
			return nullptr;
		}
		if (length == 1)
		{
			Node<T>* node = tail->next;
			tail = nullptr;
			--length;
			return node;
		}

		Node<T>* prev = nullptr;
		if (index == length - 1)
		{
			prev = NodeAtIndex(length - 1);
			tail = prev;
		}
		else
		{
			prev = tail;
			while (index > 0)
			{
				prev = prev->next;
				--index;
			}
		}
		Node<T>* res = prev->next;
		prev->next = prev->next->next;
		--length;
		return res;
	}
	T ExtractDataFromNode(Node<T>* node)
	{
		if (node == nullptr)
		{
			return T();
		}
		T res(node->data);
		delete node;
		return res;
	}
};

int main(int argc, char* argv[])
{
	CycleList<int> intList;
	intList.PushHead(1);
	std::cout << intList << std::endl;
	intList.PushHead(0);
	std::cout << intList << std::endl;
	intList.PushTail(3);
	intList.PushTail(4);
	std::cout << intList << std::endl;
	intList.PushTail(5);
	intList.PushTail(6);
	std::cout << intList << std::endl;

	intList.Insert(2, 2);
	std::cout << intList << std::endl;
	intList.Insert(0, -1);
	std::cout << intList << std::endl;

	intList.Insert(8, 7);

	std::cout << intList << std::endl;


	std::cout << "POP : " << intList.PopHead() << std::endl;
	std::cout << "POP : " << intList.PopHead() << std::endl;
	std::cout << "POP : " << intList.PopTail() << std::endl;
	std::cout << "POP : " << intList.PopTail() << std::endl;
	std::cout << "POP : " << intList.Extract(2) << std::endl;
	std::cout << intList << std::endl;

	return EXIT_SUCCESS;
}