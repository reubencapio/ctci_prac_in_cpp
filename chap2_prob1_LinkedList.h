struct Node
{
	int data;
	Node* next;
};

class LinkedList
{
public:
	Node* head;
	LinkedList();
	~LinkedList();
	void display();
	void insert(int value);
private:
	Node* tail;
};
