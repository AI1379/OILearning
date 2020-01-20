#include <bits/stdc++.h>
using namespace std;
int n, t, m, h;
int w[110], s[110], b[110];
int dp[110][110];
int main()
{
    memset(dp, 0, sizeof(dp));
    int i, j, k;
    cin >> n >> t >> m >> h;
    for (i = 1; i <= n; i++)
    {
        cin >> w[i] >> s[i] >> b[i];
    }
    for (k = 1; k <= n; k++)
    {
        for (i = m; i >= w[i]; i--)
        {
            for (j = t; j >= s[i]; j--)
            {
                dp[i][j] = max(max(dp[i][j], dp[i - w[k]][j - s[k]] + 1), max(dp[i][j], dp[i - w[k] - b[k]][j - s[k] + h]));
            }
        }
    }
    cout << dp[m][t];
    system("pause");
    return 0;
}