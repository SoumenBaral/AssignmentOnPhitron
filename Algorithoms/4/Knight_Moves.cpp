#include<bits/stdc++.h>
#define pi pair<int,int>
using namespace std;
const int N = 105;
int dis[N][N]; 
bool visited[N][N];
int n, m; 
vector<pi> path = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
bool isValid(int cI, int cJ)
{
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m)
        return true;
    else
        return false;
}
void Bfs(int si,int sj){
    queue<pi> q;
    q.push({si, sj});
    dis[si][sj] = 0;
    visited[si][sj] = true;

    while (!q.empty())
    {
        pi parent = q.front();
        int Pi = parent.first;
        int Pj = parent.second;
        q.pop();

        for (pi dir : path)
        {
            int Ci = Pi + dir.first;
            int Cj = Pj + dir.second;

            if(isValid(Ci, Cj) && !visited[Ci][Cj]){
                q.push({Ci, Cj});
                visited[Ci][Cj] = true;
                dis[Ci][Cj] = dis[Pi][Pj] + 1;
            }
        }
        
    }

}

int main ()
{
    int test_Case; cin >> test_Case;

     for (int i = 0; i < test_Case; i++)
     {
        cin >> n >> m;
        int ki, kj, qi, qj;
        cin >> ki  >> kj >> qi >> qj;
       

        Bfs(ki, kj);

        if(visited[qi][qj]){
        cout << dis[qi][qj] << endl;
        }
        else{
            cout << -1 << endl;
        }
        

        for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    dis[i][j] = 0;
                    visited[i][j] = false;

                }
        
            }

     }
    return 0;
}