#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int x) {
		data = x;
		next = NULL;
	}
};

void Print(Node* head)
{
	while (head != NULL) {
		cout << head->data << ' ';
		head = head->next;
	}
	cout << endl;
}

Node* Merge(Node* l1, Node* l2)
{
	if(l1 == NULL)
		return l2;
	if(l2 == NULL)
		return l1;

	if(l1->data > l2->data)
		swap(l1, l2);
	Node* res = l1;
	Node* tmp;

	while(l1 and l2)
	{
		while(l1 and l1->data <= l2->data)
		{
			tmp = l1;
			l1 = l1->next;
		}
		tmp->next = l2;
		swap(l1, l2);
	}

	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("checker.in", "w", stdout);
#endif


	// Constructing List1
	Node* list1 = NULL;
	list1 = new Node(1);
	list1->next = new Node(5);
	list1->next->next = new Node(11);
	list1->next->next->next = new Node(17);


	// Constructing List2
	Node* list2 = NULL;
	list2 = new Node(3);
	list2->next = new Node(7);
	list2->next->next = new Node(12);
	list2->next->next->next = new Node(19);
	list2->next->next->next->next = new Node(34);
	list2->next->next->next->next = new Node(43);

	Print(list1);
	Print(list2);

	Node* MergedList = Merge(list1, list2);
	
	Print(MergedList);

	return 0;
}