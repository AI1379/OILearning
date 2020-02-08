#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
char mp[55][55];
int dp[55][55];
int m, n;
int main()
{
    int i, j;
    cin >> n >> m;
    memset(dp, 0, sizeof(dp));
    for (i = 1; i <= n; i++)
    {
        getchar();
        for (j = 1; j <= m; j++)
        {
            mp[i][j] = getchar();
        }
    }
    getchar();
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
            {
                dp[i][j] = 1;
                continue;
            }
            if (mp[i - 1][j] == 'D' || mp[i - 1][j] == 'B')
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            }
            if (mp[i][j - 1] == 'R' || mp[i][j - 1] == 'B')
            {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
            }
        }
    }
    cout << dp[n][m];
    return 0;
}