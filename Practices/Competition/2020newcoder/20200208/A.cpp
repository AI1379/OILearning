#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long ans = 0;
char mp[55][55];
int m, n;
void dfs(int x, int y)
{
    if (x > n || y > m)
        return;
    if (x == n && y == m)
    {
        ans = (ans + 1) % mod;
        return;
    }
    switch (mp[x][y])
    {
    case 'R':
        dfs(x + 1, y);
        break;
    case 'D':
        dfs(x, y + 1);
        break;
    case 'B':
        dfs(x + 1, y);
        dfs(x, y + 1);
        break;
    default:
        break;
    }
    return;
}
int main()
{
    int i, j;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        getchar();
        for (j = 1; j <= m; j++)
        {
            mp[i][j] = getchar();
        }
    }
    getchar();
    dfs(1, 1);
    cout << ans;
    return 0;
}