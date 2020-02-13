#include <bits/stdc++.h>
using namespace std;
long long f[83];
int main()
{
    int i;
    f[0] = 1;
    f[1] = 3;
    f[2] = 5;
    for (i = 3; i <= 82; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    int t, n;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        cin >> n;
        cout << f[n] << endl;
    }
    return 0;
}