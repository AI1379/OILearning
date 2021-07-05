#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20010;
int l[MAXN], r[MAXN];
int n;
int f[MAXN][2];
int main()
{
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    memset(f, 0x3f, sizeof(f));
    f[1][0] = r[1] - 1 + r[1] - l[1];
    f[1][1] = r[1] - 1;
    for (i = 2; i <= n; i++)
    {
        f[i][0] = min(f[i - 1][0] + abs(l[i - 1] - r[i]) + 1 + r[i] - l[i], f[i - 1][1] + abs(r[i - 1] - r[i]) + 1 + r[i] - l[i]);
        f[i][1] = min(f[i - 1][0] + abs(l[i - 1] - l[i]) + 1 + r[i] - l[i], f[i - 1][1] + abs(r[i - 1] - l[i]) + 1 + r[i] - l[i]);
    }
    cout << min(f[n][0] + abs(n - l[n]), f[n][1] + abs(n - r[n])) << endl;
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}