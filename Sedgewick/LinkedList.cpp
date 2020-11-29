#include "LinkedList.h"
#include <stdio.h>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

LinkedList::LinkedList(int Length)
{
	if (Length < MIN_COUNT_NODES)
	{
		printf("List has %d number of items", Length);
		return;
	}

	//Initial list construct
	_tail = /*new*/DBG_NEW Node(Length, nullptr);
	_head = /*new*/DBG_NEW Node(1, _tail);
	//Head is last-added by default
	_lastAdded = _head;
		
	Node* listElem = nullptr;
	for (int i = 2; i <= Length-1; ++i)
	{
		listElem = /*new*/DBG_NEW Node(i, _tail);
		_lastAdded->next = listElem;
		_lastAdded = listElem;
	}

}

LinkedList::~LinkedList()
{
	if (_head != nullptr)
	{
		Node* nodeToDelete = _head;
		Node* nextNode = _head->next;

		while (nodeToDelete)
		{
			delete nodeToDelete;

			nodeToDelete = nextNode;
			if (nodeToDelete)
			{
				nextNode = nodeToDelete->next;
			}
		}
	}
}

