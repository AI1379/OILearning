#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int n;
int ans;
int anstable[2001][2001];
int dfs(int sum, int max) {
  if (sum == n) {
    ans = (ans + 1) % MOD;
    return 1;
  }
  if (anstable[sum][max] != -1) {
    return anstable[sum][max];
  }
  int res = 0;
  for (int i = max + 1; i <= n - sum; i++) {
    res = (res + dfs(sum + i, i)) % MOD;
  }
  anstable[sum][max] = res;
  return res;
}
int main() {
  cin >> n;
  memset(anstable, -1, sizeof(anstable));
  cout << dfs(0, 0) << endl;
  // cout << ans << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}