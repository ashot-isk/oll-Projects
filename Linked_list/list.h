#include <iostream>
#include <initializer_list>
using namespace std;
template <typename T>
class list
{

private:
	struct node
	{
		T mData;
		node *mNext;

		node(T mData = T(), node *mNext = nullptr) : mData{mData}, mNext{mNext}
		{
		}
	};

	int size;
	node *head;

public:
	int get_size() { return size; }
	void remove(T key);
	void push_front(T mData);
	void pop_front();
	list &operator=(const list<T> &rhs);
	list &operator=(list<T> &&rhs);
	list(const list<T> &ctor); // copy ctor
	list(list<T> &&mtor);	   // muve ctor
	T operator[](const int index);
	void insert(int index, T mData);
	list();
	list(initializer_list<T> its) : list()
	{
		node *current;
		this->head = current;
		typename initializer_list<T>::iterator it;
		for (it = its.begin(); it != its.end(); ++it)
		{
			current->mNext = new node();
			current->mData = *it;
			current = current->mNext;
			++this->size;
		}
		current->mNext == nullptr;
	}
	~list();
};

template <typename T>
list<T>::list()
{
	this->head = nullptr;
	this->size = 0;
}
template <typename T>
list<T>::~list()
{
}

template <typename T>
list<T>::list(const list<T> &ctor)
{
	this->size = ctor.size;
	node *current = new node();
	this->head = current;
	node *current2 = ctor.head;
	this->head->mData = current2->mData;
	current2 = current2->mNext;
	for (current2; current2 != nullptr; current2 = current2->mNext)
	{

		node *tmp = new node();
		current->mNext = tmp;
		current = current->mNext;
		current->mData = current2->mData;
	}
}

template <typename T>
list<T>::list(list<T> &&mtor)
{
	this->size = mtor.size;
	this->head = mtor.head;
	mtor.head = nullptr;
}

template <typename T>
list<T> &list<T>::operator=(const list<T> &rhs)
{
	if (&rhs == this)
	{
		return *this;
	}
	while (size != 0)
	{
		this->pop_front();
		--size;
	}

	this->size == rhs.size;
	node *current = new node();
	this->head = current;
	node *current2 = rhs.head;
	this->head->mData = current2->mData;
	current2 = current2->mNext;
	for (current2; current2 != nullptr; current2 = current2->mNext)
	{

		node *tmp = new node();
		current->mNext = tmp;
		current = current->mNext;
		current->mData = current2->mData;
	}
	return *this;
}

template <typename T>
list<T> &list<T>::operator=(list<T> &&rhs)
{
	while (size != 0)
	{
		this->push_front();
		--size;
	}
	this->size = rhs.size;
	this->head = rhs.head;
	rhs.head = nullptr;
}
template <typename T>
void list<T>::push_front(T mData)
{
	if (this->head == nullptr)
	{
		head = new node(mData);
	}
	else
	{
		node *reserve = head;
		head = new node(mData);
		head->mNext = reserve;
	}
	size++;
}

template <typename T>
void list<T>::pop_front()
{
	node *current = head;
	head = current->mNext;
	delete current;
	size--;
}

template <typename T>
T list<T>::operator[](const int index)
{
	int count = 0;
	node *current = head;
	while (current != nullptr)
	{

		if (count == index)
		{
			return current->mData;
		}
		current = current->mNext;
		count++;
	}
	return T();
}
template <typename T>
void list<T>::insert(int index, T mData)
{
	int counter = 0;
	node *current = head;
	while (current->mNext != nullptr)
	{
		if (counter == index)
		{
			node *reserve = current->mNext;
			current->mNext = new list<T>::node(mData);
			current = current->mNext;
			current->mNext = reserve;
		}
		current = current->mNext;
		counter++;
	}
	size++;
}

template <typename T>
void list<T>::remove(T key)
{
	for (int i = 0; i < size; ++i)
	{
		if ((head->mData) == key)
		{
			pop_front();
		}
	}
	node *t = head;
	for (int i = 0;; i++)
	{
		if (t->mNext == nullptr)
		{
			return;
		}
		if (((t->mNext)->mData) == key)
		{

			node *tmp2 = (t->mNext)->mNext;
			delete[] t->mNext;
			--size;
			t->mNext = tmp2;
		}
		else
		{
			t = t->mNext;
		}
	}
}
