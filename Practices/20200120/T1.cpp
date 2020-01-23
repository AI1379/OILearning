#include <bits/stdc++.h>
using namespace std;
struct stone
{
    int a, b
};
stone stn[1010];
int n, m, k;
bool cmp1(const stone &A, const stone &B)
{
    if (A.a == B.a)
        return A.b > B.b;
    else
        return A.a < B.a;
}
int main()
{
    int i, j;
    cin >> n >> m >> k;
    for (i = 1; i <= n; i++)
        cin >> stn[i].a;
    for (i = 1; i <= n; i++)
        cin >> stn[i].b;
    sort(stn, stn + n + 1, cmp1);
    
}