#include <bits/stdc++.h>
using namespace std;
int f[10010];
int tim, n, t[10010], c[10010], p[10010];
int solve(string s)
{
    bool flag = false;
    int ho = 0, mi = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ':')
            flag = true;
        else if (flag)
            mi = mi * 10 + (int)(s[i] - '0');
        else
            ho = ho * 10 + (int)(s[i] - '0');
    }
    return ho * 60 + mi;
}
void ZeroOnePack(int cost, int weight)
{
    for (int i = tim; i >= cost; i--)
        f[i] = max(f[i], f[i - cost] + weight);
}
void CompletePack(int cost, int weight)
{
    for (int i = cost; i <= tim; i++)
        f[i] = max(f[i], f[i - cost] + weight);
}
void MultiplePack(int cost, int weight, int amount)
{
    if (cost * amount >= tim)
        CompletePack(cost, weight); //想取多少取多少，相当于有无数个，直接调用完全背包
    else
        for (int k = 1; k < amount; amount -= k, k *= 2) //注意amount-=k和k*=2顺序不能反
            ZeroOnePack(k * cost, k * weight);
    ZeroOnePack(amount * cost, amount * weight);
}
int main()
{
    int i;
    string begin, end;
    cin >> begin >> end >> n;
    tim = solve(end) - solve(begin);
    for (i = 1; i <= n; i++)
        cin >> t[i] >> c[i] >> p[i];
    for (i = 1; i <= n; i++)
    {
        if (p[i] == 0)
            CompletePack(t[i], c[i]);
        if (p[i] == 1)
            ZeroOnePack(t[i], c[i]);
        else
            MultiplePack(t[i], c[i], p[i]);
    }
    cout << f[tim];
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}