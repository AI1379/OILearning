#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int len, nol = 0, ans, tmp;
int pos[2][100001];
int main()
{
    string s;
    int i, j;
    cin >> len >> s;
    for (i = 0; i < len; i++)
    {
        if (s[i] == '1')
        {
            pos[1][nol++] = i;
        }
    }
    tmp = nol;
    for (i = 1; i < nol; i++)
    {
        for (j = 1; j < tmp; j++)
        {
            ans = (ans + pos[i % 2][j] - pos[i % 2][0]) % mod;
            pos[(i + 1) % 2][j - 1] = pos[i % 2][j] - pos[i % 2][0];
        }
        tmp--;
    }
    cout << ans;
    return 0;
}