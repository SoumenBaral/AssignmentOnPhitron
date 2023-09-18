#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const long long int INF = 1e18;
vector<long long int> dis(N, INF);
class Edge
{
    public:
    int u;
    int v;
    int w;
    Edge(int u, int v,int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }

};
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> V;

   while(e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        Edge ed(a,b,w);
        V.push_back(ed);
    }
    int src;
    cin >> src;
    dis[src] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < V.size(); j++)
        {
            Edge ed = V[j];
            int u = ed.u;
            int v = ed.v;
            int w = ed.w;

            if (dis[u] < INF && dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
            };
        }
    };
    bool isCycle = false;
    for (int j = 0; j < V.size(); j++)
    {
        Edge ed = V[j];
        int u = ed.u;
        int v = ed.v;
        int w = ed.w;

        if (dis[u] < INF && dis[v] > dis[u] + w)
        {
            isCycle = true;
            break;
        };
    }
    if (isCycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        int t;
        cin >> t;
        while (t--)
        {
            int d;
            cin >> d;
            if (dis[d] == INF)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dis[d] << endl;
            }
        }
    }

    return 0;
}