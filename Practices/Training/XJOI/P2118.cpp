#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
int l, a, b;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    int i, j;
    cin >> a >> b >> l;
    int ansA = l, ansB = 1;
    for (i = 1; i <= l; i++)
    {
        for (j = 1; j <= l; j++)
        {
            if (gcd(i, j) != 1)
                continue;
            if (i * b >= j * a && i * ansB < j * ansA)
            {
                ansA = i;
                ansB = j;
            }
        }
    }
    cout << ansA << ' ' << ansB;
    return 0;
}