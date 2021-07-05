#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool vis[20010][20010];
bool mark(int x, int y)
{
    if (1 <= x && x <= n && 1 <= y && y <= m)
    {
        vis[x][y] = true;
        return true;
    }
    return false;
}
int main()
{
    int i, j, x, y;
    cin >> n >> m >> k;
    memset(vis, false, sizeof(vis));
    for (i = 0; i < k; i++)
    {
        cin >> x >> y;
        vis[x][y] = true;
        for (j = 1; j <= n; j++)
            vis[x][j] = true;
        for (j = 1; j <= m; j++)
            vis[j][y] = true;
        int tmpX=x,tmpY=y;
    }
}