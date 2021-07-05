#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
const int MAXM = 1000;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int n, m;
int p[MAXN][MAXM];
// bool bfsjudge(int mid) {
//   stack<pair<int, int> > q;
//   pair<int, int> tmp;
//   int posx, posy;
//   for (int i = 0; i < m; i++) {
//     bool vis[MAXN][MAXM];
//     memset(vis, false, sizeof(vis));
//     q.push(make_pair(1, i));
//     vis[1][i] = true;
//     while (!q.empty()) {
//       tmp = q.front();
//       if (tmp.first == n - 2) return true;
//       for (int j = 0; j < 4; j++) {
//         posx = dx[j] + tmp.first;
//         posy = dy[j] + tmp.second;
//         if (0 <= posx && posx < n && 0 <= posy && posy < m) {
//           if (p[posx][posy] == 0) continue;
//           if (p[posx][posy] <= mid && !vis[posx][posy]) {
//             q.push(make_pair(posx, posy));
//             vis[posx][posy] = true;
//           }
//         }
//       }
//       q.pop();
//     }
//   }
//   return false;
// }
bool judge(int mid) {
  for (int i = 0; i < m; i++)
    if (dfs(mid, 1, i)) return true;
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