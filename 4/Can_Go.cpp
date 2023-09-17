#include<bits/stdc++.h>
using namespace std;
#define pi pair <int,int>
const int N = 1e3+ 10;
vector<pi> v[N];
int dis[N];
bool visited[N];

void Djk(int s){
   priority_queue< pi, vector<pi>, greater<pi>>pq; 
    dis[s] = 0;
    pq.push({dis[s],s});

    while (!pq.empty())
    {
        pi parent = pq.top();
        long long int parentNode = parent.second;
        long long int parentCost = parent.first;
         pq.pop();

        if(visited[parentNode]) continue;
        visited[parentNode] = true;
        
        for (pi i : v[parentNode])
        {
            long long int child = i.second;
            long long int childCost = i.first;
            if(dis[child] >= parentCost + childCost){
                dis[child] = parentCost + childCost;
                pq.push({dis[child], child});
            }
            
        }
        

        
    }
        
}
int main(){

     int n, e; cin >> n >> e; 
     while(e--)
     {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({w,b});
     }

     for (int i = 1; i <=n; i++)
     {
        dis[i] = INT_MAX;
     }
      for (int i = 1; i <=n; i++)
     {
        visited[i] = false;
     }

     int src; cin >> src;
     Djk(src);

    int T;
    cin >> T;
    while(T--)
    {
        int a, b; cin >> a >> b;
        if(dis[a] <= b) cout << "YES" << endl;

        else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}