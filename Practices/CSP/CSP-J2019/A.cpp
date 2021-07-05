//luogu P5660

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int len = s.length();
    int ans = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '1')
            ans++;
    }
    cout << ans;
    return 0;
}