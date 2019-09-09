#include <bits/stdc++.h>
using namespace std;

bool isbigger(string s1, string s2)
{

	for (int i=0; i<s1.length(); i++)
	{
		if ((s1[i]-'0') > (s2[i]-'0'))	return true;
		else if ((s1[i]-'0') < (s2[i]-'0'))	return false;
	}

	return true;
}


bool comparator(string a, string b)
{
	return !isbigger(b+a, a+b);
}

void output(string strs[], long long int sz)
{	
	for (long long int i=0; i<sz; i++)
		cout<<strs[i];
	cout<<"\n";
}

int main()
{
	long long int n, q, i;

	cin>>n;
	string rr;

	while (n--)
	{
		cin>>q;
		getline(cin, rr);

		string str_arr[q];

		for (i=0; i<q; i++)
			getline(cin, str_arr[i]);

		sort(str_arr, str_arr + q, comparator);
		output(str_arr, q);
	}

	return 0;
}
