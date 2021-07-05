#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int e = 1e3 + 5;
int s[e][e], n, m, ans, ru[e], vis[e], tot, pd[e][e];
queue<pii> q;
vector<int> g[e];
inline int getint()
{
    char ch;
    int res = 0;
    while (ch = getchar(), ch < '0' || ch > '9')
        ;
    res = ch - 48;
    while (ch = getchar(), ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + ch - 48;
    return res;
}
inline void bfs()
{
    int i;
    for (i = 1; i <= n; i++)
        if (ru[i] == 0)
            q.push(make_pair(i, 1));
    ans = 1;
    while (!q.empty())
    {
        int u = q.front().first, val = q.front().second;
        q.pop();
        for (i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i];
            ru[v]--;
            if (ru[v] == 0)
            {
                q.push(make_pair(v, val + 1));
                ans = max(ans, val + 1);
            }
        }
    }
}
int main()
{
    int i, j, x;
    n = getint();
    m = getint();
    for (i = 1; i <= m; i++)
    {
        s[i][0] = getint();
        memset(vis, false, sizeof(vis));
        for (j = 1; j <= s[i][0]; j++)
        {
            x = getint();
            s[i][j] = x;
            vis[x] = true;
        }
        for (j = s[i][1]; j <= s[i][s[i][0]]; j++)
        {
            if (vis[j])
                continue;
            for (int k = 1; k <= s[i][0]; k++)
                if (!pd[j][s[i][k]])
                {
                    ru[s[i][k]]++;
                    g[j].push_back(s[i][k]);
                    pd[j][s[i][k]] = true;
                }
        }
    }
    bfs();
    cout << ans << endl;
    return 0;
}