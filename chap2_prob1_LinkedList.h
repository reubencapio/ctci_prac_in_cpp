struct Node
{
	int data;
	Node* next;
};

class LinkedList
{
public:
	Node* tail;
	Node* head;
	LinkedList();
	~LinkedList();
	void display();
	void insert(int value);

};
