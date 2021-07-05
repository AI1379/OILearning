#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100010;
long long n, m, p1, p2, s1, s2;
long long c[MAXN];
long long xuan, kai, mind = 1 << 30;
int main()
{
    long long i;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> c[i];
    cin >> m >> p1 >> s1 >> s2;
    c[p1] += s1;
    xuan = 1, kai = 1;
    for (i = 1; i <= n; i++)
    {
        if (i < m)
            xuan += (c[i] * abs(m - i));
        else if (i > m)
            kai += (c[i] * abs(m - i));
    }
    long long x, y;
    for (i = 1; i <= n; i++)
    {
        x = xuan, y = kai;
        if (i < m)
            x += (s2 * abs(m - i));
        else if (i > m)
            y += (s2 * abs(m - i));
        if (mind > abs(x - y))
        {
            mind = abs(x - y);
            p2 = i;
        }
    }
    cout << p2;
    return 0;
}