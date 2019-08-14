#include <iostream>
#include <string>
using namespace std;

struct node
{
	char b;
	node * next;
} *head;

void push(char c)
{
	if (head==NULL)
	{
		head = new(node);
		head->b = c;
		head->next=NULL;
	}
	else
	{
		node * temp = new(node);
		temp->next = head;
		head = temp;
		temp = NULL;
		head->b= c;
	}
}

void pop()
{
	if (head==NULL)	return;
	
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

char peektop()
{
	char ch='.';
	if (head==NULL)
		return ch;
	return char(head->b);
}


int main()
{
	int q;
	string rr;
	cin>>q;
	getline(cin, rr);
	head = NULL;

	while (q--)
	{
		string s;
		getline(cin, s);
		bool flag = false;

		while (s.length())
		{
			// In case of opening bracket excluding |
			if (s[0]=='(' || s[0]=='{' || s[0]=='[' || s[0]=='<')
			{
				push(s[0]);
				s.erase(s.begin());
			}

			// Case of |
			else if (s[0]=='|')
			{
				char ch;
				ch = peektop();
				if (ch=='|')
				{
					pop();
					s.erase(s.begin());
				}
				else
				{
					push(s[0]);
					s.erase(s.begin());
				}
			}

			// In case of closing brackets excluding |
			else if (s[0]==')' || s[0]=='}' || s[0]==']' || s[0]=='>')
			{
				char tch = peektop();
				if ((s[0]==')' && tch=='(') || (s[0]=='}' && tch=='{') || (s[0]=='>' && tch=='<') || (s[0]==']' && tch=='['))
				{
					s.erase(s.begin());
					pop();
				}
				else
				{
					flag = true;
					break;
				}
			}

			// In case of balanced sequence of brackets
			else
			{
				flag =true;
				break;
				s.erase(s.begin());
			}
		}

		if (flag || (peektop()!='.'))		 	cout<<"NO\n"; 
		else								cout<<"YES\n";

		while (peektop()!='.')				pop();
	}

	return 0;
}
