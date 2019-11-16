#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list <int> *adjList;

public:

    Graph(int v)
    {
        V = v;
        adjList = new list <int> [v];
    }

    ~Graph()
    {
        delete[] adjList;
    }

    void addEdge(int u, int v, bool bider = true)
    {
        adjList[u].push_back(v);
        if (bider)
            adjList[v].push_back(u);
    }

    void dfsUtility(int src, bool visited[])
    {
        visited[src] = 1;
        cout << src << " ";


        for (int node: adjList[src])
        {
            if (!visited[node])
                dfsUtility(node, visited);
        }
    }

    void dfs(int src)
    {
        bool *visited = new bool[V]{0};
        visited[src] = 1;
        dfsUtility(src, visited);

        delete[] visited;
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,5);

    g.dfs(0);
    return 0;
}