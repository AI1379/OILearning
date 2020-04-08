#include <bits/stdc++.h>
using namespace std;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
struct pos
{
    int x, y;
};
int r, c, ans = 0;
bool mp[1000][1000], vis[1000][1000];
queue<pos> q;
int main()
{
    string s;
    int i, j, k, cnt;
    memset(vis, 0, sizeof(vis));
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
            if (vis[i][j])
                continue;
            if (mp[i][j])
            {
                pos tmp, head, lu, rd;
                q.push(tmp);
                cnt = 1;
                lu = tmp;
                rd = tmp;
                vis[i][j] = true;
                while (!q.empty())
                {
                    head = q.front();
                    for (k = 0; k < 4; k++)
                    {
                        if (0 <= head.x + dx[k] && head.y + dx[k] < r && 0 <= head.y + dy[k] && head.y + dy[k] < c)
                        {
                            if (!vis[head.x + dx[k]][head.y + dy[k]] && mp[head.x + dx[k]][head.y + dy[k]])
                            {
                                tmp.x = head.x + dx[k];
                                tmp.y = head.y + dy[k];
                                q.push(tmp);
                                vis[tmp.x][tmp.y] = true;
                                lu.x = min(lu.x, tmp.x);
                                lu.y = min(lu.y, tmp.y);
                                rd.x = max(rd.x, tmp.x);
                                rd.y = max(rd.y, tmp.y);
                                cnt++;
                            }
                        }
                    }
                    q.pop();
                }
                if (cnt != (rd.x - lu.x) * (rd.y - lu.y))
                {
                    printf("Bad placement.");
                    return 0;
                }
                else
                {
                    ans++;
                }
            }
        }
    }
    printf("There are %d ships.", ans);
#ifdef DEBUG
    getchar();
#endif // DEBUG
    return 0;
}