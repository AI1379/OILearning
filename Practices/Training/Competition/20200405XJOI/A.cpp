#include <bits/stdc++.h>
using namespace std;
struct pos
{
    int x, y;
};
bool vis[110][110];
int n, ans = 1 << 30;
queue<pos> q;
int main()
{
    cin >> n;
    pos tmp, head;
    tmp.x = 1;
    tmp.y = 1;
    q.push(tmp);
    while (!q.empty())
    {
        head = q.front();
        if (head.x + 1 <= n && head.y + 1 <= (n + 1))
        {
            if (!vis[head.x + 1][head.y + 1])
            {
                tmp.x = head.x + 1;
                tmp.y = head.y + 1;
                q.push(tmp);
            }
        }
        if (head.x + 1 <= n && head.y - 1 >= 1)
        {
            if (!vis[head.x + 1][head.y - 1])
            {
                tmp.x = head.x + 1;
                tmp.y = head.y + 1;
                q.push(tmp);
            }
        }
        if (head.x - 1 >= 1 && head.y + 1 <= (n + 1))
        {
            if (!vis[head.x - 1][head.y + 1])
            {
                tmp.x = head.x + 1;
                tmp.y = head.y + 1;
                q.push(tmp);
            }
        }
        if (head.x - 1 >= 1 && head.y - 1 >= 1)
        {
            if (!vis[head.x - 1][head.y - 1])
            {
                tmp.x = head.x + 1;
                tmp.y = head.y + 1;
                q.push(tmp);
            }
        }
        if (head.x == 1)
        {
            if (head.y == (n + 1))
            {
                if (!vis[2][n + 1])
                {
                    tmp.x = 2;
                    tmp.y = n + 1;
                    q.push(tmp);
                }
            }
            else
            {
                if (!vis[1][head.y + 1])
                {
                    tmp.x = 1;
                    tmp.y = head.y + 1;
                    q.push(tmp);
                }
            }
        }
        if (head.x == n)
        {
            if (head.y == 1)
            {
                if (!vis[n - 1][1])
                {
                    tmp.x = n - 1;
                    tmp.y = 1;
                    q.push(tmp);
                }
            }
            else
            {
                if (!vis[n][head.y - 1])
                {
                    tmp.x = n;
                    tmp.y = head.y - 1;
                    q.push(tmp);
                }
            }
        }
        if (head.y == 1)
        {
            if (head.x == 1)
            {
                if (!vis[1][2])
                {
                    tmp.x = 1;
                    tmp.y = 2;
                    q.push(tmp);
                }
            }
            else
            {
                if (!vis[head.x - 1][1])
                {
                    tmp.x = head.x - 1;
                    tmp.y = 1;
                    q.push(tmp);
                }
            }
        }
        if (head.y == (n + 1))
        {
            if (head.x == n)
            {
                if (!vis[n][n])
                {
                    tmp.x = n;
                    tmp.y = n;
                    q.push(tmp);
                }
            }
            else
            {
                if (!vis[n + 1][n + 1])
                {
                    tmp.x = n + 1;
                    tmp.y = n + 1;
                    q.push(tmp);
                }
            }
        }
    }
}