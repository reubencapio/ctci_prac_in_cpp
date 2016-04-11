#include <iostream>
#include <unordered_set>
#include "LinkedList.h"


void getKtoLastInefficient(Node *head, int k)
{
	if (nullptr == head) return;
	Node *temp = head;
	Node *piter = head;
	int listctr = 0;
	while (temp != nullptr) {
		listctr++;
		temp = temp->next;
	}
	if (k > listctr) {
		return;
	}
	int stop = listctr - k;
	int iter = 0;
	while (iter != stop ) {
		piter = piter->next;
		iter++;
	}
	std::cout << "the k element is = " << piter->data << "\n";

}


void getKtoLast2Efficient(Node *head, int k)
{
	Node *p1 = head;
	Node *p2 = head;

	for (int i = 0; i < k - 1; i++) {
		if (nullptr == p2) return;
		p2 = p2->next;
	}

	if (nullptr == p2) return;

	while (nullptr != p2->next) {
		p1 = p1->next;
		p2 = p2->next;
	}

	std::cout << "efficient kth element: " << p2->data << "\n";
}

Node *getKtoLastRecurse(Node *head, int k, int& i) {
	if (head == NULL) {
		return NULL;
	}
	Node *nd = getKtoLastRecurse(head->next, k, i);
	i = i + 1;
	if (i == k) {
		return head;
	}
	return nd;
}

int main()
{
	LinkedList *a_list = new LinkedList();
	a_list->insert(1);
	a_list->insert(2);
	a_list->insert(3);
	a_list->insert(4);
	a_list->insert(5);
	a_list->display();
	getKtoLastInefficient(a_list->head, 2);
	getKtoLast2Efficient(a_list->head, 2);
	int ctr = 0;
	Node *test = getKtoLastRecurse(a_list->head, 2, ctr);
	std::cout << "recursive kth element: " << test->data << "\n";
	a_list->display();
}
