#include <bits/stdc++.h>
using namespace std;
#define MAXN 10010
#define MAXM 100010
vector<int> mp[MAXN];
int size[MAXN];
int n, m;
int color[MAXN];
bool DFS(int u)
{
    int numOfEdges = mp[u].size();
    for (int i = 0; i < numOfEdges; i++)
    {
        int v = mp[u][i];
        if (color[v] == color[u])
            return false;
        if (color[v] == -1)
        {
            color[v] = !color[u];
            if (!DFS(v))
                return false;
        }
    }
    return true;
}
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int i;
    cin >> n >> m;
    for (i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    for (i = 1; i <= n; i++)
    {
        memset(color, -1, sizeof(color));
        color[i] = 0;
        if (!DFS(i))
        {
            cout << "Impossible";
            return 0;
        }
    }
    for (i = 1; i <= n; i++)
        size[i] = mp[i].size();
    sort(size + 1, size + n + 1, cmp);
#ifdef DEBUG
    for (i = 0; i <= n; i++)
        cout << size[i] << ' ';
    cout << endl;
#endif
    i = 0;
    int tmp = 0;
    while (tmp < m)
        tmp += size[++i];
    cout << i;
    return 0;
}