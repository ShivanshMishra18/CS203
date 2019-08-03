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


int main()
{
    string s1, s2, s3, s4, s;
    string srr[11];

    srr[0]="0";
    getline(cin, s1);
    getline(cin, s2);
    int big=isbigger(s1,s2);

    if (!big)           cout<<"quotient=1 remainder=0";
    else if (big==2)    cout<<"quotient=0 remainder="<<s1;
    else
    {
        s = s1;
        s3 = s1.substr(0, s2.length());
        s.erase(s.begin(), s.begin()+s2.length());

        for (int i=1; i<10; i++)
            srr[i] = oc_mult(s2, i);
        srr[10] = s2;
        srr[10].push_back('0');

        while (s.length())
        {
            for (int j=1; j<=10; j++)
            {
                big = isbigger(srr[j], s3);

                if (!big)
                {
                    s4.push_back(j+'0');
                    s3.clear();
                    s3.push_back(s[0]);
                    s.erase(s.begin());
                    //cout<<"\n"<<srr[j];
                    break;
                }
                else if (big==2)
                    continue;
                else
                {
                    s4.push_back((j-1)+'0');
                    s3 = showdiff(s3, srr[j-1]);
                    s3.push_back(s[0]);
                    s.erase(s.begin());
                    //cout<<"\n"<<srr[j-1];
                    break;
                }
            }
        }

        for (int j=1; j<=10; j++)
        {
            big = isbigger(srr[j], s3);
            if (!big)
            {
                s4.push_back(j+'0');
                s3.clear();
                s3.push_back('0');
                break;
            }
            else if (big==2)
                continue;
            else
            {
                s4.push_back((j-1)+'0');
                s3 = showdiff(s3, srr[j-1]);
                break;
            }
        }

        if (s3=="")
            s3.push_back('0');

        while (s4[0]=='0')
            s4.erase(s4.begin());
        cout<<"quotient: "<<s4<<" remainder: "<<s3;
    }

    return 0;
}
