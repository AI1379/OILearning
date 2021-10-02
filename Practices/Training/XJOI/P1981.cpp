#include <bits/stdc++.h>
using namespace std;
const int MOD = 10000;
int main()
{
    stack<long long> stk;
    long long inNum, tmp;
    char inChar;
    cin >> inNum;
    stk.push(inNum % MOD);
    while (cin >> inChar >> inNum)
    {
        if (inChar == '*')
        {
            tmp = stk.top() % MOD;
            stk.pop();
            stk.push(((tmp % MOD) * (inNum % MOD)) % MOD);
        }
        else
        {
            stk.push(inNum % MOD);
        }
    }
    long long ans = 0;
    while (!stk.empty())
    {
        ans = (ans + stk.top()) % MOD;
        stk.pop();
    }
    cout << ans;
    return 0;
}