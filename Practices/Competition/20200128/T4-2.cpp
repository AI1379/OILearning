#include <bits/stdc++.h>
using namespace std;
int w[50010];
vector<vector<int> > arc;
vector<int> root;
bool roots[50000], leafs[50000];
int ans[50000];
int m, n;
void dfs(int s)
{
    int i, rst = w[s], num = arc[s].size();
    if (num == 0)
    {
        ans[s] = w[s];
        return;
    }
    for (i = 0; i < num; i++)
    {
        dfs(arc[s][i]);
        rst = max(rst, ans[arc[s][i]]);
    }
    ans[s] = rst;
    return;
}
int main()
{
    int i, x, y, q, sum;
    cin >> n >> m;
    arc.resize(n + 5);
    memset(roots, true, sizeof(roots));
    for (i = 1; i <= n; i++)
    {
        cin >> w[i];
        ans[i] = w[i];
    }
    for (i = 0; i < m; i++)
    {
        cin >> x >> y;
        roots[y] = false;
        arc[x].push_back(y);
    }
    for (i = 1; i <= n; i++)
    {
        if (roots[i])
        {
            root.push_back(i);
        }
    }
    sum = root.size();
    for (i = 0; i < sum; i++)
    {
        dfs(root[i]);
    }
    cin >> q;
    for (i = 0; i < q; i++)
    {
        cin >> x;
        cout << ans[x] << endl;
    }
    return 0;
}