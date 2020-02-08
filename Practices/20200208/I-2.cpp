#include <bits/stdc++.h>
using namespace std;
long long times[3][3] = {{0, 0, 1}, {0, 0, 0}, {0, 0, 0}};
long long all = 1;
int main()
{
    long long n, i, j;
    cin >> n;
    for (i = 2; i <= n; i++)
    {
        all = (all + 1) * 2 - 1;
        if (i % 2 == 0)
        {
            times[0][1] = (all - times[0][2] - times[2][1] - times[1][0] + i / 2) / 3;
            times[1][2] = times[0][1];
            times[2][0] = times[0][1] - i / 2;
        }
        else
        {
            times[1][0] = (all - times[0][1] - times[1][2] - times[2][0] - (i + 1) / 2) / 3;
            times[0][2] = times[1][0] + (i + 1) / 2;
            times[2][1] = times[1][0];
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i == j)
                continue;
            cout << (char)(i + (long long)('A')) << "->" << (char)(j + (long long)('A')) << ":" << times[i][j] << endl;
        }
    }
    cout << "SUM:" << all << endl;
    return 0;
}