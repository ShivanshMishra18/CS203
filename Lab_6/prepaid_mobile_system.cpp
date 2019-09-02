#include <bits/stdc++.h>
using namespace std;

int main()
{
	int users, queries;
	int user, recharge;
	int one;
	int distinct = 1;
	int tsize = 0;
	bool empty=true;

	cin>>users>>queries;

	int A[queries];
	int B[queries];
	int temp[queries];
	int C[queries];
	int D[queries]={0};

	for (int i=0; i<queries; i++)
	{
		cin>>one;

		if (one==1)
		{
			cin>>user>>recharge;
			A[i]=user;
			temp[i]=user;
			tsize++;
			B[i]=recharge;
		}

		else
		{
			A[i]=-1;
		}
	}

	sort(temp, temp+tsize);

	C[0] = temp[0];
	for (int i=1, count=0; i<tsize; i++)
	{
		if (temp[i]!=C[count])
		{
			C[++count]=temp[i];
			distinct++;
		}
	}

	int max_usr=-1, max_bal=-1;

	for (int i=0; i<queries; i++)
	{
		if (A[i]==-1)
		{
			if (max_usr == -1)	cout<<"No data available.\n";
			else			cout<<max_usr<<"\n";
		}

		else
		{
			int pos = lower_bound(C, C+distinct, A[i]) - C;
			D[pos] = D[pos] + B[i];

			if (D[pos]>max_bal)
			{
				max_bal = D[pos];
				max_usr = A[i];
			}
		}
	}

	return 0;
}
