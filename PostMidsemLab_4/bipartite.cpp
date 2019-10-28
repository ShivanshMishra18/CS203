#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list <int> *adjList;

	public:

	Graph(int v)
	{
		V = v+1;
		adjList = new list <int> [V];
 	}

 	~Graph()
 	{
 		delete[] adjList;
 	}

 	void addEdge(int x, int y)
 	{
 		adjList[x].push_back(y);
 		adjList[y].push_back(x);
 	}

 	bool isBipartite(int src, int visited[])
 	{
 		queue <int> q;
 		q.push(src);
 		visited[src]=1;

 		while(!q.empty())
 		{
 			int elt = q.front();
 			q.pop();

 			for (auto i: adjList[elt])
 			{
 				if (!visited[i])
 				{
 					visited[i] = (visited[elt]==1) ? 2 : 1;
 					q.push(i);
 				}
 				else
 				{
 					int should_be = (visited[elt]==1) ? 2 : 1;
 					if (visited[i] != should_be)
 						return false;
 				}
 			}
 		}
 		return true;
 	}

};

int main()
{
	int n, m;
	cin >> n >> m;
	Graph g(n);

	for (int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		g.addEdge(a,b);
	}

	int *visited = new int[n]{0};

	bool isb = true;

	for (int i=0; i<=n && isb; i++)
	{
		if (!visited[i])
			isb = g.isBipartite(i, visited);
	}

	if (isb)	cout << "YES";
	else 		cout << "NO";

	delete[] visited;
	return 0;
}