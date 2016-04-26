#include "LinkedList.h"
#include <iostream>

void addList(Node* first, Node* second)
{
	if (first == nullptr || second == nullptr) {
		return;
	}

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


	while (first->next != nullptr && second->next != nullptr) {

		int sum = first->data + second->data;
		if (sum >= 10) {
			sum = sum % 10;
			result->insert(sum);
			sum = sum / 10;
		}
		else {
			result->insert(sum);
		}
		first = first->next;
		second = second->next;
	}
	return result->head;
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

	while(ctr != pad) {
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
	LinkedList* sum = new LinkedList();
	sum->head = addList(first->head, second->head);
	sum->display();
}
