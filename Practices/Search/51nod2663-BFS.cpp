#include <bits/stdc++.h>
using namespace std;
const int MAXM = 1001;
const int MAXN = 1001;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
bool mp[MAXM][MAXN];
bool vis[MAXM][MAXN];
int pre[MAXM][MAXN];
char ans[MAXM][MAXN];
int m, n;
pair<int, int> fa[MAXM][MAXN];
queue<pair<int, int> > q;
#define posx point.first
#define posy point.second
#define check                                                    \
  (posx + dx[i] >= 0 && posx + dx[i] < n && posy + dy[i] >= 0 && \
   posy + dy[i] < m)
int bfs(pair<int, int> in) {
  int res = 0;
  pair<int, int> point = in;
  // memset(vis, false, sizeof(vis));
  // mp[posx][posy] = true;
  vis[posx][posy] = true;
  res++;
  queue<pair<int, int> > bfsq;
  queue<pair<int, int> > pointq;
  bfsq.push(in);
  while (!bfsq.empty()) {
    point = bfsq.front();
    for (int i = 0; i < 4; i++) {
      if (mp[posx + dx[i]][posy + dy[i]] && !vis[posx + dx[i]][posy + dy[i]] &&
          check) {
        bfsq.push(make_pair(posx + dx[i], posy + dy[i]));
        fa[posx + dx[i]][posy + dy[i]] = in;
        vis[posx + dx[i]][posy + dy[i]] = true;
        res++;
      }
    }
    bfsq.pop();
  }
  // mp[in.first][in.second] = false;
  return res % 10;
}
pair<int, int> find(int x, int y) {
  if (make_pair(x, y) != fa[x][y])
    fa[x][y] = find(fa[x][y].first, fa[x][y].second);
  return fa[x][y];
}
int main() {
  cin >> n >> m;
  string tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    for (int j = 0; j < m; j++) {
      if (tmp[j] == '*') {
        q.push(make_pair(i, j));
        mp[i][j] = false;
      } else {
        mp[i][j] = true;
        ans[i][j] = '.';
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mp[i][j]) {
        pre[i][j] = bfs(make_pair(i, j));
      }
    }
  }
  while (!q.empty()) {
    map<pair<int, int>, bool> used;
    int res = 0;
    pair<int, int> point = q.front();
    for (int i = 0; i < 4; i++) {
      if (!used[find(posx + dx[i], posy + dy[i])] && check) {
        res += pre[find(posx + dx[i], posy + dy[i]).first]
                  [find(posx + dx[i], posy + dy[i]).second];
      }
    }
    res++;
    ans[posx][posy] = (char)(res + (int)('0'));
  }
  // while (!q.empty()) {
  //   pair<int, int> point = q.front();
  //   q.pop();
  //   int res = bfs(point);
  //   cout << res << endl;
  //   ans[posx][posy] = (char)(res + (int)('0'));
  // }
  for (int i = 0; i < n; i++) {
    printf("%s\n", ans[i]);
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}