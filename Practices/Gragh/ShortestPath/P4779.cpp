#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 100010
#define MAXM 200010
struct edge
{
    int to;
    int next;
    int value;
};
struct node
{
    int num;
    int weight;
};
edge edges[MAXM];
int m, n, s, adj[MAXN];
void addEdge(int u, int v, int w)
{
    m++;
    edges[m].to = v, edges[m].next = adj[u];
    adj[u] = m;
    edges[m].value = w;
}
bool vis[MAXN];
int dis[MAXN];
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
    dis[s] = 0;
    vis[s] = true;
    insertEdge(s, 0);
    while (heapSize > 0)
    {
        int now = heap[1].num;
        deleteEdge();
        if (vis[now])
            continue;
        vis[now] = true;
        for (int i = adj[now]; ~i; i = edges[i].next)
        {
            edge tmp = edges[i];
            if (!vis[now] && dis[tmp.to] > dis[now] + tmp.value)
            {
                dis[tmp.to] = dis[now] + tmp.value;
                insertEdge(tmp.to, dis[tmp.to]);
            }
        }
    }
}
int main()
{
    memset(dis, 0x7f, sizeof(dis));
    memset(vis, false,sizeof(vis));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        addEdge(x, y, z);
        addEdge(y, x, z);
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
    {
        if (i == s)
            continue;
        cout << dis[i] << ' ';
    }
    return 0;
}