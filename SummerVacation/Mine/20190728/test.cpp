#include <queue>
#include <cstdio>
#include <algorithm>
#define N 102
#define M N *N
using namespace std;
queue<int> q;
struct edge
{
    int to, val, from, next;
} e[M];
struct answ
{
    int num, val;
} ans[N];
int h, i, m, n, t, u, v, w, x, c[N], hd[N];
bool out[N], vis[N];
int cnt = 0, tot = 0;
bool cmp(answ aa, answ bb)
{
    return aa.num < bb.num;
}
void build(int u, int v, int w)
{
    cnt++;
    e[cnt].to = v;
    e[cnt].val = w;
    e[cnt].from = u;
    e[cnt].next = hd[u];
    hd[u] = cnt;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; ++i)
    {
        hd[i] = 0;
        out[i] = false;
        scanf("%d%d", &c[i], &x);
        if (c[i])
        {
            q.push(i);
            vis[i] = true;
        }
        else
        {
            c[i] -= x;
            vis[i] = false;
        }
    }
    for (i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        build(u, v, w);
        out[u] = true;
    }
    while (!q.empty())
    {
        h = q.front();
        q.pop();
        for (i = hd[h]; i; i = e[i].next)
        {
            if (c[e[i].from] <= 0)
                continue;
            t = e[i].to;
            c[t] += (e[i].val * c[h]);
            if (!vis[t])
            {
                q.push(t);
                vis[t] = true;
            }
        }
    }
    for (i = 1; i <= n; ++i)
        if (c[i] && !out[i])
        {
            tot++;
            ans[tot].num = i;
            ans[tot].val = c[i];
        }
    if (tot == 0)
    {
        printf("NULL");
        return 0;
    }
    sort(ans + 1, ans + tot + 1, cmp);
    for (i = 1; i <= tot; ++i)
        printf("%d %d\n", ans[i].num, ans[i].val);
    system("pause");
    return 0;
}