#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10010;
bool mp[MAXN][MAXN];
bool vis[MAXN];
bool co[MAXN], ava[MAXN];
int n, m, s, t;
inline int read()
{
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
int main()
{
    int i, j, x, y;
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    n = read();
    m = read();
    memset(mp, false, sizeof(mp));
    memset(co, false, sizeof(co));
    memset(ava, false, sizeof(ava));
    memset(vis, false, sizeof(vis));
    for (i = 1; i <= m; i++)
    {
        x = read();
        y = read();
        mp[x][y] = true;
    }
    s = read();
    t = read();
    co[t] = true;
    queue<int> q1;
    q1.push(t);
    while (!q1.empty())
    {
        for (i = 1; i <= n; i++)
        {
            if (mp[i][q1.front()] && !vis[i])
            {
                co[i] = true;
                q1.push(i);
                vis[i] = true;
            }
        }
        q1.pop();
    }
    memset(vis, false, sizeof(vis));
#ifdef DEBUG
    for (i = 1; i <= n; i++)
        cout << co[i] << ' ';
    cout << endl;
#endif
    for (i = 1; i <= n; i++)
    {
        ava[i] = co[i];
        for (j = 1; j <= n; j++)
        {
            if (mp[i][j])
                ava[i] &= co[j];
        }
    }
#ifdef DEBUG
    for (i = 1; i <= n; i++)
        cout << ava[i] << ' ';
    cout << endl;
#endif
    typedef pair<int, int> pii;
    queue<pii> q2;
    q2.push(make_pair(s, 0));
    int ans = -1;
    while (!q2.empty())
    {
        bool flag = false;
        for (i = 1; i <= n; i++)
        {
            if (i != q2.front().first && !vis[i] && ava[i] && mp[q2.front().first][i])
            {
                q2.push(make_pair(i, q2.front().second + 1));
                flag = true;
                vis[i] = true;
            }
        }
        q2.pop();
        //if (flag)
        ans = max(ans, q2.front().second);
#ifdef DEBUG
        if (flag)
            cout << q2.front().first << ' ';
#endif
    }
    cout << ans;
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}