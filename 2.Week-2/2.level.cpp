#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int>adj[N];
bool visited[N];
int level[N];
void bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s]=true;
    level[s]=0;
    while(!q.empty()){
         int u =q.front();
            q.pop();
        for(int v: adj[u]){
            if(visited[v]==true)continue;
            q.push(v);
            visited[v]=true;
            level[v]=level[u]+1;
        }
    }
    
}
int main ()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(0);
    int p;
    cin>>p;
    queue<int>v;
    for(int i=0;i<n;i++){
        if(p == level[i]){
            v.push(i);
         
        }
       
    }

   if(v.empty()){
       
     cout<<-1;
   }
   else{
     while (!v.empty())
        {
            int x = v.front();
            v.pop();
            cout<<x<<" ";
        }
   }
    
    return 0;
}