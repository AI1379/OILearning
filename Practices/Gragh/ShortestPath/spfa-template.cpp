#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2510; //vertexs
const long long MAXM = 6210; //edges
const long long INF = 1 << 30;
struct edge
{
    long long to;
    long long next;
    long long value;
};
edge edges[MAXM];
long long numOfEdges = 0;
long long adj[MAXN];
void addEdge(long long u, long long v, long long w)
{
    numOfEdges++;
    edges[numOfEdges].to = v;
    edges[numOfEdges].next = adj[u]; //next edge
    adj[u] = numOfEdges;             //chain prev-star
    edges[numOfEdges].value = w;     //weight
}
bool vis[MAXN];
long long dis[MAXN];
long long n, m, s, t;
void spfa()
{
    memset(vis, false, sizeof(vis));
    for (long long i = 0; i < MAXN; i++)
        dis[i] = INF;
    queue<long long> q;
    q.push(s);
    vis[s] = true; //in queue
    dis[s] = 0;
    while (!q.empty())
    {
        long long head = q.front();
        q.pop();
        vis[head] = false;                                        //pop it
        for (long long i = adj[head]; i != -1; i = edges[i].next) //search every edge
        {
            long long to = edges[i].to;
            if (dis[to] > dis[head] + edges[i].value)
            {
                dis[to] = dis[head] + edges[i].value; //relax
                if (!vis[to])                         //not in queue, then push it
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
    long long x, y, z;
    cin >> n >> m >> s >> t;
    memset(adj, -1, sizeof(adj));
    for (long long i = 1; i <= m; i++)
    {
        cin >> x >> y >> z;
        addEdge(x, y, z);
    }
    spfa();
    cout << dis[t];
    return 0;
}