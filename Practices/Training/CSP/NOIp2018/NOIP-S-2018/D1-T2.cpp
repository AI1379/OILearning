#include <bits/stdc++.h>
using namespace std;
int n, t;
int a[110];
bool vis[25010][110], f[25010][110];
bool dfs(int num, int black)
{
    if (vis[num][black])
        return f[num][black];
    for (int i = 1; i <= n; i++)
    {
        if (num % a[i] == 0 && i != black)
        {
            vis[a[i]][black] = true;
            f[a[i]][black] = true;
            return true;
        }
    }
    bool res = false;
    for (int i = 1; i < num && !res; i++)
        res = res || (dfs(i, black) && dfs(num - i, black));
    vis[num][black] = true;
    f[num][black] = res;
    return res;
}
int main()
{
    int i;
    cin >> t;
#ifndef DEBUG
    //freopen("money.in", "r", stdin);
    //freopen("money.out", "w", stdout);
#endif
    while (t--)
    {
        memset(a, false, sizeof(a));
        memset(vis, false, sizeof(vis));
        memset(f, false, sizeof(f));
        cin >> n;
        for (i = 1; i <= n; i++)
            cin >> a[i];
        int ans = n;
        for (i = 1; i <= n; i++)
            if (dfs(a[i], i))
                ans--;
        cout << ans << endl;
    }
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}