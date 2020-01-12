#include <bits/stdc++.h>
using namespace std;
long long f[76][10001];
int v, n;
int lst[26];
int main()
{
    int i, j;
    memset(f, 0, sizeof(f));
    cin >> v >> n;
    for (i = 1; i <= v; i++)
    {
        cin >> lst[i];
    }
    for (i = 1; i <= v; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (j < lst[i])
            {
                f[i][j] = f[i - 1][j];
            }
            else if (j == lst[i])
            {
                f[i][j] = f[i - 1][j] + 1;
            }
            else
            {
                f[i][j] = f[i - 1][j] + f[i][j - lst[i]];
            }
        }
    }
    cout << f[v][n];
    system("pause");
    return 0;
}