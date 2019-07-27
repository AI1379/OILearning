#include <bits/stdc++.h>
using namespace std;
struct node
{
    int from;
    int to;
    int next;
    int weight;
};
struct ansds
{
    int num;
    int weight;
};
ansds ans[110];
node edge[5060];
int head[110], c[110], u, v, w, m, n, numofedge, tot;
bool vis[110], out[110];
queue<int> q;
bool cmp(ansds a, ansds b)
{
    return a.num < b.num;
}
int main()
{
    numofedge = 0;
    tot = 0;
    int i, h, t;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        head[i] = 0;
        out[i] = false;
        cin >> c[i] >> u;
        if (c[i])
        {
            q.push(i);
            vis[i] = true;
        }
        else
        {
            c[i] -= u;
            vis[i] = false;
        }
    }
    for (i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        numofedge++;
        edge[numofedge].to = v;
        edge[numofedge].from = u;
        edge[numofedge].weight = w;
        edge[numofedge].next = head[u];
        head[u] = numofedge;
        out[u] = true;
    }
    while (!q.empty())
    {
        h = q.front();
        q.pop();
        for (i = head[h]; i != 0; i = edge[i].next)
        {
            if (c[edge[i].from] <= 0)
                continue;
            t = edge[i].to;
            c[t] += (edge[i].weight * c[h]);
            if (!vis[t])
            {
                q.push(t);
                vis[t] = true;
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (c[i] && !out[i])
        {
            tot++;
            ans[tot].num = i;
            ans[tot].weight = c[i];
        }
    }
    if (tot == 0)
    {
        cout << "NULL" << endl;
        return 0;
    }
    sort(ans + 1, ans + tot + 1, cmp);
    for (i = 1; i <= tot; i++)
        if (ans[i].weight > 0)
            cout << ans[i].num << ' ' << ans[i].weight << endl;
    system("pause");
    return 0;
}