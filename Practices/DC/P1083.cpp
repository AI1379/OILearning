#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
const int MAXM = 100010;
struct pur {
  int d, s, t;
};
int avail[MAXN];
int diff[MAXN];
int n, m;
pur purs[MAXM];
bool judge(int pos) {
  //先用从0开始处理差分数组直到purs[pos]然后判断是否可行然后倒着恢复diff数组
  //或者直接memset(diff,0,sizeof(diff))然后判的时候加上avail
  memset(diff, 0, sizeof(diff));
  for (int i = 0; i <= pos; i++) {
    diff[purs[i].s] += purs[i].d;
    diff[purs[i].t + 1] -= purs[i].d;
  }
  for (int i = 0; i <= n; i++) {
    if (avail[i] + diff[i] < 0) {
      return false;
    }
  }
  return true;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> avail[i];
    // if (i != 0)
    //   diff[i] = avail[i] - avail[i - 1];
    // else
    //   diff[i] = avail[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> purs[i].d >> purs[i].s >> purs[i].t;
  }
  int l = 0, r = m, mid;
  if (judge(r)) {
    cout << 0 << endl;
#ifdef DEBUG
    system("pause");
#endif
    return 0;
  }
  while (r > l) {
    mid = (l + r) / 2;
    if (judge(mid))
      l = mid;
    else
      r = mid - 1;
  }
  #ifdef DEBUG
  cout<<l<<' '<<mid<<' '<<r<<endl;
  #endif
  cout << -1 << endl << mid << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}