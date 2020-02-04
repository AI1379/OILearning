#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long expect = 0, fact = 0, n, x, i;
    cin >> n;
    expect = (n + 1) * n / 2;
    for (i = 0; i < n - 1; i++)
    {
        cin >> x;
        fact += x;
    }
    cout << expect - fact;
    return 0;
}