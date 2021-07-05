#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
const int MAXM = 1000;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int n, m;
int p[MAXN][MAXM];
struct node {
  pair<int, int> point;
  int p;
  bool operator<(const node &b) const { return p > b.p; }
};
node mknode(int x, int y) {
  node res;
  res.point = make_pair(x, y);
  res.p = p[x][y];
  return res;
}
bool bfsjudge(int mid) {
  // queue<pair<int, int> > q;
  priority_queue<node> q;
  // pair<int, int> tmp;
  node tmp;
  int posx, posy;
  for (int i = 0; i < m; i++) {
    bool vis[MAXN][MAXM];
    memset(vis, false, sizeof(vis));
    // q.push(make_pair(1, i));
    q.push(mknode(1, i));
    vis[1][i] = true;
    while (!q.empty()) {
      // tmp = q.front();
      tmp = q.top();
      q.pop();
      if (tmp.point.first == n - 2) return true;
      for (int j = 0; j < 4; j++) {
        posx = dx[j] + tmp.point.first;
        posy = dy[j] + tmp.point.second;
        if (0 <= posx && posx < n && 0 <= posy && posy < m) {
          if (p[posx][posy] == 0) continue;
          if (p[posx][posy] <= mid && !vis[posx][posy]) {
            // q.push(make_pair(posx, posy));
            q.push(mknode(posx, posy));
            vis[posx][posy] = true;
          }
        }
      }
    }
  }
  return false;
}
int main() {
  int l = 1001, r = 0, mid;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> p[i][j];
      if (p[i][j] != 0) l = min(l, p[i][j]);
      r = max(r, p[i][j]);
    }
  }
#ifdef DEBUG
  cout << l << ' ' << r << endl;
#endif
  while (r > l + 1) {
    mid = (r + l) / 2;
    if (bfsjudge(mid)) {
      r = mid;
#ifdef DEBUG
      cout << mid << ": Succeeded" << endl;
#endif
    } else {
      l = mid + 1;
#ifdef DEBUG
      cout << mid << ": Failed" << endl;
#endif
    }
  }
  cout << r << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}