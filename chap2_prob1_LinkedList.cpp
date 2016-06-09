#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList()
{
	this->head = nullptr;
}

LinkedList::~LinkedList()
{
	Node *current = head;
	while(current != nullptr)
	{
		Node *next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
}

void LinkedList::createCycle()
{
    tail->next = head->next;  
}

void LinkedList::insert(int value)
{
	if(head == nullptr)
	{
		head = new Node();
		head->data = value;
		head->next = nullptr;
		tail = head;
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
	if(head == nullptr)
	{
		return;
	}

	Node *temp = head;

	while(temp != nullptr)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}

	std::cout << "\n";
}
