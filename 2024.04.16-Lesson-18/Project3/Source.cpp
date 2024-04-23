#include<iostream>
//LinkedList

template<class T>
struct Node {
	T data;
	Node<T>* next;
	Node(T data, Node<T>* next = nullptr) : data(data), next(next) {}
	friend std::ostream& operator<<(std::ostream& stream, Node<T>*& node)
	{
		stream << node->data;
		return stream;
	}
};

template<class T>
class LinkedList {
public:
	LinkedList() : head(nullptr) {}
	LinkedList(const LinkedList& list); //todo: implement
	LinkedList(LinkedList&& list) noexcept; //todo: implement

	~LinkedList() {
		dispose();
	}
	void PushHead(T data)
	{
		return InsertHeadNode(new Node<T>(data));
	}
	void Insert(int index, T data)
	{
		return InsertNode(index, new Node<T>(data));
	}
	void PushTail(T data)
	{
		return InsertTailNode(new Node<T>(data));
	}
	T PopHead()
	{
		return PopNode(ExtractHeadNode());
	}
	T Extract(int index)
	{
		return PopNode(ExtractNode(index));
	}
	T PopTail()
	{
		return PopNode(ExtractTailNode());
	}
	friend std::ostream& operator<<(std::ostream& stream, LinkedList<T>& list)
	{
		Node<T>* temp = list.head;
		while (temp != nullptr)
		{
			stream << temp << " ";
			temp = temp->next;
		}
		return stream;
	}
	bool IsEmpty()
	{
		return head == nullptr;
	}
	int Length()
	{
		int length = 0;
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			temp = temp->next;
			++length;
		}
		return length;
	}
	
	void swap(int ind1, int ind2); //todo: implement
	void sort(); //todo: implement
	void reverse(); //todo: implement
	friend LinkedList& operator+(LinkedList& list, T data); //todo: implement
	friend LinkedList& operator+(LinkedList& list, LinkedList& add); //todo: implement
	friend LinkedList& operator+=(LinkedList& list, T data); //todo: implement
	friend LinkedList& operator+=(LinkedList& list, LinkedList& add); //todo: implement
	friend bool operator==(LinkedList& list1, LinkedList& list2); //todo: implement
	LinkedList& operator=(LinkedList& src); //todo: implement

private:
	Node<T>* head;
	bool IndexValid(int index)
	{
		return 0 <= index && index < Length();
	}
	void InsertHeadNode(Node<T>* newHead)
	{
		newHead->next = head;
		head = newHead;
	}
	void InsertNode(int index, Node<T>* node)
	{
		if (index == 0)
		{
			return InsertHeadNode(node);
		}
		if (index == Length())
		{
			return InsertTailNode(node);
		}
		if (!IndexValid(index))
		{
			delete node;
			return;
		}
		Node<T>* temp = head;
		while (index > 1)
		{
			temp = temp->next;
			--index;
		}
		node->next = temp->next;
		temp->next = node;
	}
	void InsertTailNode(Node<T>* newTail)
	{
		if (IsEmpty())
		{
			return InsertHeadNode(newTail);
		}
		Node<T>* tail = head;
		while (tail->next != nullptr)
		{
			tail = tail->next;
		}
		tail->next = newTail;
		newTail->next = nullptr;
	}
	Node<T>* ExtractHeadNode()
	{
		if (IsEmpty())
		{
			return nullptr;
		}
		Node<T>* res = head;
		head = head->next;
		return res;
	}
	Node<T>* ExtractNode(int index)
	{
		if (index == 0)
		{
			return ExtractHeadNode();
		}
		if (index == Length() - 1)
		{
			return ExtractTailNode();
		}
		if (!IndexValid(index))
		{
			return nullptr;
		}
		Node<T>* temp = head;
		while (index > 1)
		{
			temp = temp->next;
			--index;
		}
		Node<T>* res = temp->next;
		temp->next = temp->next->next;
		return res;
	}
	Node<T>* ExtractTailNode()
	{
		if (IsEmpty() || head->next == nullptr)
		{
			return ExtractHeadNode();
		}

		Node<T>* pretail = head;
		while (pretail->next->next != nullptr)
		{
			pretail = pretail->next;
		}
		Node<T>* tail = pretail->next;
		pretail->next = nullptr;
		return tail;
	}
	T PopNode(Node<T>* node)
	{
		T data = T();
		if (node != nullptr)
		{
			data = node->data;
			delete node;
		}
		return data;
	}
	void dispose()
	{
		while (!IsEmpty())
		{
			PopHead();
		}
	}
};

int main(int argc, char* argv[])
{
	LinkedList<int> v;
	v.PushHead(1);
	v.PushHead(2);
	v.PushHead(3);
	v.PushHead(4);
	v.PushHead(5);
	std::cout << v << std::endl;
	while (!v.IsEmpty())
	{
		std::cout << v.PopHead() << " ";
	}
	std::cout << std::endl;

	v.PushTail(1);
	v.PushTail(2);
	v.PushTail(3);
	v.PushTail(4);
	v.PushTail(5);
	std::cout << v << std::endl;
	while (!v.IsEmpty())
	{
		std::cout << v.PopTail() << " ";
	}
	std::cout << std::endl;

	v.PushTail(1);
	v.PushTail(2);
	v.PushTail(3);
	v.PushTail(4);
	v.PushTail(5);
	v.Insert(4, 14);
	v.Insert(5, 15);
	v.Insert(2, 12);
	v.Insert(0, 10);
	v.Insert(9, 17);
	std::cout << v << std::endl;
	std::cout << v.Extract(3) << " -> " << v << std::endl;
	std::cout << v.Extract(0) << " -> " << v << std::endl;
	std::cout << v.Extract(7) << " -> " << v << std::endl;

	LinkedList<std::string> strList;
	return EXIT_SUCCESS;
}