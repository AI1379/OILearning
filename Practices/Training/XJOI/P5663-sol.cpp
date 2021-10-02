#include <bits/stdc++.h>
using namespace std;
int n, m, c, head[1000005], cnt, dis[1000005][2];
bool vis[1000005][2];
struct node
{
    int data, dis;
    bool operator<(const node &a) const
    {
        return a.dis < dis;
    }
};
priority_queue<node> q;
struct Edge
{
    int to, next;
} e[1000005];

void add(int u, int v)
{
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
void Initialization()
{
    memset(dis, 0x3f, sizeof(dis));
    q.push((node){1, 0});
    dis[1][0] = 0;
}
void dijkstra()
{
    while (!q.empty())
    {
        node tmp = q.top();
        q.pop();
        int now = tmp.data;
        for (int i = head[now]; i; i = e[i].next)
        {
            int y = e[i].to;
            if (dis[y][0] > dis[now][1] + 1)
            {
                dis[y][0] = dis[now][1] + 1;
                if (!vis[y][0])
                {
                    vis[y][0] = 1;
                    q.push((node){y, dis[y][0]});
                }
            }
            if (dis[y][1] > dis[now][0] + 1)
            {
                dis[y][1] = dis[now][0] + 1;
                if (!vis[y][1])
                {
                    vis[y][1] = 1;
                    q.push((node){y, dis[y][1]});
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m >> c;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    Initialization();
    dijkstra();
    while (c--)
    {
        int a, l;
        cin >> a >> l;
        if (!head[1])
            puts("No");
        else if (dis[a][l % 2] <= l)
            puts("Yes");
        else
            puts("No");
    }
}
