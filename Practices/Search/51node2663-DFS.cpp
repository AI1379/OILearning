#include <bits/stdc++.h>
using namespace std;
const int MAXM = 1001;
const int MAXN = 1001;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int n, m;
bool mp[MAXN][MAXM];
int mark[MAXN][MAXM];
bool vis[MAXN][MAXM];
char ans[MAXN][MAXM];
int size[MAXM * MAXN];
void dfs(pair<int, int> in, int num) {
  mark[in.first][in.second] = num;
  vis[in.first][in.second] = true;
  size[num]++;
  int posx, posy;
  for (int i = 0; i < 4; i++) {
    posx = in.first + dx[i];
    posy = in.second + dy[i];
    if (!vis[posx][posy] && mp[posx][posy] &&
        (0 <= posx && posx < n && 0 <= posy && posy < m)) {
      dfs(make_pair(posx, posy), num);
    }
  }
}
int main() {
  cin >> n >> m;
  string tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    for (int j = 0; j < m; j++) {
      if (tmp[j] == '*') {
        mp[i][j] = false;
      } else {
        mp[i][j] = true;
        ans[i][j] = '.';
      }
    }
  }
  int num = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mp[i][j] && !vis[i][j]) {
        dfs(make_pair(i, j), num);
        num++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int res = 0;
      if (!mp[i][j]) {
        set<int> markset;
        int setsize = markset.size();
        for (int k = 0; k < 4; k++) {
          if (!mp[i + dx[k]][j + dy[k]]) continue;
          markset.insert(mark[i + dx[k]][j + dy[k]]);
          if (setsize != markset.size()) {
            res += size[mark[i + dx[k]][j + dy[k]]];
            setsize++;
          }
        }
        res++;
        ans[i][j] = (char)(res % 10 + (int)('0'));
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%s\n", ans[i]);
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}