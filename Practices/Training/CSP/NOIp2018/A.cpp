#include <iostream>
using namespace std;
int main()
{
    string s;
    long long ans = 0, i, len;
    getline(cin, s);
    len = s.length();
    for (i = 0; i < len; i++)
        if (s[i] != ' ')
            ans++;
    cout << ans;
    return 0;
}