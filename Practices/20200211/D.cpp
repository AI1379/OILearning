#include <bits/stdc++.h>
using namespace std;
int xorlst[200001], a[200001];
int n, maxx = 0;
map<int, int> bucket;
long long ans = 0;
int main()
{
    cin >> n;
    xorlst[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        xorlst[i] = a[i] ^ xorlst[i - 1];
        bucket[xorlst[i]]++;
        if (xorlst[i] == 0)
            ans++;
        maxx = max(maxx, xorlst[i]);
    }
    for (int i = 0; i <= maxx; i++)
    {
        ans += ((bucket[i] * (bucket[i] - 1)) / 2);
    }
    cout << ans;
    return 0;
}