/*
Problem Statement
Given a graph. n egdes are inputted.
Find if there is a cycle formed
on addition addition of each edge.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
int par[100000];
int r[100000];

int find(int a)
{
	if (a == par[a])
		return a;

	return par[a] = find(par[a]);
}

bool join(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a==b)	return false;

	if (r[a] < r[b])
		swap (a,b);

	par[b] = a;
	if (r[a] == r[b])
		r[a]++;

	return true;
}

int main()
{
	int n;
	cin >> n;

	for (int i=0; i<100000; i++)
	{
		par[i] = i;
		r[i] = 1;
	}

	for (int i=0; i<n; i++)
	{
		int a,b;
		cin >> a >> b;
		if (!join(a,b))
			cout << "Cycle detected\n";
	}

	return 0;
}