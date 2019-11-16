/*
Online operations 
for a stack
Assume stack contains positive
integers only. 
Operation index:
1 -> insert
2 -> delete
3 -> showfront
0 -> End program
*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* nxt;
} *front, *rear;

void Insert(int indata)
{
	node * temp  = new node;
	temp -> data = indata;
	temp -> nxt = NULL;

	if (rear == NULL)
	{
		rear = temp;
		front = temp;
		return;
	}

	rear->nxt = temp;
	rear = rear->nxt;
}

void Delete()
{
	if (front == NULL)
	{
		cout << "Nothing to delete\n";
		return;
	}
	else if (front == rear)
	{
		delete front;
		front = NULL; 
		rear = NULL;
		return;
	}

	node * temp = front;
	front = front->nxt;
	temp->nxt = NULL;
	delete temp;
}

int showfront()
{
	if (front == NULL)	
		return -1;

	return front->data;
}

int main()
{
	front = NULL;
	rear = NULL;

	int task;

	do 
	{
		cin >> task;

		if (task==1) {
			int x; cin >> x;
			Insert(x);
		}
		else if (task==2) {
			Delete();
		}
		else if (task==3) {
			cout << showfront() << "\n";
		}

	}	while (task);

	while (front != NULL)
		Delete();

	return 0;
}