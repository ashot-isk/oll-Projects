#include "FrankenshtainList.h"

template <typename T>
FrankenshtainList<T> foo(FrankenshtainList<T> b)
{
	return b;
}
int main()
{
	FrankenshtainList<int> b;
	b.push_front(6);
	b.push_front(8);
	b.push_front(18);
	b.push_front(3457);
	b.push_front(7);
	b.push_back(15);
	b.push_back(465);
	b.pop_front();
	b.pop_front();
	//b.print();
	cout << endl;
	FrankenshtainList<int>::iterator it;
	FrankenshtainList<int> a{3, 4, 5, 67, 88, 9};
	// a.push_front(3457);
	// a.push_front(7);
	// a.push_back(15);
	// a.push_back(465);
	// a=b;
	it = a.begin();
	a.revers();
	a.print();

	a.erase(it);
	a.print();
}