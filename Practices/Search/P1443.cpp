#include <bits/stdc++.h>
using namespace std;
struct pos
{
  int x, y, level;
};
int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};
int m, n;
int mp[401][401];
queue<pos> q;
bool judge(pos in)
{
  return 1 <= in.x && in.x <= n && 1 <= in.y && in.y <= m;
}
int main()
{
  int x, y, i, j, ans = 0;
  pos tmp, head;
  cin >> n >> m >> x >> y;
  memset(mp, -1, sizeof(mp));
  mp[x][y] = 0;
  tmp.x = x;
  tmp.y = y;
  tmp.level = 0;
  q.push(tmp);
  while (!q.empty())
  {
    head = q.front();
    for (i = 0; i < 8; i++)
    {
      tmp.x = head.x + dx[i];
      tmp.y = head.y + dy[i];
      if (mp[tmp.x][tmp.y] == -1 && judge(tmp))
      {
        tmp.level = head.level + 1;
        q.push(tmp);
        mp[tmp.x][tmp.y] = tmp.level;
      }
    }
    q.pop();
  }
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= m; j++)
    {
      printf("%-5d", mp[i][j]);
    }
    cout << endl;
  }
  return 0;
}
