#include<bits/stdc++.h>
using namespace std;
// Create the a vector that can store the value of the input 
const int N = 1e3 + 5; 
int n , m;
vector<string> graph_Matrix;
bool visited[N][N];
vector<pair<int,int>>dirction = {{-1,0}, {1,0},{0, -1},{0, 1}};
bool isValid(int i, int j){
    return (i >= 0 && i < n && j >= 0 && j < m);
}
int num = 0;
void DFS(int i, int j){
    if(!isValid(i, j)) return;
    if(graph_Matrix[i][j] == '-') return;
    if(visited[i][j] == true) return;
 
    visited[i][j] = true;
    num++;
    
    for(auto && dir : dirction){
        DFS(i+dir.first, j + dir.second);
    }
}
 
int main(){
    
    // Take input 
    cin >> n >> m;
    
    for (int i = 0; i < n ; i++)
    {
        string s; cin >> s;
        graph_Matrix.push_back(s);
    }
    
    // Find the number of rooms number
    int maincnt = INT_MAX;  
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(visited[i][j] == true) continue;
            if(graph_Matrix[i][j] == '-') continue;
            num = 0;
            DFS(i, j);
           maincnt = min(maincnt,num);
        }
        
    }

    if(maincnt == INT_MAX){
        cout << -1 << endl;
    }
    else
    {
        cout << maincnt << endl;
    }
    
 
    
 
 
 
    return 0;
}