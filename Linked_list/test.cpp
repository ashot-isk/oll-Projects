
#include "list.h"

int main()
{
	// list<int> ls;
	// ls.push_front(2);
	// ls.push_front(4);
	// ls.push_front(2);
	// ls.push_front(3);
	// ls.push_front(2);
	// ls.push_front(2);
	// ls.insert(1, 10);
	//ls.remove(2);
	//ls.remove(4);

	// ls.pop_front();
	list<int> lsq{1, 2, 3, 4};

	

	for (int i = 0; i < lsq.get_size(); ++i)
	{
		std::cout << "index " << i << "=" << lsq[i] << std::endl;
	}
}