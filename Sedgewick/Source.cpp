#include <iostream>
#include "LinkedList.h"

int main()
{
	{
		LinkedList list(2);
		list.AddNode(9);
		list.AddNode(3);
		list.AddNode(7);

		list.DisplayList();
		std::cout << "\n";

		list.MoveMaxToTail();

		list.DisplayList();
	}
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}

