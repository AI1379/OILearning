#include <bits/stdc++.h>
using namespace std;
string s;
int i, len, cnt[10];
int main()
{
    cin >> len >> s;
    for (i = 0; i < len; i++)
    {
        cnt[s[i] - '0']++;
    }
    cout << min(cnt[6] - 1, cnt[1]);
    return 0;
}