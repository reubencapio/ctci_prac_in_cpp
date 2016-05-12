#include "LinkedList.h"
#include <iostream>

int lengthList(Node* head);
void padlist(Node* list, int pad);

void addList(Node* first, Node* second)
{
	if (first == nullptr || second == nullptr) {
		return;
	}

	int carry = 0;
	int val = 0;
	Node* list1 = first;
	Node* list2 = second;
	int length1 = lengthList(list1);
	int length2 = lengthList(list2);
	if (length1 > length2) {
		padlist(list2, length1 - length2);
	}

	if (length2 > length1) {
		padlist(list1, length2 - length1);
	}


	while (list1 || second) {

		list1->data += carry;
		val = list1->data + list2->data;
		if (val > 10) {
			carry = 1;
			val = val - 10;
		}
		else {
			carry = 0;
		}
		list1->data = val;
		list1 = list1->next;
		list2 = list2->next;
	}
	// if the final digit had a carry we need to add one to the end
	if (carry)
	{
		// reset the head and find the last element
		first = list1;
		while (list1->next)
		{
			list1 = list1->next;
		}

		list1->next = new Node();
		list1->next->data = 1;
		list1->next->next = nullptr;
	}
}

int lengthList(Node* head)
{
	int count = 0;
	Node* current = head;
	while (current->next != nullptr) {
		count++;
		current = current->next;
	}
	return count;
}

void padlist(Node* list, int pad)
{
	if (nullptr == list) {
		return;
	}

	int ctr = 0;
	Node* temp = list;
	while (temp->next != nullptr) {
		temp = temp->next;
	}

	while (ctr != pad) {
		temp->next = new Node();
		temp = temp->next;
		temp->data = 0;
		temp->next = nullptr;
		ctr++;
	}
}

int main()
{
	LinkedList* first = new LinkedList();
	first->insert(3);
	first->insert(2);
	first->insert(1);
	LinkedList* second = new LinkedList();
	second->insert(6);
	second->insert(5);
	second->insert(4);
	addList(first->head, second->head);
	first->display();
}
