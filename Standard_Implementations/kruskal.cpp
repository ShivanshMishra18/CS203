#include <bits/stdc++.h>
using namespace std;

// #define LD long double

int par[10000];
int r[10000];

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
	long long weight = 0;

	int n,m;
	cin >> n >> m;

	vector <pair < long long, pair<int,int> > > v;

	for (int i=0; i<n; i++)
	{
		par[i] = i;
		r[i] = 1;
	}

	for (int i=0; i<m; i++)
	{
		long long k;
		int a,b;
		cin >> a >> b >> k;

		v.push_back(make_pair(k, make_pair(a,b)));
	}

	sort(v.begin(), v.end());

	for (auto it: v)
	{
		long long k;
		int a,b;

		k = it.first;
		a = it.second.first;
		b = it.second.second;

		if (join(a,b))
			weight = weight + k;
	}

	cout << weight << "\n";
	return 0;
}
