#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list <int> *adjList;

public:

    Graph(int v) {
        V = v;
        adjList = new list <int> [V];
    }

    ~Graph() {
        delete[] adjList;
    }

    void addEdge(int u, int v, bool bider=true) {
        adjList[u].push_back(v);

        if (bider)
            adjList[v].push_back(u);
    }

    void printAdjList() {
        for (int i=0; i<V; i++) {
            cout << i << " --> ";
            for (auto node: adjList[i])
                cout << node << ", ";
        }
    }

    void dfs(int src) 
    {
        queue <int> q;
        bool *visited = new bool[V]{0};

        q.push(src);
        visited[src] = 1;
        while (!q.empty())
        {
            int t = q.front();
            cout << t << " ";
            q.pop();
            for (int node: adjList[t])
            {
                if (!visited[node]) 
                {
                    q.push(node);
                    visited[node] = 1;
                }
            }
        }

        delete[] visited;
    }

    void shortestPath(int src, int dest)
    {
        queue <int> q;
        bool *visited = new bool[V]{0};
        int *parent = new int[V];
        int *dist = new int[V]{0};

        for (int u=0; u<V; u++)
            parent[u] = -1;

        q.push(src);
        visited[src] = 1;

        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            for (int node: adjList[t])
            {
                if (!visited[node])
                {
                    visited[node] = 1;
                    parent[node] = t;
                    dist[node] = dist[t] + 1;
                    q.push(node);
                }
            }
        }

        int i = dest;
        while (i!=-1)
        {
            cout << i << " --> " ;
            i = parent[i];
        }

        // for (int p=0; p<V; p++)
        //     cout << parent[p] << " ";

        // int distance = dist[dest];

        delete[] visited;
        delete[] parent;
        delete[] dist;

        // return distance;
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,4);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(2,3);
    // g.dfs(0);
    g.shortestPath(0,5);
    return 0;
}