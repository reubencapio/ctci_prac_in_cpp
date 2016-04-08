#include <iostream>
#include <vector>
#include <map>
#include "LinkedList.h"

void removeDuplicates(LinkedList *a_list)
{

}


int main()
{
	LinkedList *a_list = new LinkedList();
	a_list->insert(1);
	a_list->insert(3);
	a_list->insert(3);
	a_list->insert(5);
	a_list->display();
	removeDuplicates(a_list);
}
