#include <bits/stdc++.h>
using namespace std;
const int MAXN = 101;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
bool mp[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n;
#define posx point.first
#define posy point.second
int main() {
  char c;
  pair<int, int> point;
  queue<pair<int, int> > q;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      c = getchar();
      mp[i][j] = (c == '1');
      if (c == '1') {
        point = make_pair(i, j);
        q.push(point);
        vis[posx][posy] = true;
      }
    }
    getchar();
  }
  while (!q.empty()) {
    point = q.front();
    for (int i = 0; i < 4; i++) {
      if (!vis[posx + dx[i]][posy + dy[i]] && mp[posx + dx[i]][posy + dy[i]]) {

      }
    }
  }
}