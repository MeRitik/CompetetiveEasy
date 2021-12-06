#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
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

vector<vector<int>> ZigZag(Node* root)
{
    if (!root)
        return {};

    vector<vector<int>> res;
    queue<Node*>q;
    q.push(root);
    bool flag = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int>v(size);

        for (int i = 0; i < size; i++)
        {
            Node* tmp = q.front();
            q.pop();

            // Find position to insert the data
            int index = (flag) ? i : (size - 1 - i);
            v[index] = tmp->data;

            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }

        // Flip the flag each time
        res.push_back(v);
        flag = !flag;
    }
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


    vector<vector<int>> ans = ZigZag(root);
    for (auto it : ans) {
        for (auto itr : it)
            cout << itr << ' ';
        cout << endl;
    }


    return 0;
}