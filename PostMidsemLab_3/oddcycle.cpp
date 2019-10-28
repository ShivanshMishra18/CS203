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
	Graph g(n+m);
	int dummy = n+1;

	for (int i=0; i<m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (c%2)
		{
			g.addEdge(a,dummy);
			g.addEdge(dummy,b);
			dummy++;
		}
		else
			g.addEdge(a,b);
	}

	int *visited = new int[n+m+1]{0};

	bool isb = true;
	bool oddc = false;

	for (int i=0; i<=n+m; i++)
	{
		if (!visited[i])
		{
			isb = g.isBipartite(i, visited);
			if (!isb)
			{
				oddc = true;
				break;
			}
		}
	}

	if (oddc)	cout << "YES";
	else 		cout << "NO";

	delete[] visited;
	return 0;
}
