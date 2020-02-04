#include <bits/stdc++.h>
using namespace std;
int n, a, b, x;
int main()
{
    int pmax, pmin;
    double ans = 0.0000, tmp1, tmp2;
    cin >> n >> x >> a >> b;
    pmax = n * a;
    pmin = n * b;
    tmp1 = pmax * x / 100.0000;
    tmp2 = pmin * (100 - x) / 100.0000;
    ans = tmp1 + tmp2;
    cout << fixed << setprecision(2) << ans << endl;
    system("pause");
    return 0;
}