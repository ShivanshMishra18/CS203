#include <bits/stdc++.h>
using namespace std;

// bool visited[100][100];
// bool graph[100][100];

int n,m,k;
int ans = 0;
int fin_ans = -1;

void dfs(int x, int y, vector <vector <bool>> &visited, vector <vector <bool>> &graph) {
	visited[x][y] = 1;
	ans++;

	if ((x<n) && (x>=0) && (y+1<m) && (y+1>=0) && (graph[x][y+1])) 
	{
		if (!visited[x][y+1]) {
			dfs(x,y+1,visited,graph);
		}
	}

	if ((x<n) && (x>=0) && (y-1<m) && (y-1>=0) && (graph[x][y-1]))
	{
		if (!visited[x][y-1]) {
			dfs(x,y-1,visited,graph);
		}
	}

	if ((x+1<n) && (x+1>=0) && (y<m) && (y>=0) && (graph[x+1][y])) 
	{
		if (!visited[x+1][y]) {
			dfs(x+1,y,visited,graph);
		}
	}

	if ((x-1<n) && (x-1>=0) && (y<m) && (y>=0) && (graph[x-1][y])) 
	{
		if (!visited[x-1][y]) {
			dfs(x-1,y,visited,graph);
		}
	}
	if (ans > fin_ans) {
		fin_ans = ans;
	}

}

int main()
{
	
	cin>>n>>m>>k;
	int x,y;

	vector<vector <bool>> visited (n, vector<bool> (m));
	vector<vector <bool>> graph (n, vector<bool> (m));

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			visited[i][j]=0;
			graph[i][j]=0;
		}
	}

	for (int i=0; i<k; i++) 
	{
		cin >> x >> y;
		graph[x-1][y-1] = 1;
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (!visited[i][j] && graph[i][j]) {
				ans = 0;
				dfs(i,j, visited, graph);
			}
		}
	}
	cout << fin_ans << "\n";

	return 0;
}
