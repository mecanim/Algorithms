#pragma once



class LinkedList
{
using ListItem = int;

public:
	LinkedList(int Length);
	~LinkedList();

public:
	void MoveMaxToTail();
	void DisplayList();
	void AddNode(int Data);
private:
	struct Node
	{
		ListItem data;
		Node* next;
		Node* prev;

		Node(int X, Node* Prev, Node* Next)
		{
			data = X;
			prev = Prev;
			next = Next;
		}
	};

	const int MIN_COUNT_NODES = 2;

private:
	Node* _head = nullptr;
	Node* _tail = nullptr;

	Node* _lastAdded = nullptr;
};
