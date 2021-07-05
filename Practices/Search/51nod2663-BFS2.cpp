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
#ifdef DEBUG
int maxmark;
#endif
void bfs(pair<int, int> in, int num) {
  queue<pair<int, int> > q;
  q.push(in);
  pair<int, int> point = in;
  int posx, posy;
  mark[in.first][in.second] = num;
  vis[in.first][in.second] = true;
  size[num]++;
  while (!q.empty()) {
    point = q.front();
    for (int i = 0; i < 4; i++) {
      posx = point.first + dx[i];
      posy = point.second + dy[i];
      if (!vis[posx][posy] && mp[posx][posy] &&
          (0 <= posx && posx < n && 0 <= posy && posy < m)) {
        vis[posx][posy] = true;
        q.push(make_pair(posx, posy));
        mark[posx][posy] = num;
        size[num]++;
      }
    }
    q.pop();
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
#ifdef DEBUG
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << mp[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
#endif
  int num = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mp[i][j] && !vis[i][j]) {
#ifdef DEBUG
        cout << num << endl;
        for (int it = 0; it < n; it++) {
          for (int jt = 0; jt < m; jt++) {
            cout << vis[it][jt] << ' ';
          }
          cout << endl;
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            cout << mark[i][j] << ' ';
          }
          cout << endl;
        }
        cout << endl;
#endif
        bfs(make_pair(i, j), num);
        num++;
#ifdef DEBUG
        cout << num << endl;
        for (int it = 0; it < n; it++) {
          for (int jt = 0; jt < m; jt++) {
            cout << vis[it][jt] << ' ';
          }
          cout << endl;
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            cout << mark[i][j] << ' ';
          }
          cout << endl;
        }
        cout << endl;
#endif
      }
    }
  }
#ifdef DEBUG
  maxmark = num;
  cout << maxmark << endl;
  for (int i = 0; i <= maxmark; i++) cout << size[i] << ' ';
  cout << endl << endl;
#endif
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
#ifdef DEBUG
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << mark[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
#endif
  for (int i = 0; i < n; i++) {
    printf("%s\n", ans[i]);
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}