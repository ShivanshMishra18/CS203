#include <bits/stdc++.h>
using namespace std;

vector <pair<int,int>> *adjList;

void addEdge(int u, int v, int wt)
{
    adjList[u].push_back(make_pair(v,wt));
    adjList[v].push_back(make_pair(u,wt));
}

void prim(int n)
{
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
    
    vector <int> dist(n, 10000000);
    vector <int> par(n, -1);
    vector <bool> visited(n,0);

    dist[0]=0;
    p.push(make_pair(0,0));

    while (!p.empty())
    {
        int v = p.top().second;
        p.pop();
        visited[v]=1;

        for (auto x: adjList[v])
        {
            int nbr = x.first;
            int wt = x.second;

            if (!visited[nbr] && dist[nbr]>wt)
            {
                dist[nbr] = wt;
                p.push(make_pair(wt,nbr));
                par[nbr] = v;
            }
        }
    }

    for (int i=0; i<n; i++)
    cout << par[i] << " is parent of " << i << "\n";
}

int main()
{
    int n;
    cin >> n;
    adjList = new vector<pair<int,int>>[n];

    int m;
    cin >> m;

    for (int i=0; i<m; i++)
    {
        int a,b,wt;
        cin >> a >> b >> wt;
        addEdge(a,b,wt);
    }

    prim(n);

    delete[] adjList;
    return 0;
}
