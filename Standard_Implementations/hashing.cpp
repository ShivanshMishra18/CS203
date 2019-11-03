/*
Rabin-Karp Algorithm for short string search

Find the number of times a given 
substring occurs in a string.
*/

#include <bits/stdc++.h>
using namespace std;

#define C 256    // Number of characters
#define P 101    // Prime number

bool compare(string s, string subs, int idx, int M)
{
    for (int i=0; i<M; i++)
        if (s[idx+i] != subs[i])
            return false;

    return true;
}

int main()
{
    string s, subs;
    cin >> s;
    cin >> subs;

    int N = s.length();
    int M = subs.length();

    int subs_hash = 0;
    int semi_hash = 0;
    int h = 1;

    for (int i=0; i<M-1; i++)
        h = (h * C) % P;

    int occurences = 0;

    for (int i=0; i<M; i++) {
        subs_hash = ((subs_hash * C) + subs[i]) % P;
        semi_hash = ((semi_hash * C) + s[i]) % P;
    }
    // cout << subs_hash << " " << semi_hash << " ";

    for (int i=0; i<=N-M; i++)
    {
        if (subs_hash==semi_hash && compare(s,subs, i, M)) 
            occurences++;

        if (i<N-M)
        {
            semi_hash = ((semi_hash - s[i]*h)*C + s[i+M]) % P;

            if (semi_hash < 0)  
                semi_hash = semi_hash + P;
            
            // cout << semi_hash << " ";
        }
    }

    cout << occurences;

    return 0;
}