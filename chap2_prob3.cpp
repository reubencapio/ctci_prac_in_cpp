#include <iostream>
#include <unordered_set>
#include "LinkedList.h"


void deleteNode(Node *head)
{
	if (nullptr == head || nullptr == head->next){
		return;
	}

	Node *nd = head->next;
	head->next = nd->next;
	head->data = nd->data;
	delete nd;

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
	Node *test = a_list->head->next->next;
	deleteNode(test);
	a_list->display();
}
