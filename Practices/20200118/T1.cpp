#include <bits/stdc++.h>
using namespace std;
int O[1010], n, ans = 0;
int main()
{
    int i, j, pre = -1;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> O[i];
    }
    for (i = 0; i < n; i++)
    {
        if (O[i] > pre)
        {
            pre = O[i];
        }
        else
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}