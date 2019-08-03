#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string oc_mult(string s1, int d)
{
    string s3;
    reverse(s1.begin(), s1.end());
    int size1 = s1.length();
    int thisnum, i, carry=0;

    for (i=0; i<size1; i++)
    {
        thisnum = (int(s1[i]-'0') * d) + carry;
        s3.push_back(thisnum%10 + '0');
        carry = thisnum/10;
    }
    if (carry) s3.push_back(carry+'0');

    reverse(s3.begin(), s3.end());
    return s3;
}

string adder(string s1, string s2)
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


void multiplier(string s1, string s2)
{
    string s3, s4;
    int d;

    if (s1[0]=='-' && s2[0]=='-')
    {
        s1.erase(s1.begin());
        s2.erase(s2.begin());
    }
    else if (s1[0]=='-')
    {
        s1.erase(s1.begin());
        cout<<'-';
    }
    else if (s2[0]=='-')
    {
        s2.erase(s2.begin());
        cout<<'-';
    }

    reverse(s2.begin(), s2.end());

    s3 = oc_mult(s1, s2[0]-'0');

    for (int t=1; t<s2.length(); t++)
    {
        d = s2[t]-'0';
        s4 = oc_mult(s1, d);
        for (int tt=0; tt<t; tt++)  s4.push_back('0');
        s3 = adder(s3, s4);
    }
    cout<<s3;
}

int main()
{
    string s1, s2;

    getline(cin, s1);
    getline(cin, s2);

    multiplier(s1, s2);
}
