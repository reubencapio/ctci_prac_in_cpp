#include <iostream>
#include "LinkedList.h"

// runs in O(n) time with O(1) space
Node* findCycleBegin(Node* head)
{
	if(head == nullptr) {
		return nullptr;
	}

	Node* slow = head;
	Node* fast = head;

	while (fast != nullptr || fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			break;
		}
	}

	if (fast == nullptr || fast->next == nullptr) {
		return nullptr;
	}

	slow = head;

	while (fast != slow) {
		fast = fast->next;
		slow = slow->next;
	}

	return slow;
}



int main()
{
	LinkedList* list1 = new LinkedList();
	list1->insert(5);
	list1->insert(3);
	list1->insert(6);
	list1->insert(8);
	list1->insert(1);
	list1->insert(2);

	std::cout << "For the list: ";
	list1->display();
	std::cout << "A cycle begins at value: ";

	// create a cycle in the list
	list1->createCycle();

	Node* beginCycle = findCycleBegin(list1->head);
	std::cout << beginCycle->data << std::endl;

	return 0;
}
