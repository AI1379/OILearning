#include <bits/stdc++.h>
using namespace std;
long long times[3][3], all = 0;
void hanoi(long long n, char a, char b, char c)
{
    if (n == 1)
    {
        times[a - 'A'][c - 'A']++;
        all++;
        return;
    }
    else
    {
        hanoi(n - 1, a, c, b);
        times[a - 'A'][c - 'A']++;
        all++;
        hanoi(n - 1, b, a, c);
        return;
    }
}
int main()
{
    long long n;
    cin >> n;
    for (; n <= 30; n++)
    {
        memset(times,0,sizeof(times));
        hanoi(n, 'A', 'B', 'C');
        cout<<n<<":\n";
        for (long long i = 0; i < 3; i++)
        {
            for (long long j = 0; j < 3; j++)
            {
                if (i == j)
                    continue;
                cout << (char)(i + (long long)('A')) << "->" << (char)(j + (long long)('A')) << ":" << times[i][j] << endl;
            }
        }
        cout << "SUM:" << all<<endl;
    }
    return 0;
}