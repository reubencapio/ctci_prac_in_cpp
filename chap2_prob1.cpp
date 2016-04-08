#include <iostream>
#include <unordered_set>
#include "LinkedList.h"


void removeDuplicates(Node *head)
{
	std::unordered_set<int> unique;
	Node *current = head;
	unique.insert(current->data);

	while(current->next != nullptr)
	{
		if(unique.find(current->next->data) == unique.end()){
			unique.insert(current->next->data);
			current = current->next;
		} 
		else
		{
			Node* temp = current->next;
			current->next = current->next->next;
			delete temp;
		}
	}
}


int main()
{
	LinkedList *a_list = new LinkedList();
	a_list->insert(1);
	a_list->insert(3);
	a_list->insert(3);
	a_list->insert(5);
	a_list->display();
	removeDuplicates(a_list->head);
	a_list->display();
}
