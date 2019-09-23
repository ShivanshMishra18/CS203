#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll retMedian(ll A[], int sz)
{
	sort(A, A+sz);
	return A[sz/2];
}

void swap(ll *a, ll *b) 
{ 
    ll temp = *a; 
    *a = *b; 
    *b = temp; 
} 

ll partition(ll A[], ll l, ll r, ll pivot)
{ 
    ll i, tmp; 
    
    for (i=l; i<r; i++) 
        if (A[i] == pivot) break; 
  
    swap(&A[i], &A[r]);
    
    i = l; 

    for (ll j = l; j <= r - 1; j++) 
    { 
        if (A[j] <= pivot) 
        { 
            swap(&A[i], &A[j]); 
            i++; 
        } 
    } 
    
    swap(&A[i], &A[r]); 
    
    return i; 
} 

double medianRadius(ll A[], ll l, ll r, ll k) 
{ 
    
    if (k > 0 && k <= r - l + 1) 
    { 
        ll n = r-l+1; 
        ll i, median[(n+4)/5]; 

        for (i=0; i<n/5; i++) 
            median[i] = retMedian(A+l+i*5, 5); 

        if (i*5 < n) 
        { 
            median[i] = retMedian(A+l+i*5, n%5);  
            i++; 
        }     
  
        ll pivot = (i == 1)? median[i-1]: medianRadius(median, 0, i-1, i/2); 
  
        ll pos = partition(A, l, r, pivot); 
  
        if (pos-l == k-1) return A[pos]; 
        if (pos-l > k-1)  return medianRadius(A, l, pos-1, k); 
        return medianRadius(A, pos+1, r, k-pos+l-1); 
    } 
    return INT_MAX; 
} 

int main()
{
	int queries;
	cin>>queries;

	while (queries--)
	{
		ll n, i, x, y;
		cin>>n;

		ll radii[n];

		for (i=0; i<n; i++)
		{
			cin>>x>>y;
			radii[i]=(x*x)+(y*y); 
		}

		ll rad = medianRadius(radii, 0, n-1, (n+1)/2);
		double res = sqrt(rad);
		cout<<res<<"\n";
	}

	return 0;
}
