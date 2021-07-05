#include <bits/stdc++.h>
using namespace std;
int dp[350][350];
int value[350];
int add[350] int n;
int main()
{
    int i, j, k, l;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> value[i];
        dp[i][i] = value[i];
        add[i] = add[i - 1] + value[i];
    }
    for (l = 2; l <= n; l++)
    {
        for (i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            for (k = i + 1; k < j; k++)
                dp[i][j] = max(dp[i][j], (dp[i][k - 1] + dp[i][k + 1]) * value[k]);
        }
    }
    cout << dp[1][n];
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}