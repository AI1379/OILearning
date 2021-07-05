#include <bits/stdc++.h>
using namespace std;
unsigned int f[1010][1010];
bool check(char x, char y)
{
    return (x == '[' && y == ']') || (x == '(' && y == ')');
}
int main()
{
    string in;
    cin >> in;
    int len = in.length(), l, i, j, k;
    memset(f, -1, sizeof(f));
    for (i = 1; i <= len; i++)
        f[i][i] = 1;
    for (i = 1; i <= len; i++)
        for (j = i + 1; j <= len; j++)
            f[j][i] = 0;
    for (l = 2; l <= len; l++)
    {
        for (i = 1; i <= len - l + 1; i++)
        {
            j = i + l - 1;
            if (!check(in[i - 1], in[j - 1]))
            {
                f[i][j] = f[i + 1][j - 1] + 2;
#ifdef DEBUG
                cout << i << ' ' << j << endl;
#endif
            }
            else
                f[i][j] = f[i + 1][j - 1];
            for (k = i; k < j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
        }
    }
#ifdef DEBUG
    for (i = 1; i <= len; i++)
    {
        for (j = 1; j <= len; j++)
        {
            cout << f[i][j] << ' ';
        }
        cout << endl;
    }
#endif
    cout << f[1][len];
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}