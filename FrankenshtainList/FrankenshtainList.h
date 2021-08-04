#include <iostream>
#include <initializer_list>
using namespace std;

template <typename T>
class FrankenshtainList
{
private:
	struct node
	{
		T data;
		node *next;
		node *prev;
		node *asc;
		node *desc;
		node();
		node(T d) : data{d}, next{nullptr}, prev{nullptr}, asc{nullptr}, desc{nullptr}
		{
		}
	};

	node *tail;
	node *m_asc;
	node *m_desc;
	node *head;

public:
	class iterator
	{
	private:
	public:
		node *tmp;

		iterator() : tmp{nullptr}
		{
		}

		iterator(node *cur)
		{
			this->tmp = cur;
		}

		iterator operator++()
		{
			tmp = tmp->next;
			return *this;
		}

		iterator operator--()
		{
			tmp = tmp->prev;
			return *this;
		}

		iterator operator++(T)
		{
			iterator cur = *this;
			tmp = tmp->next;
			return cur;
		}

		iterator operator--(T)
		{
			iterator cur = *this;
			tmp = tmp->prev;
			return cur;
		}

		T operator*()
		{
			return tmp->data;
		}

		bool operator!=(const iterator &rhs)
		{
			return this->tmp != rhs.tmp;
		}

		bool operator==(const iterator &rhs)
		{
			return this->tmp == rhs.tmp;
		}
	};

	iterator begin()
	{
		return iterator(this->head);
	}

	iterator end()
	{
		return iterator(this->tail);
	}

	void revers()
	{
		 if (head == nullptr || !head->next)
		{
			return ;
		}
		// revers(head->next);
		// head->next->next = head;
		// head->next = nullptr;
		//{
			// Initialize current, previous and
			// next pointers
			// node *current = head;
			// node *preve = nullptr, *nexte = nullptr;

			// while (current != nullptr)
			// {
			// 	nexte = current->next;
			// 	current->next = preve;
			// 	preve = current;
			// 	current = nexte;
			// }
			// head = preve;
	
	}
	void remove(T key); //ches arel
	void erase(int pos);
	void erase(const iterator &it);
	void erase();
	void insert(const int pos, T data);
	void sort(node *);
	void deleteSort(node *);
	void push_front(T);
	void pop_front();
	void push_back(T);
	void pop_back();
	void print();
	int size();
	FrankenshtainList(T);
	FrankenshtainList();
	FrankenshtainList(initializer_list<T> its) : FrankenshtainList()
	{
		typename initializer_list<T>::iterator it;
		for (it = its.begin(); it < its.end(); ++it)
		{
			this->push_back(*it);
		}
	}
	FrankenshtainList(const FrankenshtainList<T> &rhs);
	FrankenshtainList(FrankenshtainList<T> &&tmp);
	FrankenshtainList<T> &operator=(const FrankenshtainList<T> &rhs);
	FrankenshtainList<T> &operator=(FrankenshtainList<T> &&tmp);
	~FrankenshtainList();
};

template <typename T>
FrankenshtainList<T>::FrankenshtainList() : head{nullptr}, tail{nullptr}, m_asc{nullptr}, m_desc{nullptr}
{
}

template <typename T>
FrankenshtainList<T>::~FrankenshtainList()
{
}

template <typename T>
FrankenshtainList<T>::FrankenshtainList(const FrankenshtainList<T> &rhs)
{
	node *current = rhs.head;
	FrankenshtainList<T> tmp;
	while (current != nullptr)
	{
		tmp.push_back(current->data);
		current = current->next;
	}
	this->head = tmp.head;
	this->m_desc = tmp.m_desc;
	this->m_asc = tmp.m_asc;
	this->tail = tmp.tail;
	tmp.tail = nullptr;
	tmp.m_desc = nullptr;
	tmp.head = nullptr;
	tmp.m_asc = nullptr;
}

template <typename T>
FrankenshtainList<T>::FrankenshtainList(FrankenshtainList<T> &&rhs)
{
	this->head = rhs.head;
	this->m_desc = rhs.m_desc;
	this->m_asc = rhs.m_asc;
	this->tail = rhs.tail;
	rhs.tail = nullptr;
	rhs.m_desc = nullptr;
	rhs.head = nullptr;
	rhs.m_asc = nullptr;
}

template <typename T>
FrankenshtainList<T> &FrankenshtainList<T>::operator=(const FrankenshtainList<T> &rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	while (this->head != nullptr)
	{
		node *tmp = head;
		head = head->next;
		delete tmp;
	}

	node *current = rhs.head;
	FrankenshtainList<T> tmp;
	while (current != nullptr)
	{
		tmp.push_back(current->data);
		current = current->next;
	}
	this->head = tmp.head;
	this->m_desc = tmp.m_desc;
	this->m_asc = tmp.m_asc;
	this->tail = tmp.tail;
	tmp.tail = nullptr;
	tmp.m_desc = nullptr;
	tmp.head = nullptr;
	tmp.m_asc = nullptr;
	return *this;
}

template <typename T>
FrankenshtainList<T> &FrankenshtainList<T>::operator=(FrankenshtainList<T> &&tmp)
{
	this->head = tmp.head;
	this->m_desc = tmp.m_desc;
	this->m_asc = tmp.m_asc;
	this->tail = tmp.tail;
	tmp.tail = nullptr;
	tmp.m_desc = nullptr;
	tmp.head = nullptr;
	tmp.m_asc = nullptr;
	return *this;
}

template <typename T>
void FrankenshtainList<T>::print()
{
	node *cur = m_desc;
	cout << "mdesc-> ";
	while (cur != nullptr)
	{
		cout << cur->data << " ";
		cur = cur->desc;
	}
	cout << endl;
	cout << endl;
	node *c = m_asc;
	cout << "m_asc-> ";
	while (c != nullptr)
	{
		cout << c->data << " ";
		c = c->asc;
	}
	cout << endl;
	cout << endl;

	node *cu = head;
	cout << "head -> ";
	while (cu != nullptr)
	{
		cout << cu->data << " ";
		cu = cu->next;
	}
	cout << endl;
	cout << endl;

	node *ur = tail;
	cout << "tail -> ";
	while (ur != nullptr)
	{
		cout << ur->data << " ";
		ur = ur->prev;
	}
	cout << endl;
}

template <typename T>
void FrankenshtainList<T>::sort(node *tmp)
{
	if (m_asc->data >= tmp->data)
	{
		tmp->asc = m_asc;
		m_asc->desc = tmp;
		m_asc = tmp;
		tmp->desc = nullptr;
		return;
	}

	if (m_desc->data <= tmp->data)
	{
		tmp->desc = m_desc;
		m_desc->asc = tmp;
		m_desc = tmp;
		tmp->asc = nullptr;
		return;
	}

	node *cur = m_asc;
	while (cur->asc != nullptr)
	{
		cur = cur->asc;
		if (cur->data >= tmp->data)
		{
			tmp->asc = cur;
			tmp->desc = cur->desc;
			tmp->desc->asc = tmp;
			cur->desc = tmp;
			return;
		}
	}
}

template <typename T>
void FrankenshtainList<T>::deleteSort(node *tmp)
{
	if (m_asc->data == tmp->data)
	{
		m_asc = m_asc->asc;
		m_asc->desc = nullptr;
		return;
	}

	if (m_desc->data == tmp->data)
	{
		m_desc = m_desc->desc;
		m_desc->asc = nullptr;
		return;
	}

	tmp->asc->desc = tmp->desc;
	tmp->desc->asc = tmp->asc;
}

template <typename T>
FrankenshtainList<T>::FrankenshtainList(T data)
{
	head = new node(data);
	tail = head;
	m_asc = head;
	m_desc = head;
}

template <typename T>
void FrankenshtainList<T>::push_front(T m_data)
{
	node *tmp = new node(m_data);
	if (!head)
	{
		head = tmp;
		tail = tmp;
		m_asc = tmp;
		m_desc = tmp;
	}
	else
	{
		tmp->next = head;
		tmp->prev = nullptr;
		head->prev = tmp;
		head = tmp;
		sort(tmp);
	}
}

template <typename T>
void FrankenshtainList<T>::pop_front()
{
	if (!head->next)
	{
		delete head;
		head = nullptr;
		m_desc = nullptr;
		m_asc = nullptr;
		tail = nullptr;
	}
	node *tmp = head;
	deleteSort(tmp);
	head = tmp->next;
	head->prev = nullptr;
	delete tmp;
}

template <typename T>
void FrankenshtainList<T>::pop_back()
{
	if (!head->next)
	{
		delete head;
		head = nullptr;
		m_desc = nullptr;
		m_asc = nullptr;
		tail = nullptr;
		return;
	}
	node *tmp = tail;
	deleteSort(tmp);
	tail = tail->prev;
	tail->next = nullptr;
	delete tmp;
}

template <typename T>
void FrankenshtainList<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new node(data);
		tail = head;
		m_asc = head;
		m_desc = head;
	}
	else
	{
		node *tmp = new node(data);
		tmp->next = nullptr;
		tmp->prev = tail;
		tail->next = tmp;
		tail = tmp;
		sort(tmp);
	}
}

template <typename T>
void FrankenshtainList<T>::erase()
{
	while (head != nullptr)
	{
		node *tmp = head;
		head = head->next;
		delete tmp;
	}
	m_asc = nullptr;
	m_desc = nullptr;
	tail = nullptr;
}

template <typename T>
void FrankenshtainList<T>::erase(const iterator &it)
{
	if (it.tmp == head)
	{
		pop_front();
		return;
	}

	if (it.tmp == tail)
	{
		pop_back();
		return;
	}

	deleteSort(it.tmp);
	it.tmp->next->prev = it.tmp->prev;
	it.tmp->prev->next = it.tmp->next;
	delete it.tmp;
}

template <typename T>
void FrankenshtainList<T>::erase(int pos)
{
	if (pos < 0 || pos > this->size() - 1)
	{
		throw std::invalid_argument("is invalid_argument");
	}

	node *tmp = head;
	if (pos == 0)
	{
		deleteSort(tmp);
		head = tmp->next;
		tmp->next->prev = head;
		head->prev = nullptr;
		delete tmp;
		return;
	}

	if (pos == this->size() - 1)
	{
		node *res = this->tail;
		deleteSort(res);
		tail = res->prev;
		res->prev->next = tail;
		tail->next = nullptr;
		delete res;
		return;
	}
	int count{};
	while (count < pos)
	{
		tmp = tmp->next;
		++count;
	}
	deleteSort(tmp);
	tmp->next->prev = tmp->prev;
	tmp->prev->next = tmp->next;
	delete tmp;
}

template <typename T>
void FrankenshtainList<T>::insert(const int pos, T data)
{
	if (pos < 0 || pos > this->size() - 1)
	{
		throw std::invalid_argument("is invalid_argument");
	}

	node *tmp = head;
	if (pos == 0)
	{
		this->push_front(data);
		return;
	}

	if (pos == this->size() - 1)
	{
		this->push_back(data);
		return;
	}
	int count{};
	while (count < pos)
	{
		tmp = tmp->next;
		++count;
	}

	node *cur = new node(data);
	tmp->prev->next = cur;
	cur->prev = tmp->prev;
	cur->next = tmp;
	tmp->prev = cur;
	sort(cur);
}

template <typename T>
int FrankenshtainList<T>::size()
{
	node *tmp = this->head;
	int size = 0;
	while (tmp)
	{
		tmp = tmp->next;
		++size;
	}

	return size;
}