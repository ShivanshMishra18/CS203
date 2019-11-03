/*
Problem Statement
Output sorted sequence using treap.
Then delete a node with given key
and again output the sorted sequence.
*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key, order;
    node *left, *right;
};

// Left Rotation
node * RRot(node * y)
{
    node *x = y->left;
    y->left = x->right;
    x->right = y;
    return x;
}

// Right Rotation
node * LRot(node * x)
{
    node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Creates new node
node * newnode(int data)
{
    node * ptr = new node;
    ptr->key = data;
    ptr->order = rand() % 1000;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

node * Insert(node * root, int data)
{
    if (root == NULL) {
        root = newnode(data);
        return root;
    }

    if (data > root->key)
    {
        root->right = Insert (root->right, data);
        if (root->right->order > root->order)
            root = LRot(root);
    }

    else
    {
        root->left = Insert (root->left, data);
        if (root->left->order > root->order)
            root = RRot(root);
    }
    
    return root;
}

void Inorder(node * root)
{
    if (root==NULL) return;

    Inorder(root->left);
    cout << root->key << " ";
    Inorder(root->right);
}

node * Delete(node * root, int data)
{
    if (root==NULL) return root;

    if (data > root->key)
        root->right = Delete (root->right, data);

    else if (data < root->key)
        root->left = Delete (root->left, data);

    else if (root->left == NULL) {
        node * temp = root;
        root = root->right;
        temp->right = NULL;
        delete temp;
    }

    else if (root->right == NULL) {
        node * temp = root;
        root = root->left;
        temp->left = NULL;
        delete temp;
    }

    else if (root->left->order < root->right->order)
    {
        root = LRot(root);
        root->left = Delete (root->left, data);
    }

    else
    {
        root = RRot(root);
        root->right = Delete (root->right, data);
    }
    
    return root; 
}

void Destroy(node * root)
{
    if (root == NULL)   return;

    Destroy(root->right);
    Destroy(root->left);
    delete root;
}

int main()
{
    int n;
    cin >> n;

    node *root = NULL;

    for (int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        root = Insert(root, a);
    }

    Inorder(root);
    cout << "\n";

    int del;
    cin >> del;

    root = Delete(root, del);
    Inorder(root);
    Destroy(root);

    return 0;
}