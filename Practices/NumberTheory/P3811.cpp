#include <bits/stdc++.h>
using namespace std;
long long inv[20000529];
int gcd(const int x, const int y)
{
    int a = x, b = y, r;
    if (a < b)
    {
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    while (1)
    {
        r = a % b;
        if (r == 0)
            return b;
        else
            a = b, b = r;
    }
    return 1;
}
int main()
{
    int i, n, p;
    inv[1] = 1;
    cin >> n >> p;
    for (i = 2; i <= n; ++i)
    {
        inv[i] = (long long)(p - p / i) * inv[p % i] % p;
    }
    cout << inv[n];
    return 0;
}