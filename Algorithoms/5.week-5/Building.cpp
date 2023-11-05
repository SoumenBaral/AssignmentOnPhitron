#include<bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
const int N = 1e5 + 5;
vector<pi> v[N];
bool vis[N];
class Edges{
    public:
    int u;
    int v;
    int w;

    Edges(int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
class cmp{
    public:

    bool operator()(Edges a, Edges b){
        return a.w > b.w;
    }
};

void prims(int s, int n){
    priority_queue<Edges, vector<Edges>,cmp> pq;
    pq.push(Edges(s,s,0));
    int cnt =  0;
    vector<Edges> edgeListOfRoad;

    while (!pq.empty())
    {
        Edges parent = pq.top();
        pq.pop();

        int b = parent.v;
        if(vis[b]) continue;
        vis[b] = true;
        edgeListOfRoad.push_back(parent);
        cnt++;

        for (int i = 0; i < v[b].size(); i++)
        {
            pi child = v[b][i];
            if (!vis[child.first])
            {
                pq.push(Edges(b, child.first, child.second));
            }
        }
        
    }
    edgeListOfRoad.erase(edgeListOfRoad.begin());
    long long int sum = 0;
    for (Edges ed : edgeListOfRoad)
    {
        sum += ed.w;
    }
    if(cnt == n){
        cout << sum << endl;
    }
    else{
        cout << -1 << endl;
    }
    
    
}

int main(){
    
    
    int n, e; 
    cin >> n >> e;
     
     while (e--)
     {
        int a, b, w;
        cin >> a >> b >> w;

        v[a].push_back({b,w});
        v[b].push_back({a,w});
     }

     prims(1, n);
     
     

    return 0;
}