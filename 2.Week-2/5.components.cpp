#include<bits/stdc++.h>
using namespace std;

const int N = 1001;
int x = 1;
vector<int> counted;
vector<int> adj[N];
bool visited[N];

void dfs(int u) {
    x++;
    visited[u] = true;
    for(int v: adj[u]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   
    for(int i = 1; i <= 1000; i++) {
        if(!visited[i]) {
            x = 0;
            dfs(i);
            counted.push_back(x);
        }
    }
    sort(counted.begin(),counted.end());
   for(int z:counted){
    if(z==1)continue;
    cout << z << " ";
   }
   
    return 0;
}
