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
	LinkedList() : head(nullptr), length(0) {}
	LinkedList(const LinkedList& list) : head(nullptr), length(list.length)
	{
		head = copy(list.head);
	}
	LinkedList(LinkedList&& list) noexcept
	{
		length = list.length;
		head = list.head;
		list.length = 0;
		list.head = nullptr;
	}

	~LinkedList() {
		dispose();
	}
	void PushHead(T data)
	{
		return InsertNode(0, new Node<T>(data));
	}
	void Insert(int index, T data)
	{
		return InsertNode(index, new Node<T>(data));
	}
	void PushTail(T data)
	{
		return InsertNode(Length(), new Node<T>(data));
	}
	T PopHead()
	{
		return PopNode(ExtractNode(0));
	}
	T Extract(int index)
	{
		return PopNode(ExtractNode(index));
	}
	T PopTail()
	{
		return PopNode(ExtractNode(Length() - 1));
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
		return length;
	}

	void swap(int ind1, int ind2)
	{
		if (!IndexValid(ind1) || !IndexValid(ind2) || ind1 == ind2)
		{
			return;
		}
		if (ind1 < ind2)
		{
			return swap(ind2, ind1);
		}

		Node<T>* node1 = ExtractNode(ind1);
		Node<T>* node2 = ExtractNode(ind2);

		InsertNode(ind2, node1);
		InsertNode(ind1, node2);
	}
	void sort()
	{
		int i = 0;
		for (Node<T>* inode = head; inode != nullptr; inode = inode->next, ++i) {
			int j = 0;
			for (Node<T>* jnode = i->next; jnode != nullptr; jnode = jnode->next, ++j) {
				if (inode->data > jnode->data) {
					swap(i, j);
				}
			}
		}
	}
	void reverse()
	{
		Node<T>* prev = nullptr;
		Node<T>* current = head;
		Node<T>* next = nullptr;

		while (current != nullptr) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		head = prev;
	}
	friend LinkedList& operator+(T data, LinkedList& list)
	{
		list.PushHead(data);
		return list;
	}
	friend LinkedList& operator+(LinkedList& list, T data)
	{
		list.PushTail(data);
		return list;
	}
	friend LinkedList& operator+(LinkedList& list, LinkedList& add) {
		Node<T>* tail = list.head;
		while (tail->next != nullptr)
		{
			tail = tail->next;
		}
		tail->next = copy(add.head);
		list.length += add.length;
		return list;
	}
	friend LinkedList& operator+=(LinkedList& list, T data)
	{
		list.PushTail(data);
		return list;
	}
	friend LinkedList& operator+=(LinkedList& list, LinkedList& add)
	{
		Node<T>* tail = list.head;
		while (tail->next != nullptr)
		{
			tail = tail->next;
		}
		tail->next = copy(add.head);
		list.length += add.length;
		return list;
	}
	friend bool operator==(LinkedList& list1, LinkedList& list2)
	{
		if (list1.Length() != list2.Length())
		{
			return false;
		}

		Node<T>* temp1 = list1.head;
		Node<T>* temp2 = list2.head;

		while (temp1 != nullptr) {
			if (temp1->data != temp2->data)
			{
				return false;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}

		return true;
	}
	LinkedList& operator=(LinkedList& src) {
		if (this != &src)
		{
			dispose();
			head = copy(src.head);
			length = src.length;
		}
		return *this;
	}

private:
	Node<T>* head;
	int length;
	bool IndexValid(int index)
	{
		return 0 <= index && index < Length();
	}
	void InsertNode(int index, Node<T>* node)
	{
		if (!IndexValid(index) && index != Length())
		{
			delete node;
			return;
		}
		++length;
		if (index == 0)
		{
			node->next = head;
			head = node;
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
	Node<T>* ExtractNode(int index)
	{
		if (IsEmpty() || !IndexValid(index))
		{
			return nullptr;
		}
		--length;
		if (index == 0)
		{
			Node<T>* res = head;
			head = head->next;
			return res;
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
	Node<T>* copy(Node<T>* src)
	{
		if (src == nullptr)
		{
			return nullptr;
		}
		Node<T>* dst = new Node<T>(src->data);
		src = src->next;
		while (src != nullptr)
		{
			dst->next = new Node<T>(src->data);
			dst = dst->next;
			src = src->next;
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
