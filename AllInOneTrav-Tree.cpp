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

void AllInOneTraversal(Node* root, vector<int> &Pre, vector<int> &In, vector<int> &Post)
{
    if (!root)return;

    stack<pair<Node*, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            // TODO
            Pre.emplace_back(it.first->data);
            it.second = 2;
            st.push(it);

            if (it.first->left)
                st.push({it.first->left, 1});
        }
        else if (it.second == 2)
        {
            // TODO
            In.emplace_back(it.first->data);
            it.second = 3;
            st.push(it);

            if (it.first->right)
                st.push({it.first->right, 1});
        }
        else {
            Post.emplace_back(it.first->data);
        }
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
    root->left->right = new Node(23);
    root->right = new Node(8);
    root->right->left = new Node(34);
    root->left->left = new Node(3);
    root->left->left->left = new Node(4);
    root->left->left->right = new Node(5);
    root->right->right = new Node(7);
    root->right->right->left = new Node(71);
    root->right->right->right = new Node(6);

    vector<int>Pre, In, Post;
    AllInOneTraversal(root, Pre, In, Post);
    for (auto it : Pre)
        cout << it << ' ';
    cout << endl;

    for (auto it : In)
        cout << it << ' ';
    cout << endl;

    for (auto it : Post)
        cout << it << ' ';



    return 0;
}