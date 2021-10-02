#include <bits/stdc++.h>
using namespace std;
int n, m, l;
int d[50010];
bool check(int value)
{
    int cnt = 0, i, now = 0;
    for (i = 1; i <= n; i++)
        if (d[i] - d[now] < value)
            cnt++;
        else
            now = i;
    return cnt <= m;
}
int main()
{
    int i;
    cin >> l >> n >> m;
    if (n == 0 || m == 0)
    {
        cout << l;
        return 0;
    }
    for (i = 1; i <= n; i++)
        cin >> d[i];
    d[n + 1] = l;
    int left = 1, right = l, mid, ans;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (check(mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
#ifdef DEBUG
        cout << mid << endl;
#endif
    }
    cout << ans;
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}