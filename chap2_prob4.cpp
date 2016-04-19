#include <iostream>
#include <unordered_set>
#include "LinkedList.h"


Node* arrangeList(Node *node, int mid)
{
	if (nullptr == node || nullptr == node->next) {
		return nullptr;
	}

	Node * beforeStart = nullptr;;
	Node *beforeEnd = nullptr;
	Node *afterStart = nullptr;
	Node *afterEnd = nullptr;


	while (nullptr != node) {
		Node *next = node->next;
		node->next = nullptr;
		if (node->data < mid) {
			if (nullptr == beforeStart) {
				beforeStart = node;
				beforeEnd = beforeStart;
			} else{
				beforeEnd->next = node;
				beforeEnd = node;
			}

		} else {
			if (nullptr == afterStart) {
				afterStart = node;
				afterEnd = afterStart;
			} else {
				afterEnd->next = node;
				afterEnd = node;
			}
		}
		node = next;
	}
	if (nullptr == beforeStart) {
		return afterStart;
	}
	beforeEnd->next = afterStart;
	return beforeStart;
}


Node* partition(Node* head, int val)
{
	if (head == NULL)
	{
		return nullptr;
	}

	LinkedList* upper = new LinkedList();
	LinkedList* lower = new LinkedList();
	Node* current = head;

	while (current)
	{
		if (current->data < val)
		{
			lower->insert(current->data);
		}
		else
		{
			upper->insert(current->data);
		}

		current = current->next;
	}

	// reset current back to the head
	current = lower->head;
	Node* lowNode = lower->head;

	// find the end of the lower list
	while (lowNode->next)
	{
		lowNode = lowNode->next;
	}
	lowNode->next = upper->head;

	return current;
}

int main()
{
	LinkedList *a_list = new LinkedList();
	a_list->insert(7);
	a_list->insert(2);
	a_list->insert(5);
	a_list->insert(8);
	a_list->insert(3);
	a_list->display();
	LinkedList *a_list2 = new LinkedList();
	a_list2->head = arrangeList(a_list->head, 5);
	a_list2->display();
	delete a_list2;
	return 0;
}
