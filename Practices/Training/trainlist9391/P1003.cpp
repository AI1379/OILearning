#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int mp[maxn][maxn];
int n;
int main()
{
    int i, j, k, a, b, x, y;
    memset(mp, -1, sizeof(mp));
    cin >> n;
    for (k = 1; k <= n; k++)
    {
        cin >> a >> b >> x >> y;
        for (i = 0; i <= x; i++)
            for (j = 0; j <= y; j++)
                mp[a + i][b + j] = k;
    }
    cin >> x >> y;
    cout << mp[x][y];
    return 0;
}   