#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int h[MAXN];
int n, m;
int main()
{
    bool flag, started = false;
    int i;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> h[i];
    for (i = 0; i < n; i++)
    {
        if (i == 0)
            continue;
        else if (!started)
        {
            if (h[i] > h[i - 1])
            {
                flag = true;
                started = true;
            }
            else if (h[i] < h[i - 1])
            {
                flag = false;
                started = true;
            }
            else
                m++;
        }
        else
        {
            if ((flag && h[i] <= h[i - 1]) || (!flag && h[i] >= h[i - 1]))
            {
                m++;
#ifdef DEBUG
                cout << i << ' ';
#endif
                flag = !flag;
            }
        }
    }
    cout << m + 2;
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}