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

vector<int> PreOrderIter(Node* root)
{
    if (root == NULL)
        return {};

    vector<int>ans;
    stack<Node*> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        ans.emplace_back(root->data);

        if (root->right)
            st.push(root->right);
        if (root->left)
            st.push(root->left);
    }
    return ans;
}

void Inorder(Node* root)
{
    if (root == NULL)
        return;

    Inorder(root->left);
    cout << root->data << ' ';
    Inorder(root->right);
}

vector<int> InOrder(Node* root)
{
    if (root == NULL)
        return {};

    stack<Node*> st;
    vector<int> ans;
    Node* node = root;

    while (true)
    {
        if (node)
        {
            st.push(node);
            node = node->left;
        }
        else {
            if (st.empty())
                break;

            node = st.top();
            st.pop();
            ans.emplace_back(node->data);
            node = node->right;
        }
    }
    return ans;
}


void PostOrder(Node* root)
{
    if (root == NULL)
        return;

    stack<Node*>st;
    stack<int> st1;
    st.push(root);

    while (!st.empty())
    {
        Node * temp = st.top();
        // cout << temp->data << ' ';
        st1.push(temp->data);
        st.pop();

        if (temp->left)
            st.push(temp->left);

        if (temp->right)
            st.push(temp->right);
    }

    while (!st1.empty())
    {
        cout << st1.top() << ' ';
        st1.pop();
    }
}

void PostOrder2(Node* root)
{
    // Using 1 stack only
    if (root == NULL)
        return;

    stack<Node*>st;
    // st.push(root);
    Node* curr = root;

    while (!st.empty() or curr != NULL)
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else {
            Node* temp = st.top()->right;

            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                cout << temp->data << ' ';

                while (!st.empty() and st.top()->right == temp)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << ' ';
                }
            }
            else {
                curr = temp;
            }

        }
    }

}

void postorder(Node* root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << ' ';
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

    PostOrder2(root);




    return 0;
}