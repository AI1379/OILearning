#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10010;
const int MAXM = 500010;
const int INF = 2147483647;
struct edge
{
    int to;
    int next;
    int value;
};
edge edges[MAXM];
int numOfEdges = 0;
int adj[MAXN];
void addEdge(long long u, long long v, long long w)
{
    numOfEdges++;
    edges[numOfEdges].to = v, edges[numOfEdges].next = adj[u];
    adj[u] = numOfEdges;
    edges[numOfEdges].value = w;
}
bool vis[MAXN];
int dis[MAXN];
int n, m, s, t;
void spfa()
{
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < MAXN; i++)
        dis[i] = INF;
    queue<int> q;
    q.push(s);
    vis[s] = true;
    dis[s] = 0;
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        vis[head] = false;
        for (int i = adj[head]; i != -1; i = edges[i].next)
        {
            int to = edges[i].to;
            if (dis[to] > dis[head] + edges[i].value)
            {
                dis[to] = dis[head] + edges[i].value;
                if (!vis[to])
                {
                    q.push(to);
                    vis[to] = true;
                }
            }
        }
    }
}
int main()
{
    int x, y, z;
    cin >> n >> m >> s;
    memset(adj, -1, sizeof(adj));
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> z;
        addEdge(x, y, z);
    }
    spfa();
    for (int i = 1; i <= n; i++)
        cout << dis[i] << ' ';
    return 0;
}