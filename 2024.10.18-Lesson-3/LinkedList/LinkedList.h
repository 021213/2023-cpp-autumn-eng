#pragma once
#include<ostream>

template<class T>
struct Node {
	T data;
	Node<T>* next;
	Node(T data = T(), Node<T>* next = nullptr) : data(data), next(next) {}
	~Node()
	{
		data = T();
		next = nullptr;
	}
	friend std::ostream& operator<<(std::ostream& stream, Node<T>*& node)
	{
		stream << node->data;
		return stream;
	}
};

template <class T>
class LinkedList
{
public:
	LinkedList()
	{
		spare = T();
		head = nullptr;
	}
	LinkedList(const LinkedList<T>& list)
	{
		spare = T();
		head = nullptr;
		if (list.head == nullptr)
		{
			return;
		}
		Node<T>* tmpSrc = list.head;
		head = new Node<T>(tmpSrc->data);
		tmpSrc = tmpSrc->next;
		Node<T>* tmpDst = head;
		while (tmpSrc != nullptr)
		{
			tmpDst->next = new Node<T>(tmpSrc->data);
			tmpDst = tmpDst->next;
			tmpSrc = tmpSrc->next;
		}
	}
	~LinkedList()
	{
		while (head != nullptr)
		{
			Node<T>* tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	void push_front(T element)
	{
		head = new Node<T>(element, head);
	}
	void push_back(T element)
	{
		if (head == nullptr)
		{
			return push_front(element);
		}
		Node<T>* tmp = head;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = new Node<T>(element);
	}
	void insert(int index, T element)
	{
		if (index == 0)
		{
			return push_front(element);
		}
		Node<T>* tmp = head;
		for (int i = 0; i < index - 1 && tmp != nullptr; ++i)
		{
			tmp = tmp->next;
		}
		if (tmp != nullptr)
		{
			tmp->next = new Node<T>(element, tmp->next);
		}
	}

	T pop_front()
	{
		if (head == nullptr)
		{
			return spare;
		}
		T res = head->data;
		Node<T>* tmp = head;
		head = head->next;
		delete tmp;
		return res;
	}
	T pop_back()
	{
		if (head == nullptr)
		{
			return spare;
		}
		if (head->next == nullptr)
		{
			return pop_front();
		}
		Node<T>* tmp = head;
		while (tmp->next->next != nullptr)
		{
			tmp = tmp->next;
		}
		T res = tmp->next->data;
		delete tmp->next;
		tmp->next = nullptr;
		return res;
	}
	T extract(int index)
	{
		if (head == nullptr)
		{
			return spare;
		}
		if (index == 0)
		{
			return pop_front();
		}
		Node<T>* tmp = head;
		for(int i = 0; i < index - 1 && tmp->next != nullptr; ++i)
		{
			tmp = tmp->next;
		}
		if (tmp->next == nullptr)
		{
			return spare;
		}
		T res = tmp->next->data;
		Node<T>* toDelete = tmp->next;
		tmp->next = tmp->next->next;
		delete toDelete;
		return res;
	}

	/*TODO: implement all unimplemented methods in LinkedList.h*/
	T& operator[](int index);
	LinkedList<T>& operator=(LinkedList<T>& list);
	LinkedList<T>& operator+(LinkedList<T>& list);
	LinkedList<T>& operator+(T element);
	bool operator==(LinkedList<T>& list);
	friend std::ostream& operator<<(std::ostream& stream, LinkedList<T>& list)
	{
		Node<T>* tmp = list.head;
		stream << "{ ";
		while (tmp != nullptr)
		{
			stream << tmp << " ";
			tmp = tmp->next;
		}
		stream << "}";
		return stream;
	}

private:
	T spare;
	Node<T>* head;
};
