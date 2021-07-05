#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000007;
int n, m;
int a[110];
int f[110][110];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  memset(f, 0, sizeof(f));
  f[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= j && k <= a[i]; k++) {
        f[i][j] = (f[i][j] + f[i - 1][j - k]) % MOD;
      }
    }
  }
  cout << f[n][m] << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}