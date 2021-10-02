#include <bits/stdc++.h>
using namespace std;
int n;
int a[2010];
int cnt;
int gcd(int x, int y) {
  if (x < y) x = x ^ y, y = x ^ y, x = x ^ y;
  return x % y == 0 ? y : gcd(y, x % y);
}
int main() {
  cin >> n;
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      cnt++;
    }
  }
  if (cnt > 0) {
    cout << n - cnt << endl;
#ifdef DEBUG
    system("pause");
#endif
    return 0;
  }
  int mintime = 0x3f3f3f3f;
  int tmp;
  for (int i = 1; i <= n; i++) {
    cnt = 0;
    tmp = a[i];
    for (int j = i + 1; j <= n; j++) {
      cnt++;
      tmp = gcd(tmp, a[j]);
      if (tmp == 1) break;
    }
    if (tmp == 1) mintime = min(mintime, cnt);
  }
  if (mintime == 0x3f3f3f3f) {
    cout << "-1" << endl;
  } else {
    cout << mintime + n - 1 << endl;
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}