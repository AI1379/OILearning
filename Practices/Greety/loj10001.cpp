#include <bits/stdc++.h>
using namespace std;
struct area
{
    int b, e, t;
};
bool cmp(area A, area B)
{
    return A.e < B.e;
}
area lst[5000];
bool vis[30001];
int n, h;
int main()
{
    int i, j, cnt, ans = 0;
    memset(vis, false, sizeof(vis));
    cin >> n >> h;
    for (i = 0; i < h; i++)
    {
        cin >> lst[i].b >> lst[i].e >> lst[i].t;
    }
    sort(lst, lst + h, cmp);
    for (i = 0; i < h; i++)
    {
        cnt = 0;
        for (j = lst[i].b; j <= lst[i].e; j++)
        {
            if (vis[j])
                cnt++;
        }
        for (j = lst[i].e; cnt < lst[i].t && j >= lst[i].b; j--)
        {
            if (!vis[j])
            {
                vis[j] = true;
                ans++;
                cnt++;
            }
        }
    }
    cout << ans;
#ifdef DEBUG
    system("pause");
#endif // DEBUG
    return 0;
}