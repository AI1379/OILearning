#include <bits/stdc++.h>
using namespace std;
int dfs(int n, int k, int dep, int last)
{
    if (k == 1)
        return 1;
    int res = 0;
    for (int i = last; i <= n / 2; i++)
        res += dfs(n - i, k - 1, dep + 1, i);
    return res;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int ans = dfs(n, k, 1, 1);
    cout << ans;
    system("pause");
    return 0;
}