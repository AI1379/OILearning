#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2510;
const long long MAXM = 6210;
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
struct node
{
    long long num;    //pos of vertex
    long long weight; //edge weight
    bool operator<(const node A) const
    {
        return weight > A.weight;
    }
};
node makeNode(long long x, long long y)
{
    node tmp;
    tmp.num = x, tmp.weight = y;
    return tmp;
}
long long m, n, s, t;
long long inf;
long long dis[MAXN];
void dijkstra()
{
    priority_queue<node> q;
    q.push(makeNode(s, 0));
    dis[s] = 0;
    while (!q.empty())
    {
        long long head = q.top().num, to;
        q.pop();
        for (long long j = adj[head]; j != -1; j = edges[j].next)
        {
            to = edges[j].to;
            if (dis[to] > dis[head] + edges[j].value)
            {
                dis[to] = dis[head] + edges[j].value; //relax
                q.push(makeNode(to, dis[to]));        //push it into priority queue
            }
        }
    }
}
int main()
{
    long long i, x, y, z;
    memset(dis, 0x7f, sizeof(dis));
    memset(adj, -1, sizeof(adj));
    inf = dis[0];
    cin >> n >> m >> s >> t;
    for (i = 1; i <= m; i++)
    {
        cin >> x >> y >> z;
        addEdge(x, y, z);
    }
    dijkstra();
    cout << dis[t];
    return 0;
}