#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
int main()
{
    cin >> a >> b >> c;
    long double x, y, rst;
    x = (long double)(a);
    y = (long double)(b);
    rst = y / (2.000000 * x) + 1.000000 / 2.000000;
    cout << fixed << setprecision(5) << rst << endl;
    return 0;
}