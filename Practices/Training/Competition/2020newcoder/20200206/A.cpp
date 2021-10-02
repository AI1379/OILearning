#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;
    cout << min(a, y) + min(b, z) + min(c, x);
    return 0;
}