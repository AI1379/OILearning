#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
struct pos
{
    int x, y;
};
bool mp[1000][1000];
bool vis[1000][1000];
int r, c, ans = 0;
bool bfs(pos in)
{
    int k, minx, miny, maxx = 0, maxy = 0, s = 1;
    pos tmp, head;
    bool res = true;
    queue<pos> q;
    q.push(in);
    minx = in.x;
    miny = in.y;
    vis[in.x][in.y] = true;
    while (!q.empty())
    {
        head = q.front();
        for (k = 0; k < 4; k++)
        {
            if (0 <= head.x + dx[k] && head.x + dx[k] < c && 0 <= head.y + dy[k] && head.y + dy[k] < r)
            {
                if (!vis[head.x + dx[k]][head.y + dy[k]] && mp[head.x + dx[k]][head.y + dy[k]])
                {
                    tmp.x = head.x + dx[k];
                    tmp.y = head.y + dy[k];
                    q.push(tmp);
                    vis[tmp.x][tmp.y] = true;
                    if (tmp.x < minx || tmp.y < miny)
                    {
                        res = false;
                    }
                    s++;
                    maxx = max(tmp.x, maxx);
                    maxy = max(tmp.y, maxy);
                }
            }
        }
        q.pop();
    }
    if (s == 1)
    {
        maxx = in.x;
        maxy = in.y;
    }
    if ((maxx - minx + 1) * (maxy - miny + 1) != s)
        res = false;
    return res;
}
int main()
{
    memset(vis, false, sizeof(vis));
    string s;
    pos tmp;
    int i, j;
    cin >> r >> c;
    for (i = 0; i < r; i++)
    {
        cin >> s;
        for (j = 0; j < c; j++)
        {
            if (s[j] == '#')
                mp[i][j] = true;
            else
                mp[i][j] = false;
        }
    }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (mp[i][j] && !vis[i][j])
            {
                tmp.x = i;
                tmp.y = j;
                if (bfs(tmp))
                {
                    ans++;
                }
                else
                {
                    cout << "Bad placement.";
                    return 0;
                }
            }
        }
    }
    printf("There are %d ships.", ans);
    system("pause");
    return 0;
}