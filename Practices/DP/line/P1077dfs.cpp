#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000007;
long long n, m;
long long a[110];
long long f[110][110];
long long ans;
long long dfs(long long dep, long long used) {
  if (dep == n) {
    if (used == m) {
      return 1;
    }
    return 0;
  }
  long long res = 0;
  for (long long i = 0; i <= a[dep]; i++) {
    res = (res + dfs(dep + 1, used + i)) % MOD;
  }
  return res % MOD;
}
int main() {
  memset(f, -1, sizeof(f));
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  ans = dfs(0, 0) % MOD;
  cout << ans << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}
