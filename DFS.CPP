#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;

	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void InOrder(Node* root)
{
	if (root == NULL)
		return;
	InOrder(root->left);
	cout << root->data << " ";
	InOrder(root->right);
}


void PreOrder(Node* root)
{
	if (root == NULL)
		return;
	cout << root->data << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}


void PostOrder(Node* root)
{
	if (root == NULL)
		return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->data << " ";
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("checker.in", "w", stdout);
#endif

	Node* root = NULL;
	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->left->right->left = new Node(8);
	root->right->right->left = new Node(9);
	root->right->right->right = new Node(10);

	InOrder(root);

	PreOrder(root);
	cout << endl;
	PostOrder(root);


	return 0;
}