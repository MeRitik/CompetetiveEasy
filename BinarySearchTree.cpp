// C++ program to demonstrate insertion
// in a BST recursively.
#include <iostream>
using namespace std;

class BST
{
    int data;
    BST *left, *right;

public:
    // Default constructor.
    BST();

    int freq;


    BST(int);

    BST* Insert(BST*, int);

    void Inorder(BST*);



    BST* search( BST* root, int key)
    {
        if (root == NULL || root->data == key)
            return root;

        if (root->data < key)
            return search(root->right, key);

        return search(root->left, key);
    }
};

BST ::BST(): data(0), left(NULL), right(NULL), freq(1) {}

// Parameterized Constructor definition.
BST ::BST(int value)
{
    data = value;
    left = right = NULL;
    freq = 1;
}

BST* BST ::Insert(BST* root, int value)
{
    if (!root)
    {
        return new BST(value);
    }

    if (value > root->data)
    {
        root->right = Insert(root->right, value);
    }
    else
    {
        root->left = Insert(root->left, value);
    }
    return root;
}


// Inorder traversal function.
// This gives data in sorted order.
void BST ::Inorder(BST* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data << "  " << root->freq << endl;
    Inorder(root->right);
}

// Driver code
int main()
{

#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
#endif
    BST b, *root = NULL;
    root = b.Insert(root, 0);

    int arr[12] = {1, 2, 3, 4, 3, 1, 3, 1, 3, 1, 5, 4};
    int n = 12;
    for (auto it : arr)
    {
        if (b.search(root, it) == NULL) {
            b.Insert(root, it);
        }
        else {
            BST* temp = b.search(root, it);
            temp->freq++;
        }
    }

    b.Inorder(root);
    return 0;
}
