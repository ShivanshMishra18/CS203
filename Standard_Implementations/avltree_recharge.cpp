#include <bits/stdc++.h>
using namespace std;

int maxpair[2];

struct node
{
    int key, amount;
    node * left; 
    node * right;
    int height;
};

node *newnode(int k, int amt)
{
    node *p = new(node);
    p->height=1;
    
    p->amount=amt;
    p->key=k;

    p->left=NULL;
    p->right=NULL;

    if (maxpair[0]<amt) {
        maxpair[0]=amt;
        maxpair[1]=k;
    }

    return p;
}

int getH(node *ptr)
{
    if (ptr == NULL)
        return 0;

    return ptr->height;
}

node *lRot(node *x)
{
    node *y = x->right;
    node *p = y->left;

    x->right = p;
    y->left = x;

    x->height = max(getH(x->right), getH(x->left)) + 1;
    y->height = max(getH(y->right), getH(y->left)) + 1;

    return y;
}

node *rRot(node *x)
{
    node *y = x->left;
    node *p = y->right;

    x->left = p;
    y->right = x;

    x->height = max(getH(x->right), getH(x->left)) + 1;
    y->height = max(getH(y->right), getH(y->left)) + 1;

    return y;
}

int Balance(node *ptr)
{
    if (ptr == NULL) 
        return 0;

    return (getH(ptr->left) - getH(ptr->right));
}

node *insert(node *root, int k, int amt)
{
    if (root == NULL)   return newnode(k, amt);

    if (k < root->key)      root->left = insert(root->left, k, amt);
    else if (k > root->key)  root->right = insert(root->right, k, amt);
    else
    {
        root->amount = root->amount + amt;
        if (root->amount > maxpair[0])
        {
            maxpair[0] = root->amount;
            maxpair[1] = k;
        }
    }
    
    root->height = 1 + max(getH(root->left),getH(root->right));
    int bal = Balance(root);

    if (bal > 1)
    {
        if (k < root->left->key) {
            return rRot(root);
        }
        else {
            root->left = lRot(root->left);
            return rRot(root);
        }
    }
    else if (bal < -1)
    {
        if (k > root->right->key) {
            return lRot(root);
        }
        else {
            root->right = rRot(root->right);
            return lRot(root);
        }
    }
    return root;
}

node *minele(node *root)
{
    node *p = root;
    while (p->left != NULL)
        p = p->left;
    return p;
}

node *del(node *root, int k)
{
    if (root == NULL)   return root;

    if (root->key > k)  root->left = del(root->left, k);
    else if (root->key < k)  root->right = del(root->right, k);
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete(root);
            return temp;
        }
        else
        {
            node *p = minele(root->right);
            root->key = p->key;
            root->right = del(root->right, p->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = max(getH(root->left), getH(root->right)) + 1;
    int bal = Balance(root);

    if (bal > 1)
    {
        if (k < root->left->key) {
            return rRot(root);
        }
        else {
            root->left = lRot(root->left);
            return rRot(root);
        }
    }

    else if (bal < -1)
    {
        if (k > root->right->key) {
            return lRot(root);
        }
        else {
            root->right = rRot(root->right);
            return lRot(root);
        }
    }
    return root;     
}

void destrTree(node *root)
{
    if (root->left != NULL) destrTree(root->left);
    if (root->right != NULL) destrTree(root->right);
    delete(root);
    root = NULL;
}

int main()
{
    int queries;
    int type;
    int k, amt;
    node *root = NULL;

    cin>>queries;
    while (queries--)
    {
        cin>>type;

        if (type==1)
        {
            cin>>k>>amt;
            root = insert(root, k, amt);
        }
        else if (type == 2)
        {
            if (maxpair[0]>0) {
                cout<<maxpair[1]<<"\n";
            }
            else {
                cout<<"NO DATA\n";
            }
        }
        else
        {
            cin>>k;
            root = del(root, k);
        }
    }

    destrTree(root);
    return 0;
}
