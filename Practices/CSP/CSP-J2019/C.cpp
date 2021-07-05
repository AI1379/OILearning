#include <bits/stdc++.h>
using namespace std;
int dp[10010];
int price[110][110];
int t, n, m, ans = 0;
int main()
{
    cin >> t >> n >> m;
    int i, j, k;
    for (i = 1; i <= t; i++)
        for (j = 1; j <= n; j++)
            cin >> price[i][j];
    ans = m;
    for (i = 1; i <= t; i++)
    {
        memset(dp, ~0x3f, sizeof(dp));
        dp[ans] = ans;
        for (j = 1; j <= n; j++)
            for (k = ans; k >= price[i][j]; k--)
                dp[k - price[i][j]] = max(dp[k - price[i][j]], dp[k] + price[i + 1][j] - price[i][j]);
        int maxdp = 0;
        for (j = 0; j <= ans; j++)
            maxdp = max(maxdp, dp[j]);
        ans = maxdp;
    }
    cout << ans;
    return 0;
}