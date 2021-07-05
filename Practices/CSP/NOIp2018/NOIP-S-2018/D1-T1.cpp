#include <bits/stdc++.h>
using namespace std;
int d[100010], n, ans = 0;
int main()
{
    int i;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> d[i];
    for (i = 2; i <= n; i++)
        if (d[i] > d[i - 1])
            ans += (d[i] - d[i - 1]);
    cout << ans + d[1];
    return 0;
}