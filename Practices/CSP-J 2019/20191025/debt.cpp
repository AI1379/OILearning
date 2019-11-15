#include <bits/stdc++.h>
#define DEBUG true
using namespace std;
map<int, int> lis;
int m, n;
long long ans;
int main()
{
    int i, j, a, b, c;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        lis[i] = 0;
    }
#if DEBUG
    for (j = 1; j <= n; j++)
        cout << lis[j] << ' ';
    cout << endl;
#endif
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        lis[a] -= c;
        lis[b] += c;
#if DEBUG
        for (j = 1; j <= n; j++)
            cout << lis[j] << ' ';
        cout << endl;
#endif
    }
    for (i = 1; i <= n; i++)
    {
        if (lis[i] > 0)
            ans += lis[i];
    }
    cout << ans;
    system("pause");
    return 0;
}