#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int isbigger(string s1, string s2)
{
	if (s1.length() > s2.length())	return 1;
	else if (s2.length() > s1.length())	return 2;
	else
	{
		for (int i=0; i<s1.length(); i++)
		{
			if ((s1[i]-'0') > (s2[i]-'0'))	return 1;
			else if ((s1[i]-'0') < (s2[i]-'0'))	return 2;
		}
	}
	return 0;
}

string showdiff(string s1, string s2)
{
    int c=0, thisnum, i;
    string s3;

    reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	int size1=s1.length();
	int size2=s2.length();

	for (i=0; i<size2; i++)
	{
		if ((int)(s1[i]-'0')+c >= (int)(s2[i]-'0'))
		{
			thisnum = (int)(s1[i]-'0') - (int)(s2[i]-'0') + c;
			s3.push_back(thisnum+'0');
			c = 0;
		}
		else
		{
			thisnum = 10 + c + (int)(s1[i]-'0') - (int)(s2[i]-'0');
			s3.push_back(thisnum+'0');
			c = -1;
		}
	}

	for (; i<size1; i++)
	{
		if ((int)(s1[i]-'0')+c >= 0)
		{
			thisnum = (int)(s1[i]-'0')+ c;
			s3.push_back(thisnum+'0');
			c = 0;
		}
		else
		{
			thisnum = 10 + c + (int)(s1[i]-'0');
			s3.push_back(thisnum+'0');
			c = -1;
		}
	}

	reverse(s3.begin(), s3.end());
	while (s3[0]=='0')  s3.erase(s3.begin());
	return s3;
}

string showsum(string s1, string s2)
{
    int c=0, thisnum, i;
    string s3;

    reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	int size1=s1.length();
	int size2=s2.length();

	if (size1 > size2)
	{
		for (i=0; i<size2; i++)
		{
			thisnum = (int)(s1[i]-'0') + (int)(s2[i]-'0') + c;
			s3.push_back(thisnum%10 + '0');
			c = thisnum/10;
		}
		for (; i<size1; i++)
		{
			thisnum = (int)(s1[i]-'0') + c;
			s3.push_back(thisnum%10 + '0');
			c = thisnum/10;
		}
		if (c==1)	s3.push_back('1');
	}

	else
	{
		for (i=0; i<size1; i++)
		{
			thisnum = (int)(s1[i]-'0') + (int)(s2[i]-'0') + c;
			s3.push_back(thisnum%10 + '0');
			c = thisnum/10;
		}
		for (; i<size2; i++)
		{
			thisnum = (int)(s2[i]-'0') + c;
			s3.push_back(thisnum%10 + '0');
			c = thisnum/10;
		}
		if (c==1)	s3.push_back('1');
	}

	reverse(s3.begin(), s3.end());
	return s3;
}

void differentiator(string s1, string s2)
{
	char sign1, sign2;
	int outcome;

	sign1 = s1[0];
	sign2 = s2[0];

	if (sign1=='-' && sign2=='-')
	{
	    s1.erase(s1.begin());
	    s2.erase(s2.begin());
	    outcome = isbigger(s1, s2);

	    if (!outcome)         cout<<"0";
	    else if (outcome==2)  cout<<showdiff(s2,s1);
	    else                  cout<<"-"<<showdiff(s1,s2);
	}

	else if (sign1=='-')
	{
	    s1.erase(s1.begin());
	    cout<<"-"<<showsum(s1,s2);
	}

    else if (sign2=='-')
    {
        s2.erase(s2.begin());
        cout<<showsum(s1,s2);
    }

	else
	{
	    outcome = isbigger(s1, s2);
        if (!outcome)           cout<<"0";
        else if (outcome == 1)  cout<<showdiff(s1,s2);
        else                    cout<<"-"<<showdiff(s2,s1);
	}
}


int main()
{
    int t; cin>>t;
    string rr; getline(cin, rr);

    while(t--)
    {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        differentiator(s1, s2);
        cout<<"\n\n";
    }
	return 0;
}
