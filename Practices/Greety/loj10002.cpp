#include <bits/stdc++.h>
using namespace std;
struct area
{
    int a, b;
};
int T, n, l, w;
area lst[10000];
bool cmp(area A, area B)
{
    return A.a < B.a;
}
int main()
{
    int i, k, o, r, ans, tmp;
    cin >> T;
    for (k = 0; k < T; k++)
    {
        ans = 0;
        cin >> n >> l >> w;
        for (i = 0; i < n; i++)
        {
            cin >> o >> r;
            lst[i].a = o - r;
            lst[i].b = o + r;
        }
        sort(lst, lst + n, cmp);
        while (l < w)
        {
            tmp = 0;
            for (i = 0; i < n; i++)
            {
                if (lst[i].a <= l && l <= lst[i].b)
                {
                    tmp = max(tmp, lst[i].b);
                }
            }
            l = tmp;
            ans++;
        }
        cout << ans << endl;
    }
#ifdef DEBUG
    system("pause");
#endif // DEBUG
    return 0;
}