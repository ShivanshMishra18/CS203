/*
Online operations 
for a stack
Assume stack contains positive
integers only. 
Operation index:
1 -> push
2 -> pop
3 -> top
0 -> End program
*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* nxt;
};

void push(int indata, node **head)
{
	node * ptr = new node;
	ptr->nxt = (*head == NULL) ? NULL : *head;
	ptr->data = indata;
	*head = ptr;
}

void pop(node **head)
{
	if (*head == NULL)	{
		cout << "Nothing to pop\n";
		return;
	}

	node * temp = (*head);
	*head = (((*head)->nxt)==NULL) ? NULL : temp->nxt;
	temp->nxt = NULL;
	delete temp;
}

int top(node **head)
{
	if (*head == NULL)
		return -1;

	return (*head)->data;
}

int size(node **head)
{
	node *temp = *head;
	int ctr = 0;

	while (temp!=NULL) {
		ctr++;
		temp = temp->nxt;
	}
	return ctr;
}

int main()
{
	int todo;
	node *head = NULL;

	do 
	{
		cin >> todo;
		if (todo == 1) {
			int a;
			cin >> a;
			push(a, &head);
			cout << size(&head);
		}
		else if (todo == 2)
			pop(&head);
		else if (todo == 3)
			cout << top(&head) << "\n";
	}
	while (todo);

	int sz = size(&head);
	while(sz--)
		pop(&head);

	if (head != NULL)	pop(&head);

	return 0;
}