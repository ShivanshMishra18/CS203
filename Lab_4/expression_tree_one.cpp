#include <bits/stdc++.h>
using namespace std;

// Structure for tree
struct node
{
	node *left;
	node *right;
	node *parent;
	string data;
} *root;

// Childern pointers - NULL
void initptr(node * p)
{
	p->left = NULL;
	p->right = NULL;
}

// String to Integer
int string_to_int(string s)
{
	int k=0;
	while(s.length())
	{
		k = k*10 + (s[0]-'0');
		s.erase(s.begin());
	}
	return k;
}

// Evaluate from expression tree
int eval_tree(node *root)
{
	node * ptr = root;
	if (ptr==NULL)
		return 0;

	if (ptr->left==NULL)
		return string_to_int(ptr->data);

	char ch = ptr->data[0];
	int left_op = eval_tree(ptr->left); 		//string_to_int(ptr->left->data);
	int right_op = eval_tree(ptr->right); 		//string_to_int(ptr->right->data);

	if (ch == '+')
		return left_op + right_op;
	else if (ch == '-')
		return left_op - right_op;
	else if (ch == '*')
		return left_op * right_op;
	else if (ch == '/')
		return left_op / right_op;
	else if (ch == '^')
		return pow(left_op, right_op);
}

// Priority order for operators
int prior(string y)
{
	if (y=="^")
		return 3;
	else if (y=="*" || y=="/")
		return 2;
	else if (y=="+" || y=="-")
		return 1;
	else
		return -1;
}

// Check if string is operator
bool isoper(string y)
{
	if (y=="+" || y=="-" || y=="*" || y=="/" || y=="^")
		return true;
	return false;
}

// Free pointers from tree
void destroy(node *root)
{
	node *ptr = root;
	node *pl = ptr->left;
	node *pr = ptr->right;

	ptr->left = NULL;
	ptr->right = NULL;

	delete(ptr);

	if (pl!=NULL)	destroy(pl);
	if (pr!=NULL)	destroy(pr);
}

// Take input, convert to postfix and return as vector
vector <string> input()
{

	vector <string> v;
	
	string s;
	getline(cin, s);

	string kk="";
	kk.append(s,0,1);
	v.push_back(kk);
	s.erase(s.begin());

	// Tokenize input
	while (s.length())
	{
		if ((s[0]-'0')>=0 && (s[0]-'0')<=9)
		{
			if ((v.back()[0]-'0'<=9) && (v.back()[0]-'0'>=0))
				{
					string tt= v.back();
					// cout<<v.back();
					v.back().clear();
					v.back() = to_string(((string_to_int(tt))*10) + (int)(s[0]-'0'));
				}
			else
			{
				v.push_back(to_string(s[0]-'0'));
			}
		}

		else
		{
			string k="";
			k.append(s,0,1);
			v.push_back(k);
		} 

		s.erase(s.begin());
	}

	// for (int i=0; i<v.size(); i++)
	// {
	// 	cout<<v[i]<<" ";
	// }
	

	//Infix to Postfix
	stack <string> st;
	vector<string> vout;
	string rr="_N_";

	st.push(rr);
	int l = v.size();

	for (int i=0; i<l; i++)
	{
		if ((v[i][0]-'0'<=9) && (v[i][0]-'0'>=0))
			vout.push_back(v[i]);

		else if (v[i]=="(")
			st.push(v[i]);

		else if (v[i]==")")
		{
			while(st.top() != "_N_" && st.top() != "(") 
            { 
                string c = st.top(); 
                st.pop(); 
               	vout.push_back(c);
            } 
            if(st.top() == "(") 
            { 
                string c = st.top(); 
                st.pop(); 
            } 
		}

    	else
    	{ 
    		if (((v[i][0]-'a'>=0) && (v[i][0]-'a'<=25)) || ((v[i][0]-'A'>=0) && (v[i][0]-'A'<=25)))
    		{
    			cout<<"CANT BE EVALUATED\n";
    			vector <string> ww;
    			return ww;
    		} 	
            while(st.top() != "_N_" && prior(v[i]) <= prior(st.top())) 
            { 
                string c = st.top(); 
                st.pop(); 
                vout.push_back(c);
            } 
            st.push(v[i]); 
        } 
	}

	while(st.top() != "_N_") 
    { 
        string c = st.top(); 
        st.pop(); 
        vout.push_back(c); 
    } 

    return vout;
}

int main()
{

	int cases;
	int queries;

	scanf("%d\n", &cases);
	
	while (cases--){

	scanf("%d\n", &queries);

	while (queries--){

	vector<string> q(input());

    // for (int j=0; j<q.size(); j++)
    // 		cout<<q[j]<<" "; 
    if (!q.size())	continue;

	root = new(node);
	initptr(root);
	root->parent = NULL;

	root->data = q.back();
	q.pop_back();

	node *ptr = root;

	// Generate Evaluation Tree from Postfix Vector
	while (q.size())
	{
		string nxt=q.back();
		q.pop_back();

		if (isoper(nxt))
		{
			if (ptr->right == NULL) 
			{
				ptr->right = new(node);
				ptr->right->parent = ptr;
				ptr = ptr->right;
				initptr(ptr);
				ptr->data = nxt;
			}
			else
			{
				ptr->left = new(node);
				ptr->left->parent = ptr;
				ptr = ptr->left;
				initptr(ptr);
				ptr->data = nxt;
			}
		}
		else
		{
			while(1)
			{
				if (ptr->right == NULL) 
				{
					ptr->right = new(node);
					ptr->right->parent = ptr;
					ptr = ptr->right;
					initptr(ptr);
					ptr->data = nxt;
					ptr = ptr->parent;
					break;
				}
				else if (ptr->left == NULL) 
				{
					ptr->left = new(node);
					ptr->left->parent = ptr;
					ptr = ptr->left;
					initptr(ptr);
					ptr->data = nxt;
					ptr = ptr->parent;
					break;
				}
				else
					ptr = ptr->parent;
			}
		}
	}

	cout<<eval_tree(root);
	destroy(root);
	cout<<"\n";
	}
	}

	return 0;
}
