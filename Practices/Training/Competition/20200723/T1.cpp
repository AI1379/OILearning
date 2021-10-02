#include <bits/stdc++.h>
using namespace std;
const long long inf = 1 << 30;
long long t, n, p;
vector<long long> a, s;
int main()
{
#ifndef DEBUG
    std::ios::sync_with_stdio(false);
#endif
    long long k, i, j, maxa, x, ans;
    bool flag;
    cin >> t;
    while (t--)
    {
        ans = inf;
        maxa = 0;
        a.clear();
        s.clear();
        flag = false;
        cin >> n >> p;
        a.push_back(0);
        s.push_back(0);
        for (i = 1; i <= n; i++)
        {
            cin >> x;
            if (x == p)
                x = 0;
            maxa = max(x, maxa);
            if (x <= p)
                flag = true;
            a.push_back(x);
        }
        if (!flag)
        {
            ans = 0;
            for (i = 1; i <= n; i++)
                ans += (maxa - a[i]);
        }
        else if (maxa > p)
        {
            cout << "-1" << endl;
            continue;
        }
        sort(a.begin(), a.end());
        for (i = 1; i <= n; i++)
            s.push_back(a[i] + s[i - 1]);
        for (i = 1; i <= n; i++)
        {
            k = (((i - 1) * a[i] - s[i - 1]) + ((n - i) * (a[i] + p) - (s[n] - s[i])));
            ans = min(ans, k);
        }
        cout << ans << endl;
    }
    return 0;
}