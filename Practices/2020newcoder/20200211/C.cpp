#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int a[200001];
int n, k, ans = 1, tmp;
int main()
{
    int i;
    cin >> n >> k;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i <= k)
            ans = (ans * a[i]) % mod;
    }
    for (i = k + 1; i <= n; i++)
    {
        if (a[i - k] == 0)
        {
            tmp = 1;
            for (int j = i - k + 1; j <= i; j++)
            {
                tmp = (tmp * a[i]) % mod;
            }
        }
        else
        {
            tmp = tmp / a[i - k] * a[i] % mod;
        }
        ans = max(ans, tmp);
    }
    cout << ans;
    return 0;
}