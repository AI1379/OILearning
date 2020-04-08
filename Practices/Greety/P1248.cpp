#include <bits/stdc++.h>
using namespace std;
struct product
{
    int a, b;
};
product lst[1000];
bool vis[1000];
int n;
int q[1000];
int main()
{
    int ka, kb, i, j, mina, minb, l, r, ta = 0, tb = 0, ans;
    memset(vis, false, sizeof(vis));
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> lst[i].a;
    }
    for (i = 0; i < n; i++)
    {
        cin >> lst[i].b;
    }
    l = 0;
    r = n - 1;
    for (i = 0; i < n; i++)
    {
        mina = 1 << 30;
        minb = 1 << 30;
        for (j = 0; j < n; j++)
        {
            if (lst[j].a < mina && !vis[j])
            {
                ka = j;
                mina = lst[j].a;
            }
            if (lst[j].b < minb && !vis[j])
            {
                kb = j;
                minb = lst[j].b;
            }
        }
        if (mina < minb)
        {
            q[l++] = ka;
            vis[ka] = true;
        }
        else
        {
            q[r--] = kb;
            vis[kb] = true;
        }
    }
    for (i = 0; i <= n; i++)
    {
        if (i < n)
            ta += lst[q[i]].a;
        if (i > 0)
            tb = max(tb + lst[q[i - 1]].b, ta);
        else
            tb = ta;
    }
    ans = max(ta, tb);
    cout << ans << endl;
    for (i = 0; i < n; i++)
    {
        cout << q[i] + 1 << ' ';
    }
#ifdef DEBUG
    system("pause");
#endif // DEBUG
    return 0;
}