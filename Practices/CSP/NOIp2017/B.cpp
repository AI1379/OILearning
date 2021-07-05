#include <bits/stdc++.h>
using namespace std;
long long n, q;
long long bookid[1010];
long long needid[1010];
long long pow(long long x)
{
    long long ans = 1;
    for (long long i = 0; i < x; i++)
        ans *= 10;
    return ans;
}
int main()
{
    long long i, j, x, y, a;
    bool flag;
    cin >> n >> q;
    for (i = 1; i <= n; i++)
        cin >> bookid[i];
    sort(bookid + 1, bookid + n + 1);
    for (i = 1; i <= q; i++)
    {
        cin >> x >> y;
        a = pow(x);
        flag = false;
        for (j = 1; j <= n; j++)
        {
            if (bookid[j] % a == y)
            {
                cout << bookid[j] << endl;
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << "-1" << endl;
    }
    return 0;
}