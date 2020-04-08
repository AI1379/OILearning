#include <bits/stdc++.h>
using namespace std;
struct product
{
    int a, b;
    int index;
};
bool cmp(product x, product y)
{
    return x.a + max(y.a, x.b) + y.b < y.a + max(x.a, y.b) + x.b;
}
product lst[1000];
int n, ans = 0;
int main()
{
    int i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        lst[i].index = i;
        cin >> lst[i].a;
    }
    for (i = 0; i < n; i++)
    {
        cin >> lst[i].b;
    }
    sort(lst, lst + n, cmp);
    ans = lst[0].a;
    for (i = 1; i < n; i++)
    {
        ans += max(lst[i].a, lst[i - 1].b);
    }
    ans += lst[n - 1].b;
    cout << ans << endl;
    for (i = 0; i < n; i++)
    {
        cout << lst[i].index << ' ';
    }
    return 0;
}