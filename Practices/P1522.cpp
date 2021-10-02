#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> farms[200];
double mp[200][200];
double maxl[200];
int fa[200];
double d[200];
double cal(int num1, int num2) {
  int x = (farms[num1].first - farms[num2].first) *
              (farms[num1].first - farms[num2].first) +
          (farms[num1].second - farms[num2].second) *
              (farms[num1].second - farms[num2].second);
  return sqrt(x);
}
int find(int pos) {
  if (fa[pos] != pos) fa[pos] = find(fa[pos]);
  return fa[pos];
}
int main() {
  // freopen("cowtravel.in", "r", stdin);
  // freopen("cowtravel.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> farms[i].first >> farms[i].second;
  }
  getchar();
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
    for (int j = 1; j <= n; j++) {
      if (getchar() == '1')
        mp[i][j] = cal(i, j);
      else if (i == j)
        mp[i][j] = 0;
      else
        mp[i][j] = 1e9;
    }
    getchar();
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (mp[i][j] < 1e8) {
        maxl[i] = fmax(maxl[i], mp[i][j]);
        if (find(i) != find(j)) {
          fa[j] = i;
        }
      }
    }
  }
  int tmp;
  for (int i = 1; i <= n; i++) {
    tmp = find(i);
    d[tmp] = fmax(d[tmp], maxl[i]);
  }
  double ans = 1e9;
  double maxd, l;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (mp[i][j] > 1e8) {
        l = maxl[i] + maxl[j] + cal(i, j);
        maxd = fmax(d[find(i)], d[find(j)]);
        ans = fmin(ans, fmax(l, maxd));
      }
    }
  }
  printf("%.6f", ans);
  return 0;
}
