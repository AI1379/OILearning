#include <bits/stdc++.h>
using namespace std;
int n, maxm;
int c[65000];
int ans[15010];
int lowbit(int x) { return x & (-x); }
void add(int pos, int num) {
  int x = pos;
  while (x <= 32010) {
    c[x] += num;
    x += lowbit(x);
  }
}
int query(int pos) {
  int res = 0;
  while (pos >= 1) {
    res += c[pos];
    pos -= lowbit(pos);
  }
  return res;
}
int main() {
  int x, y;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    x++;
    maxm = max(maxm, y + 1);
    ans[query(x)]++;
    add(x, 1);
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}