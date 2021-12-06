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

bool CheckIfSame(Node* root1, Node* root2)
{
    if (!root1 || !root2)
        return (root1 == root2);

    return (root1->data == root2->data) && CheckIfSame(root1->left, root2->left)
           && CheckIfSame(root1->right, root2->right);
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


    Node* root2 = NULL;
    root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->left = new Node(6);
    root2->right->right = new Node(7);
    root2->left->right->left = new Node(8);
    root2->right->right->left = new Node(9);
    root2->right->right->right = new Node(10);


    bool ans = CheckIfSame(root, root2);

    if (ans)
        cout << "Identical Tree" << endl;
    else
        cout << "Not Identical Tree" << endl;


    return 0;
}