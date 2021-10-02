#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
struct edge
{
    int value;
    int column;
    bool flag; //true:a[] false:b[]
};
bool cmp(edge a, edge b) { return a.value > b.value; }
int fa[MAXN];
int n, m;
int ans = 0;
vector<edge> edges;
bool find(int x)
{
    if (fa[x] == x)
        return x;
    fa[x] = find(x);
    return fa[x];
}
int main()
{
    int i, j, x;
    cin >> n >> m;
    edges.push_back({-1, -1, false});
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        edge tmp;
        tmp.value = x;
        tmp.column = i;
        tmp.flag = true;
        edges.push_back(tmp);
    }
    for (i = 1; i <= m; i++)
    {
        cin >> x;
        edge tmp;
        tmp.value = x;
        tmp.column = i;
        tmp.flag = false;
        edges.push_back(tmp);
    }
#ifdef DEBUG
    for (auto &i : edges)
        cout << i.value << ' ' << i.column << ' ' << i.flag << endl;
    cout << endl;
#endif
    sort(edges.begin() + 1, edges.end(), cmp);
#ifdef DEBUG
    for (auto &i : edges)
        cout << i.value << ' ' << i.column << ' ' << i.flag << endl;
    cout << endl;
#endif
    for (i = 0; i < MAXN; i++)
        fa[i] = i;
    for (i = 1; i < edges.size(); i++)
    {
        if (edges[i].flag)
        {
            for (j = 1; j < m; j++)
            {
                int a = m * (edges[i].column - 1) + j;
                int b = a + 1;
                if (find(a) == find(b))
                    continue;
                fa[find(a)] = find(b);
                ans += edges[i].value;
            }
        }
        else
        {
            for (j = 1; j < n; j++)
            {
                int a = m * (j - 1) + edges[i].column;
                int b = m * j + edges[i].column;
                if (find(a) == find(b))
                    continue;
                fa[find(a)] = find(b);
                ans += edges[i].value;
                
            }
        }
    }
    cout << ans;
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}