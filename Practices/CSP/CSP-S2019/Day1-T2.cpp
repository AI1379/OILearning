#include <bits/stdc++.h>
using namespace std;
int n;
int fa[500010];
int sum[500010];
int lst[500010];
string tree;
stack<int> stk;
int main()
{
#ifndef DEBUG
    freopen("bracket.in", "r", stdin);
    freopen("bracket.out", "w", stdout);
#endif
    int i, j;
    cin >> n >> tree;
    for (i = 2; i <= n; i++)
        cin >> fa[i];

#ifdef DEBUG
    system("pause");
#endif
    return 0;
}