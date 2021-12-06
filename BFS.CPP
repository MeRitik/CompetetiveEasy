#include <iostream>
#include <queue>
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

void BreadthFirst(Node* root)
{
	if (root == NULL)
		return;

	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		Node* curr = q.front();
		cout << curr->data << ' ';
		q.pop();

		if (curr->left)
			q.push(curr->left);
		if (curr->right)
			q.push(curr->right);
	}
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

	BreadthFirst(root);


	return 0;
}