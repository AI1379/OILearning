#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
#define MAXM 400010
struct edge
{
    long long to;
    long long next;
    long long value;
};
struct node
{
    long long num;
    long long weight;
    bool operator<(const node A) const
    {
        return weight > A.weight;
    }
};
edge edges[MAXM];
long long m, n, s, adj[MAXN], numOfEdges = 0;
void addEdge(long long u, long long v, long long w)
{
    numOfEdges++;
    edges[numOfEdges].to = v, edges[numOfEdges].next = adj[u];
    adj[u] = numOfEdges;
    edges[numOfEdges].value = w;
}
bool vis[MAXN];
long long dis[MAXN];
priority_queue<node> Q;
void dijkstra()
{
    memset(dis, 0x7f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    dis[s] = 0;
    node tmp;
    Q.push((node){s, 0});
    while (!Q.empty())
    {
        long long now = Q.top().num;
        Q.pop();
        if (vis[now])
            continue;
        vis[now] = true;
        for (long long i = adj[now]; i != -1; i = edges[i].next)
        {
            long long to = edges[i].to;
            if (!vis[to] && dis[to] > dis[now] + edges[i].value)
            {
                dis[to] = dis[now] + edges[i].value;
                Q.push((node){to, dis[to]});
            }
        }
    }
}
int main()
{
    long long i;
#ifndef DEBUG
    ios::sync_with_stdio(false);
#endif
    memset(adj, -1, sizeof(adj));
    cin >> n >> m >> s;
    for (i = 1; i <= m; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    dijkstra();
    for (i = 1; i <= n; i++)
        cout << (dis[i] > 2000000000 ? 2147483647 : dis[i]) << ' ';
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}