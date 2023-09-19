#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+1;
int dp[N];
bool choose(int n, ll x)
{
    if (n == x) return true;
    else if (n<x) return false;
    if (dp[x] != -1) return dp[x];
       
    bool opt1 = choose(n, x + 3);
    bool opt2 = choose(n, x * 2);

    return dp[x] = opt1 || opt2;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            dp[i] = -1;
        }
        
        if (choose(n, 1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}