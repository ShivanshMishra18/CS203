#include <bits/stdc++.h>
using namespace std;


int main()
{
	long long int users, queries;
	long long int user, recharge;
	int one;
	long long int max_usr=-1, max_bal=-1;

	cin>>users>>queries;

	long long int A[users]={0};

	while (queries--)
	{
		cin>>one;

		if (one==1)
		{
			cin>>user>>recharge;
			A[user] = A[user] + recharge;

			if (A[user]>max_bal)
			{
				max_bal = A[user];
				max_usr = user;
			}
		}

		else
		{
			if (max_bal == -1)
			{
				cout<<"No data available.\n";
			}
			else
			{
				cout<<max_usr<<"\n";
			}
		}

	}

	return 0;
}
