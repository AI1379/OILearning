//石子合并
#include <bits/stdc++.h>
using namespace std;
int n;
int a[300];
int f_min[300][300];
int f_max[300][300];
int sum[300];
int minf, maxf;
int main()
{
    int i, j, k, l;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[n + i] = a[i];
    }
    for (i = 1; i <= 2 * n; i++)
        sum[i] = a[i] + sum[i - 1];
    for (l = 2; l <= n; l++)
    {
        for (i = 1; i <= 2 * n - l + 1; i++)
        {
            j = i + l - 1;
            minf = 1 << 30;
            for (k = i; k < j; k++)
            {
                minf = min(minf, f_min[i][k] + f_min[k + 1][j] + sum[j] - sum[i - 1]);
                f_max[i][j] = max(f_max[i][j], f_max[i][k] + f_max[k + 1][j] + sum[j] - sum[i - 1]);
            }
            f_min[i][j] = minf;
        }
    }
    minf = 1 << 30;
    for (i = 1; i <= n; i++)
    {
        maxf = max(maxf, f_max[i][i + n - 1]);
        minf = min(minf, f_min[i][i + n - 1]);
    }
    cout << minf << endl
         << maxf;
    return 0;
}