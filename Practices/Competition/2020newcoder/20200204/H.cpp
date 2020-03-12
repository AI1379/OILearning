#include <bits/stdc++.h>
using namespace std;
vector<int> zero;
vector<int> one;
string s;
int n, k, ans = 0;
int main()
{
    int i, j;
    cin >> n >> k >> s;
    zero.push_back(-1);
    one.push_back(-1);
    for (i = 0; i < n; i++)
    {
        if (s[i] == '0')
            zero.push_back(i);
        else
            one.push_back(i);
    }
    zero.push_back(n);
    one.push_back(n);
    if (zero.size() - 2 <= k)
        ans = n;
    else
    {
        for (i = 0, j = k; j < zero.size() - 1; i++, j++)
        {
            ans = max(ans, zero[j + 1] - zero[i - 1] - 1);
        }
    }
    if (one.size() - 2 <= k)
        ans = n;
    else
    {
        for (i = 0, j = k; j < one.size() - 1; i++, j++)
        {
            ans = max(ans, one[j + 1] - one[i - 1] - 1);
        }
    }
    cout << ans;
    return 0;
}