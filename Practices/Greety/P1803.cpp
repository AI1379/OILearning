#include <bits/stdc++.h>
using namespace std;
struct comptition
{
    int l, r;
};
comptition lst[1000000];
bool cmp(comptition a, comptition b)
{
    if (a.r == b.r)
    {
        return a.l < b.l;
    }
    return a.r < b.r;
}
int n, ans = 0;
int main()
{
    comptition tmp;
    int i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> lst[i].l >> lst[i].r;
    }
    sort(lst, lst + n, cmp);
#ifdef DEBUG
    for (i = 0; i < n; i++)
    {
        printf("(%d, %d)\n", lst[i].l, lst[i].r);
    }
#endif // DEBUG
    tmp = lst[0];
    ans++;
    for (i = 1; i < n; i++)
    {
        if (lst[i].l >= tmp.r)
        {
            tmp = lst[i];
            ans++;
        }
    }
    cout << ans;
#ifdef DEBUG
    system("pause");
#endif // DEBUG
    return 0;
}