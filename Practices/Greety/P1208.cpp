#include <bits/stdc++.h>
using namespace std;
struct farmer
{
    int p, a;
};
bool cmp(farmer a, farmer b)
{
    return a.p < b.p;
}
farmer lst[5000];
int m, n, ans = 0;
int main()
{
    int i;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> lst[i].p >> lst[i].a;
    }
    sort(lst, lst + m, cmp);
    for (i = 0; i < m; i++)
    {
        if (n < lst[i].a)
        {
            ans += lst[i].p * n;
            break;
        }
        n -= lst[i].a;
        ans += (lst[i].p * lst[i].a);
    }
    cout << ans;
    return 0;
}