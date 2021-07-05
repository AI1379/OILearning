#include <bits/stdc++.h>
using namespace std;
const int MAXN = 11;
int n;
bool mp[MAXN][MAXN];
void out() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << mp[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
}
void change(int posx, int posy) {
  mp[posx][posy] = (!mp[posx][posy]);
  if (posx - 1 > 0) mp[posx - 1][posy] = (!mp[posx - 1][posy]);
  if (posx + 1 <= n) mp[posx + 1][posy] = (!mp[posx + 1][posy]);
  if (posy - 1 > 0) mp[posx][posy - 1] = (!mp[posx][posy - 1]);
  if (posy + 1 <= n) mp[posx][posy + 1] = (!mp[posx][posy + 1]);
}
void dfs(int deps) {
  // stack<pair<int, int>> stk;
  if (deps > n) {
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (mp[i - 1][j] == 1) {
          change(i, j);
          //           stk.push(make_pair(i, j));
          // #ifdef DEBUG
          //           out();
          // #endif
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (mp[i][j] == 1) {
//           while (!stk.empty()) {
//             change(stk.top().first, stk.top().second);
// #ifdef DEBUG
//             cout << stk.top().first << ' ' << stk.top().second << endl;
//             out();
// #endif
//             stk.pop();
//           }
#ifdef DEBUG
          cout << "DFS Failed" << endl;
          out();
#endif
          return;
        }
      }
    }
    cout << "Yes" << endl;
    exit(0);
  }
  dfs(deps + 1);
  change(1, deps);
  dfs(deps + 1);
}
int main() {
  int tmp;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> tmp;
      mp[i][j] = (tmp == 1);
    }
  }
#ifdef DEBUG
  out();
#endif
  dfs(1);
  cout << "No" << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}