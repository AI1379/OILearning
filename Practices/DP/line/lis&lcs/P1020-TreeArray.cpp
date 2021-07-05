#include <bits/stdc++.h>
using namespace std;
int n, a[100000], b[100000], sys[100000];
int main()
{
    int i, l, r, mid, ans = 0, ns = 0, x;
    n = 0;
    memset(b, 0, sizeof(b));
    b[0] = 0x7fffff;
    while (cin >> x)
    {
        a[n++] = x;
    }
    for (i = 0; i < n; i++)
    {
        l = 0;
        r = n;
        while (l < r)
        {
            mid = (l + r) >> 1;
            if (b[mid] < a[i])
                r = mid;
            else
                l = mid + 1;
        }
        b[r] = a[i];
    }
    for (i = 0; i < n; i++)
        if (b[i] != 0)
            ans++;
    ans--;
    cout << ans << endl;
    memset(sys, 0x7f, sizeof(sys));
    for (i = 0; i < n; i++)
    {
        l = 0;
        r = n;
        while (l < r)
        {
            mid = (l + r) >> 1;
            if (sys[mid] >= a[i])
                r = mid;
            else
                l = mid + 1;
        }
        if (r >= ns)
        {
            sys[ns] = a[i];
            ns++;
        }
        else
        {
            sys[r] = a[i];
        }
    }
    cout << ns;
    return 0;
}
