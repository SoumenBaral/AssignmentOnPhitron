#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n,m;
        cin>>n>>m;
        int s = 1000-m;
        int val[n];
        int dp[n+1][s+1];
        for (int i = 0; i <=n; i++)
        {
            for (int j = 0; j <=s; j++)
            {
                if(i==0 || j== 0)
                {
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            cin >> val[i];
        }
        for (int i = 1; i <=n; i++)
        {
            for (int j = 1; j <=s; j++)
            {
                if(val[i-1] <= j)
                {
                    dp[i][j] = max(val[i-1] + dp[i][j-val[i-1]], dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    if(dp[n][s] == s)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    }
    return 0;
}