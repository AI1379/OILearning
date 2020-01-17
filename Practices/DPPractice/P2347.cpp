#include <bits/stdc++.h>
using namespace std;
const int w[7] = {0, 1, 2, 3, 5, 10, 20};
int a[7], maxf[7];
bool f[7][1001];
int ans = 0;
int main()
{
    int i, j, k;
    memset(f, false, sizeof(f));
    memset(maxf, 0, sizeof(maxf));
    for (i = 1; i <= 6; i++){
        cin >> a[i];
        maxf[i]=maxf[i-1]+a[i]*w[i];
    }
    for (i = 1; i <= 6; i++)
    {
        for (j = 0; j <= a[i]; j++)
        {
            f[i][j * w[i]] = true;
            for (k = 1; k <= maxf[i - 1]; k++)
            {
                if (f[i - 1][k])
                {
                    f[i][j * w[i] + k] = true;
                }
            }
        }
    }
    for (i = 1; i <= maxf[6]; i++)
    {
        if (f[6][i])
            ans++;
    }
    cout << "Total=" << ans;
    system("pause");
    return 0;
}