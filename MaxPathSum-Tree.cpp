#include <iostream>
#include <queue>
#include <stack>
#include <vector>
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

int maxPathSum(Node* root, int& maxm)
{
    if (root == NULL)
        return 0;

    int maxLeft = max(0, maxPathSum(root->left, maxm));
    int maxRight = max(0, maxPathSum(root->right, maxm));

    maxm = max(maxm, maxLeft + maxRight + root->data);

    return root->data + max(maxLeft, maxRight);
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
    root->left->right = new Node(23);
    root->right = new Node(8);
    root->right->left = new Node(34);
    root->left->left = new Node(3);
    root->left->left->left = new Node(4);
    root->left->left->right = new Node(5);
    root->right->right = new Node(7);
    root->right->right->left = new Node(71);
    root->right->right->right = new Node(6);

    int res = 0;
    maxPathSum(root, res);
    cout << res;


    return 0;
}