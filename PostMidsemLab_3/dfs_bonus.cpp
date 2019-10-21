#include <bits/stdc++.h>
using namespace std;

// bool visited[100][100];
// bool graph[100][100];

int n,m,c;
int ans = 0;
int fin_ans = -1;

void dfs(int x, int y, vector <vector <bool>> &visited, vector <vector <int>> &graph, int color) {
	visited[x][y] = 1;
	ans++;

	if ((x<n) && (x>=0) && (y+1<m) && (y+1>=0) && (graph[x][y+1]==color)) 
	{
		if (!visited[x][y+1]) {
			dfs(x,y+1,visited,graph,color);
		}
	}

	if ((x<n) && (x>=0) && (y-1<m) && (y-1>=0) && (graph[x][y-1]==color))
	{
		if (!visited[x][y-1]) {
			dfs(x,y-1,visited,graph,color);
		}
	}

	if ((x+1<n) && (x+1>=0) && (y<m) && (y>=0) && (graph[x+1][y]==color)) 
	{
		if (!visited[x+1][y]) {
			dfs(x+1,y,visited,graph,color);
		}
	}

	if ((x-1<n) && (x-1>=0) && (y<m) && (y>=0) && (graph[x-1][y]==color)) 
	{
		if (!visited[x-1][y]) {
			dfs(x-1,y,visited,graph,color);
		}
	}
	if (ans > fin_ans) {
		fin_ans = ans;
	}

}

int main()
{
	
	cin>>n>>m>>c;
	int x;

	vector<vector <bool>> visited (n, vector<bool> (m));
	vector<vector <int>> graph (n, vector<int> (m));

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			visited[i][j]=0;
			graph[i][j]=0;
		}
	}

	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			cin >> x;
			graph[i][j] = x;
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (!visited[i][j]) {
				ans = 0;
				dfs(i,j, visited, graph, graph[i][j]);
			}
		}
	}
	cout << fin_ans << "\n";

	return 0;
}
