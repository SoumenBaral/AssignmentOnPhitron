#include<bits/stdc++.h>
using namespace std;
const int N = 20;
vector<int>adj[N];
bool visited[N];
void dfs(int u){
    visited[u]=true;
    
    for(int v: adj[u])
    {
       if(!visited[v]){
            dfs(v);
        }
    }
    
}
int main ()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v); 

    }
     int p;
     cin>>p;

        
  dfs(p);
   int count = 0;
   for (int i = 0; i < N; ++i) {
        if (visited[i]) {
            count++;
        }
    }
    
    cout << count - 1 << endl;
    
    
    return 0;
}