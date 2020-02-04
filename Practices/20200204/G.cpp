#include <bits/stdc++.h>
using namespace std;
bool ansexist = false;
int n, k, ans = 1 << 30;
vector<int> lst[26];
int main()
{
    string s;
    int i, j, tmp;
    cin >> n >> k;
    cin >> s;
    for (i = 0; i < n; i++)
    {
        lst[(int)(s[i]) - (int)('a')].push_back(i);
    }
    for (i = 0; i < 26; i++)
    {
        if (lst[i].size() >= k)
        {
            ansexist = true;
            tmp = lst[i].size();
            for (j = 0; j + k - 1 < tmp; j++)
            {
                ans = min(ans, lst[i][j + k - 1] - lst[i][j] + 1);
            }
        }
    }
    if (!ansexist)
        cout << "-1";
    else
        cout << ans;
    return 0;
}