#pragma once



class LinkedList
{
using ListItem = int;

public:
	LinkedList(int Length);
	~LinkedList();

private:
	struct Node
	{
		ListItem data;
		Node* next;

		Node(int X, Node* Next)
		{
			data = X;
			next = Next;
		}
	};


	const int MIN_COUNT_NODES = 2;

private:
	Node* _head = nullptr;
	Node* _tail = nullptr;

	Node* _lastAdded = nullptr;
};
