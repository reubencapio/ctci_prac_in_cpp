#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

struct node {

	node::node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}

	int data;
	node* left;
	node* right;
};


void postorder(node* p, int indent)
{
	if (p != NULL) {
		if (p->right) {
			postorder(p->right, indent + 4);
		}
		if (indent) {
			cout << setw(indent) << ' ';
		}
		if (p->right) cout << " /\n" << setw(indent) << ' ';
		cout << p->data << "\n ";
		if (p->left) {
			cout << setw(indent) << ' ' << " \\\n";
			postorder(p->left, indent + 4);
		}
	}
}


//recursive solution
node* createMinimalBST(std::vector<int> &input, int min, int max)
{
	//create stop condition
	if (min> max) {
		return NULL;
	}

	int mid = (max + min) / 2;
	node *n = new node(input[mid]);
	n->left =  createMinimalBST(input, min, mid-1);
	n->right = createMinimalBST(input, mid + 1, max);
	return n;
}

int main()
{
	std::vector<int> input = { 1,2,3,4,5,6,7,8,9 };
	node *root = createMinimalBST(input, 0, input.size() - 1);
	postorder(root, 0);
}