#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
vector<int> adj[N];
bool visited[N];

void dfs(int node, vector<int> &component)
{
    visited[node] = true;
    component.push_back(node);

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, component);
        }
    }
}

int main()
{
    int N, E;
    cin >> N >> E;

    for (int i = 0; i < E; ++i)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A); // Undirected graph
    }

    vector<int> componentSizes;

    for (int i = 0; i < N; ++i)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, component);
            componentSizes.push_back(component.size());
        }
    }

    sort(componentSizes.begin(), componentSizes.end());

    for (int size : componentSizes)
    {
        if(size==1)continue;
        cout << size << " ";
    }

    return 0;
}
