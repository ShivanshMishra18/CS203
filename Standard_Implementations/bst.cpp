#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
};

node *newnode(int dat)
{
    node * p = new node;
    p->data = dat;
    p->left = NULL;
    p->right = NULL;

    return p;
}

node * getmin(node *root)
{
    node * temp = root;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

node * insert(int dat, node *root)
{
    if (root==NULL)
    {
        root = newnode(dat);
        return root;   
    }

    if (root->data < dat)
    {
        root->right = insert(dat, root->right); 
    }
    else
    {
        root->left = insert(dat, root->left);
    }
    return root;
}

node * Delete(int dat, node *root)
{
    if (root == NULL) 
    {
        cout << "Not found\n" ;
        return root; 
    }

    if (root->data == dat)
    {
        if (root->right == NULL && root->left == NULL)
        {
            node * temp = root; delete temp;
            root = NULL;
        }
        else if (root->right == NULL)
        {
            node * temp = root;
            root = root->left;
            temp->left = NULL;
            delete temp;
        }
        else if (root->left == NULL)
        {
            node * temp = root;
            root = root->right;
            temp->right = NULL;
            delete temp;
        }
        else 
        {
            node *temp = getmin(root->right);
            root->data = temp->data;
            root->right = Delete(temp->data, root->right); 
        }
        return root;
    }
    else if (root->data < dat)
    {
        root->right = Delete(dat, root->right);
        return root;
    }
    else
    {
        root->left = Delete(dat, root->left);
        return root;
    }
}

void destrTree(node **root)
{
    if ((*root)->left != NULL) destrTree(&((*root)->left));
    if ((*root)->right != NULL) destrTree(&((*root)->right));
    delete *root;
    *root = NULL;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    // else
    //     cout << "empty tree\n";
}

int main() 
{ 
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    node *root = NULL; 
    root = insert(50, root); 
    root = insert(30, root); 
    root = insert(20, root); 
    root = insert(40, root); 
    root = insert(70, root); 
    root = insert(60, root); 
    root = insert(80, root); 
  
    printf("Inorder traversal of the given tree \n"); 
    inorder(root); 
  
    printf("\nDelete 20\n"); 
    root = Delete(20, root); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 30\n"); 
    root = Delete(30, root); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 50\n"); 
    root = Delete(50, root); 
    // for (int i=0; i<=10; i++)
    //     root = Delete(10*i, root);
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root);

    if (root)
        destrTree(&root); 
    if (root == NULL) cout << "done";
  
    return 0; 
} 
