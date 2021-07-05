#include <bits/stdc++.h>
using namespace std;
const char word[] = "yizhong";
const int dx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[] = {-1, 0, 1, -1, 0, 1, -1, 1};
int n;
char mat[100][100];
bool mark[100][100];
bool DFS(int x, int y, int dep, int t)
{
    bool flag;
    if (dep == 6 && mat[x][y] == word[dep])
    {
        mark[x][y] = true;
        return true;
    }
    if ((x + dx[t] < 0) || (y + dy[t] < 0) || (x + dx[t] >= n) || (y + dy[t] >= n) || (mat[x][y] != word[dep]))
        return false;
    flag = DFS(x + dx[t], y + dy[t], dep + 1, t);
    if (flag)
        mark[x][y] = true;
    return flag;
}
int main()
{
    int i, j, k;
    string s;
    memset(mark, false, sizeof(mark));
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        for (j = 0; j < n; j++)
        {
            mat[i][j] = s[j];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (mat[i][j] != word[0])
                continue;
            for (k = 0; k < 8; k++)
            {
                DFS(i, j, 0, k);
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (mark[i][j])
                cout << mat[i][j];
            else
                cout << '*';
        }
        cout << endl;
    }
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}