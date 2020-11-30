#include "LinkedList.h"
#include <stdio.h>
#include <iostream>

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
	_tail = /*new*/DBG_NEW Node(Length, nullptr, nullptr);
	_head = /*new*/DBG_NEW Node(1, nullptr, _tail);
	_tail->prev = _head;
	//Head is last-added by default
	_lastAdded = _head;
		
	Node* listElem = nullptr;
	for (int i = 2; i <= Length-1; ++i)
	{
		listElem = /*new*/DBG_NEW Node(i, _lastAdded, _tail);
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

//Move max elem to the tail
void LinkedList::MoveMaxToTail()
{
	if (!(_head && _tail))
	{
		printf("List head or tail are not valid");
		return;
	}
	Node* max = _head;

	Node* current = _head->next;
	while (current != nullptr)
	{
		if (current->data > max->data)
		{
			max = current;
		}
		current = current->next;
	}

	if (max == _tail)
	{
		return;
	}

	Node* nextAfterMax = max->next;
	Node* previousBeforeMax = max->prev;

	nextAfterMax->prev = previousBeforeMax;
	if (previousBeforeMax)
	{
		previousBeforeMax->next = nextAfterMax;
	}

	_tail->next = max;
	max->prev = _tail;
	max->next = nullptr;

	_tail = max;
}

void LinkedList::DisplayList()
{
	if (!_head)
	{
		return;
	}
	std::cout << "<--prev[" << _head->prev << "] -- _head ([" << _head << "]  " << _head->data << ") -- next[" << _head->next << "]-->" << std::endl;

	Node* nd = _head->next;
	while (nd != _tail)
	{
		std::cout << "<--prev[" << nd->prev << "] -- nd ([" << nd << "]  " << nd->data << ") -- next[" << nd->next << "]-->" << std::endl;
		nd = nd->next;
	}

	if (!_tail)
	{
		return;
	}
	std::cout << "<--prev[" << _tail->prev << "] -- _tail ([" << _tail << "]  " << _tail->data << ") -- next[" << _tail->next << "]-->" << std::endl;
}

void LinkedList::AddNode(int Data)
{
	Node* nd = /*new*/DBG_NEW  Node(Data, _tail, nullptr);
	_tail->next = nd;
	_tail = nd;
}

