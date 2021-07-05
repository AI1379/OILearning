#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int to;
    int next;
};
vector<edge> edges;
int adj[100010];
int dis[2][100010];
int n, m, q;
inline void addEdge(int u, int v)
{
    edge tmp;
    tmp.to = v;
    tmp.next = adj[u];
    adj[u] = edges.size();
    edges.push_back(tmp);
}
void bfs()
{
    memset(dis, 0x7f, sizeof(dis));
    queue<pair<int, int> > q;
    q.push(make_pair(1, 0));
    int inf = dis[0][0];
    dis[0][1] = 0;
    while (!q.empty())
    {
        pair<int, int> now = q.front();
        int level = now.second + 1;
        for (int i = adj[now.first]; i != -1; i = edges[i].next)
        {
            if (dis[level % 2][edges[i].to] != inf)
                continue;
            dis[level % 2][edges[i].to] = level;
            q.push(make_pair(edges[i].to, level));
        }
        q.pop();
    }
}
int main()
{
    int i, x, y;
    memset(adj, -1, sizeof(adj));
    cin >> n >> m >> q;
    for (i = 1; i <= m; i++)
    {
        cin >> x >> y;
        addEdge(x, y);
        addEdge(y, x);
    }
    bfs();
#ifdef DEBUG
    cout << dis[0][0] << endl;
    for (i = 1; i <= n; i++)
        cout << dis[0][i] << ' ' << dis[1][i] << endl;
#endif
    for (i = 1; i <= q; i++)
    {
        cin >> x >> y;
        if (dis[y % 2][x] <= y && y % 2 == dis[y % 2][x] % 2 && dis[y % 2][x] != dis[0][0])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
#ifdef DEBUG
        if (dis[y % 2][x] >= y)
            cout << 1 << endl;
        if (y % 2 == dis[y % 2][x] % 2)
            cout << 2 << endl;
        if (dis[y % 2][x] != dis[0][0])
            cout << 3 << endl;
#endif
    }
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}