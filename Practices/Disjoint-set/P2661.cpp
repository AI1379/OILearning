#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
int fa[MAXN], dis[MAXN], n, ans = 214748364;
int find(int x)
{
    if (fa[x] != x)
    {
        int tmp = fa[x];
        fa[x] = find(fa[x]);
        dis[x] += dis[tmp];
    }
    return fa[x];
}
void add(int a, int b)
{
    int u = find(a), v = find(b);
    if (u != v)
        fa[u] = v, dis[a] = dis[b] + 1;
    else
        ans = min(ans, dis[a] + dis[b] + 1);
    return;
}
int main()
{
    int i, x;
    cin >> n;
    for (i = 1; i <= n; i++)
        fa[i] = i;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        add(i, x);
    }
    cout << ans;
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}