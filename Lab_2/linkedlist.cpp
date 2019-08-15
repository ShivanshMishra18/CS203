#include <iostream>
#include <math.h>
using namespace std;

struct node 
{
	int x, y;
	node* next;	
}	*head;

void AddFirst(int x, int y)
{
	if (head==NULL)
	{
		head = new(node);
		head->x = x;
		head->y = y;
		head->next=NULL;
	}
	else
	{
		node * temp = new(node);
		temp->next = head;
		head = temp;
		temp = NULL;
		head->x = x;
		head->y = y;
	}
}

void DelFirst()
{
	if (head==NULL)	
	{
		cout<<"-1\n";
		return;
	}

	if (head->next == NULL)
	{
		delete(head);
		head = NULL;
		return;
	}

	node* temp = head;
	head = head->next;
	temp->next = NULL;
	delete(temp);
	temp = NULL;
	return;
}

void Del(int x, int y)
{
	if (head==NULL)
	{
		cout<<"-1\n";
		return;
	}
	if ((head->x==x) && (head->y==y))
	{
		DelFirst();
		return;
	}

	node* temp = head;

	while (temp->next!=NULL)
	{
		if ((temp->next->x==x) && (temp->next->y==y))
		{
			node *t = temp->next;
			if (t->next!=NULL)
				temp->next = t->next;
			else
				temp->next = NULL;
			t->next = NULL;
			delete(t);
			t = NULL;
			return;
		}
		temp = temp->next;
	}

	cout<<"-1\n";
	return;	
}

float Euclidian(node* nn)
{
	int x = nn->x;
	int y = nn->y;
	return sqrt(x*x + y*y);
}

void Search(float d)
{
	if (head==NULL)	return;

	node* ptr=head;
	int cnt=0;

	while(ptr!=NULL)
	{
		if (Euclidian(ptr) <= d)
			cnt++;
		ptr = ptr->next;
	}
	if (!cnt)	cout<<"-1\n";
	else 		cout<<cnt<<"\n";

	return;
}

bool Search(int x, int y)
{
	if (head==NULL)	return false;

	node* ptr=head;
	
	while(ptr!=NULL)
	{
		if ((ptr->x==x) && (ptr->y==y))
			return true;
		ptr = ptr->next;
	}	

	return false;
}

int Length()
{
	if (head==NULL)	return 0;

	node* ptr=head;
	int count=0;

	while(ptr!=NULL)
	{
		count++;
		ptr = ptr->next;
	}

	return count;
}

int main()
{
	head = NULL;

	int t, c, x, y;
	cin>>t;
	while(t--)
	{
		cin>>c;
		if (c==1)
		{
			cin>>x>>y;
			AddFirst(x,y);
		}
		else if (c==2)
		{
			DelFirst();
		}
		else if (c==3)
		{
			cin>>x>>y;
			Del(x,y);
		}
		else if (c==4)
		{
			cin>>x;
			Search(x);
		}
		else if (c==5)
		{
			cin>>x>>y;
			if (Search(x,y))
				cout<<"True\n";
			else
				cout<<"False\n";
		}
		else if (c==6)
		{
			cout<<Length()<<"\n";
		}
		else
		{
			cout<<"Enter again!\n";
			t++;
		}
	}

	// Empty the list to prevent memory leaks
	while (Length())
		DelFirst();

	return 0;
}
