#include <iostream>
#include <unordered_set>
#include "LinkedList.h"

//not done!! please finish


void arrangeList(Node *head, int mid)
{
	if (nullptr == head || nullptr == head->next) {
		return;
	}

	Node *headrunner = head;;
	Node *lowerrunner = nullptr;
	Node *lowerstart = nullptr;
	Node *higherrunner = nullptr;
	Node *higherstart = nullptr;

	while (nullptr != headrunner) {
		Node *next = head->next;
		head->next = nullptr;
		if (headrunner->data >= mid) {
			if (nullptr == higherstart) {
				higherstart = head;
				higherrunner = higherstart;
			} else{
				higherrunner->next = head->next;
				higherrunner = head;
			}

		} else {
			lowerrunner = headrunner;
			if (nullptr == lowerstart) {
				lowerstart = headrunner;
			}
			headrunner = headrunner->next;
			lowerrunner = lowerrunner->next;
		}
	}
	higherrunner->next = lowerrunner;
	head = higherrunner;
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
	arrangeList(a_list->head, 5);
	a_list->display();
}
