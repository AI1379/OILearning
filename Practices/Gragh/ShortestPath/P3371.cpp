#include <bits/stdc++.h>
using namespace std;
#define MAXN 400010
#define MAXM 1000010
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
node heap[MAXM];
int heapSize = 0;
void mySwap(node &a, node &b)
{
    node tmp;
    tmp = a, a = b, b = tmp;
}
void insertEdge(int number, int weight)
{
    node tmp = {number, weight};
    heapSize++;
    heap[heapSize] = tmp;
    int now = heapSize;
    while (now / 2 && heap[now / 2].weight > heap[now].weight)
    {
        mySwap(heap[now / 2], heap[now]);
        now = now << 1;
    }
}
void deleteEdge()
{
    heap[1] = heap[heapSize];
    heapSize--;
    int now = 1;
    while (2 * now <= heapSize)
    {
        int tmp = 2 * now;
        if (tmp + 1 <= heapSize && heap[tmp].weight > heap[tmp + 1].weight)
            tmp++;
        if (heap[now].weight > heap[tmp].weight)
        {
            mySwap(heap[now], heap[tmp]);
            now = tmp;
        }
        else
            break;
    }
}
void dijkstra()
{
    memset(dis, 0x7f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    dis[s] = 0;
    node tmp;
    insertEdge(s, 0);
    while (heapSize != 0)
    {
        long long now = heap[1].num;
        deleteEdge();
        if (vis[now])
            continue;
        vis[now] = true;
        for (long long i = adj[now]; i != -1; i = edges[i].next)
        {
            long long to = edges[i].to;
            if (!vis[to] && dis[to] > dis[now] + edges[i].value)
            {
                dis[to] = dis[now] + edges[i].value;
                insertEdge(to, dis[to]);
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
    }
    dijkstra();
    for (i = 1; i <= n; i++)
        cout << (dis[i] > 2000000000 ? 2147483647 : dis[i]) << ' ';
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}