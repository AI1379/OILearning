#include <bits/stdc++.h>
using namespace std;
int n;
int seq[256];
int f[256][256];
int main()
{
    int len, i, j, k;
    int ans = 0;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> seq[i];
        f[i][i] = seq[i];
    }
    for (len = 2; len <= n; len++)
    {
        for (i = 1; i <= n - len + 1; i++)
        {
            j = i + len - 1;
            for (k = i; k < j; k++)
            {
                if (f[i][k] == f[k + 1][j] && f[i][k] != 0 && f[k + 1][j] != 0)
                {
                    f[i][j] = max(f[i][j], f[i][k] + 1);
                    ans = max(ans, f[i][j]);
                }
                //else
                //    f[i][j] = max(f[i][j], max(f[i][k], f[k + 1][j]));
            }
        }
    }
    //cout << f[1][n] << endl;
    cout << ans;
#ifdef DEBUG
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << f[i][j] << ' ';
        }
        cout << endl;
    }
    system("pause");
#endif
    return 0;
}