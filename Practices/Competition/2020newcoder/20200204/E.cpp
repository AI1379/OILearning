#include <bits/stdc++.h>
using namespace std;
long long n;
long long ans = 0;
long long factor(long long x)
{
    long long i;
    long long rst = 0;
    for (i = 1; i * i <= x; i++)
    {
        if (x % i == 0 && i * i != x)
        {
            rst += 2;
        }
        else if (x % i == 0 && i * i == x)
        {
            rst++;
        }
    }
    return rst;
}
int main()
{
    long long tmp;
    cin >> n;
    while (true)
    {
        tmp = factor(n);
        ans++;
        if (tmp == 2)
        {
            cout << ans;
            return 0;
        }
        else
        {
            n = tmp;
        }
    }
    return 0;
}