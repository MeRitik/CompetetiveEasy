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

bool isLeaf(Node* root)
{
    if (!root->left and !root->right)
        return true;
    return false;
}

void addLeftBoundry(Node* root, vector<int> &res)
{
    while (root)
    {
        if (!isLeaf(root))
            res.emplace_back(root->data);
        if (root->left)root = root->left;
        else root = root->right;
    }
}

void addRightBoundry(Node* root, vector<int> &res)
{
    stack<int>st;
    while (root)
    {
        if (!isLeaf(root))
            st.push(root->data);
        if (root->right)
            root = root->right;
        else
            root = root->left;
    }

    while (!st.empty())
    {
        res.emplace_back(st.top());
        st.pop();
    }
}

void addLeafs(Node* root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.emplace_back(root->data);
        return;
    }

    if (root->left)
        addLeafs(root->left, res);
    if (root->right)
        addLeafs(root->right, res);
}

vector<int> BoundryTraversal(Node* root)
{
    if (!root)
        return {};

    vector<int> res;
    if (!isLeaf(root))
        res.emplace_back(root->data);

    addLeftBoundry(root->left, res);
    addLeafs(root, res);
    addRightBoundry(root->right, res);

    return res;
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

    vector<int> res = BoundryTraversal(root);
    for (auto it : res)
        cout << it << ' ';


    return 0;
}