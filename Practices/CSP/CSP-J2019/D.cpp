#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int to;
    int next;
};
vector<edge> edges;
int adj[100010];
int n, m, q;
inline void addEdge(int u, int v)
{
    edge tmp;
    tmp.to = v;
    tmp.next = adj[u];
    adj[u] = edges.size();
    edges.push_back(tmp);
}
struct request
{
    int num;
    int level;
};
request makeReq(int a, int l)
{
    request tmp;
    tmp.level = l;
    tmp.num = a;
    return tmp;
}
int main()
{
    cin >> n >> m >> q;
    int i, j, k;
    memset(adj, -1, sizeof(adj));
    for (i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    for (i = 0; i < q; i++)
    {
        queue<request> q;
        int a, l;
        cin >> a >> l;
        q.push(makeReq(a, l));
        while (!q.empty())
        {
            request now = q.front();
            if (now.level == 0)
                break;
            for (j = adj[now.num]; j != -1; j = edges[j].next)
                q.push(makeReq(edges[j].to, now.level - 1));
            q.pop();
        }
        while (!q.empty())
        {
            if (q.front().num == 1)
            {
                cout << "Yes" << endl;
                break;
            }
            q.pop();
        }
        if (q.empty())
            cout << "No" << endl;
    }
    return 0;
}