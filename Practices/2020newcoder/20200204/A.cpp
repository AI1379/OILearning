#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long m, n;
long long ans, tmp;
int main()
{
    cin >> n >> m;
    tmp = (((m - 2) > 0 ? (m - 2) : 0) * ((n - 1) > 0 ? (n - 1) : 0) % mod +
           ((m - 1) > 0 ? (m - 1) : 0) * ((n - 2) > 0 ? (n - 2) : 0) % mod) %
          mod;
    ans = 2 * tmp * ((m + n - 2) % mod) % mod;
    cout << ans;
    return 0;
}