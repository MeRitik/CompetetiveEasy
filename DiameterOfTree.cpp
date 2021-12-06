#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
int diameter = 0;

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

int Height(Node* root)
{
    if (root == NULL)
        return 0;

    int lh = 1 + Height(root->left);
    int rh = 1 + Height(root->right);

    return max(lh, rh);
}

void Diameter(Node* root)
{
    if (root == NULL)
        return;

    int lh = Height(root->left);
    int rh = Height(root->right);

    diameter = max(diameter, lh + rh);
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
    root->right->right->right->right = new Node(112);

    Diameter(root);
    cout << diameter << endl;

    return 0;
}