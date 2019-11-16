#include <bits/stdc++.h> 
using namespace std; 
#define INF 1000000

int graph[2000][2000];

void FW(int n)
{
	int dist[n][n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dist[i][j] = graph[i][j];


	for (int k = 0; k < n; k++) 
	{ 
		for (int i = 0; i < n; i++) 
		{ 
			for (int j = 0; j < n; j++) 
			{  
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		} 
	} 

	for (int i = 0; i < n; i++) 
	{ 
		for (int j = 0; j < n; j++) 
		{ 
			if (dist[i][j] == INF) 
				cout<<"INF"<<"	"; 
			else
				cout<<dist[i][j]<<"	 "; 
		} 
		cout<<"\n"; 
	} 
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (i!=j)
			graph[i][j] = INF;


	for (int i=0; i<m; i++)
	{
		int a, b, wt;
		cin >> a >> b >> wt;
		graph[a][b] = wt;
		graph[b][a] = wt;
	}

	FW(n);
	return 0;	
}