#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList()
{
	this->head = nullptr;
}

LinkedList::~LinkedList()
{
	Node* current = head;

	while (current != 0)
	{
		Node* next = current->next;
		delete current;
		current = next;
	}

	head = nullptr;
}

void LinkedList::insert(int value)
{
	if (head == nullptr)
	{
		head = new Node();
		tail = head;
		head->next = nullptr;
		head->data = value;
	}
	else
	{
		tail->next = new Node();
		tail = tail->next;
		tail->data = value;
		tail->next = nullptr;
	}
}

void LinkedList::display()
{
	Node* temp;

	if (head == nullptr)
	{
		return;
	}

	temp = head;

	while (temp != nullptr)
	{
		std::cout << temp->data << ' ';
		temp = temp->next;
	}

	std::cout << std::endl;
}
