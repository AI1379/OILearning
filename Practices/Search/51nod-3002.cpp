#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int n;
int ans;
void dfs(int parts, int state, int deps) {
  int i, maxi = (state - parts * (parts + 1) / 2 + parts) / parts;
  if (parts == 1) {
    if (deps <= state) ans = (ans + 1) % MOD;
    return;
  }
  for (i = deps; i <= state; i++) {
    if ((i - 1) * parts + parts * (parts + 1) / 2 > state) return;
    dfs(parts - 1, state - i, i + 1);
  }
}
int main() {
  cin >> n;
  // ans++;
  // ans += (n / 2 - 1);
  int parts = 1;
  while (parts * (parts + 1) / 2 <= n) {
    dfs(parts, n, 1);
    parts++;
  }
  cout << ans << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}