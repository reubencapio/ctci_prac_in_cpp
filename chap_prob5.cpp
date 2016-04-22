#include "LinkedList.h"
#include <iostream>

Node* addList(Node* first, Node* second)
{
	if (first == nullptr || second == nullptr) {
		return nullptr;
	}
	LinkedList* result = new LinkedList();
	while (first->next != nullptr && second->next != nullptr) {

		int sum = first->data + second->data;
		if (sum >= 10) {
			sum = sum % 10;
			result->insert(sum);
			sum = sum / 10;
		}else{
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
	while (current->next !=nullptr) {
		count++;
		current = current->next;
	}
	return count;
}

void padlist(Node* list, int pad)
{




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
