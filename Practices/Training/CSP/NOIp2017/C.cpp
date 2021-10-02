#include <bits/stdc++.h>
using namespace std;
const int MAXM = 101;
const int MAXN = 1001;
const long long INF = 1 << 30;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
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
    edges[numOfEdges].to = v, edges[numOfEdges].next = adj[u];
    adj[u] = numOfEdges;
    edges[numOfEdges].value = w;
}
bool vis[MAXN];
long long dis[MAXN];
void spfa(int s)
{
    memset(vis, false, sizeof(vis));
    for (long long i = 0; i < MAXN; i++)
        dis[i] = INF;
    queue<long long> q;
    q.push(s);
    vis[s] = true;
    dis[s] = 0;
    while (!q.empty())
    {
        long long head = q.front();
        q.pop();
        vis[head] = false;
        for (long long i = adj[head]; i != -1; i = edges[i].next)
        {
            long long to = edges[i].to;
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
int m, n;
int mp[2][MAXM][MAXM];
int main()
{
    int i, j, k, s, x, y, z;
    memset(mp, -1, sizeof(mp));
    cin >> m >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> x >> y >> z;
        mp[1][x][y] = z;
        mp[0][x][y] = i;
    }
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (mp[1][i][j] == -1)
                continue;
            for (k = 0; k < 4; k++)
            {
                x = i + dx[k], y = j + dy[k];
                if (x > 0 && x <= m && y > 0 && y <= m)
                {
                    if (mp[1][x][y] == mp[1][i][j])
                    {
                        addEdge(mp[0][x][y], mp[0][i][j], 0);
                        addEdge(mp[0][i][j], mp[0][x][y], 0);
                    }
                    else if (mp[1][x][y] == -1)
                    {
                        int a, b;
                        for (s = 0; s < 4; s++)
                        {
                            a = x + dx[s], b = y + dy[s];
                            if (a == i && b == j)
                                continue;
                            if (mp[1][a][b] == mp[1][i][j])
                            {
                                addEdge(mp[0][a][b], mp[0][i][j], 2);
                                addEdge(mp[0][i][j], mp[0][a][b], 2);
                            }
                            else if (mp[1][a][b] != mp[1][i][j] && mp[1][a][b] != -1)
                            {
                                addEdge(mp[0][a][b], mp[0][i][j], 3);
                                addEdge(mp[0][i][j], mp[0][a][b], 3);
                            }
                        }
                    }
                    else
                    {
                        addEdge(mp[0][x][y], mp[0][i][j], 1);
                        addEdge(mp[0][i][j], mp[0][x][y], 1);
                    }
                }
            }
        }
    }
    spfa(mp[0][1][1]);
    cout << (dis[mp[0][m][m]] == INF ? -1 : dis[mp[0][m][m]]);
    return 0;
}