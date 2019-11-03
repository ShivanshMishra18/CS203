/*
PROBLEM STATEMENT
Perform merge sort using linked list

input - number of elements in sequence
        sequence of integers
*/


#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* nxt;
};

// Insert a node in the front of the list
void insert(int indata, node ** head)
{
    node *temp = new node;
    temp->data = indata;
    temp->nxt = *head;
    *head = temp;
}

// Merging utility for sorted sublists
node * merge_util(node *h1, node *h2)
{
    node *h3, *last;

    if (h1->data < h2->data) 
    {
        h3 = h1;
        h1 = h1->nxt;
        h3->nxt = NULL;
    }
    else
    {
        h3 = h2;
        h2 = h2->nxt;
        h3->nxt = NULL;
    }
    last = h3;

    while (h1!=NULL && h2!=NULL)
    {
        if (h1->data < h2->data)
        {
            last->nxt = h1;
            h1 = h1->nxt;
            last = last->nxt;
            last->nxt = NULL;
        }
        else
        {
            last->nxt = h2;
            h2 = h2->nxt;
            last = last->nxt;
            last->nxt = NULL;
        }
    }

    if (h1 != NULL)
        last->nxt = h1;
    else if (h2 != NULL)
        last->nxt = h2;
        
    return h3;
}

// Recursive merge sort function
void mergesort(node **ptr, int sz)
{
    if (sz==1)  return;

    int sz1 = sz/2;
    
    node *h1 = *ptr;
    node *h2 = *ptr;

    for (int i=0; i<sz1-1; i++)
        h2 = h2->nxt;

    node *temp = h2;
    h2 = h2->nxt;
    temp->nxt = NULL;
    temp = NULL;

    mergesort(&h1,sz1);
    mergesort(&h2,sz-sz1);
    *ptr = merge_util(h1,h2);
}

void showlist(node * head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->nxt;
    }
    cout << "\n";
}

void removelist(node **ptr)
{
    if (*ptr == NULL)    return;

    removelist(&((*ptr)->nxt));
    (*ptr)->nxt = NULL;
    // cout << (*ptr)->data << " ";
    delete *ptr;
    // cout << (*ptr)->data << " ";
}

int main()
{
    
    node *head = NULL;
    
    int n;
    cin >> n;

    for (int i=0; i<n; i++)
    {
        int newdata;
        cin >> newdata;
        insert(newdata, &head);
    }

    mergesort(&head, n);
    showlist(head);
    removelist(&head);
    head = NULL;

    return 0;
}
