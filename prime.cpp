#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	long long int n, i, root;
	bool flag=0;
	cin>>n

	root = sqrt(n);

	for (i=2; i<=root; i++)
	{
		if (!(n%i))
		{
			flag=1;
			break;
		}
	}

	if (flag)	cout<<"Not Prime";
	else		COUT<<"Prime";

	return 0;
}