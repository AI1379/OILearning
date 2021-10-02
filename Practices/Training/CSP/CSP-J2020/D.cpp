#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
ll mp[1010][1010];
ll dp[1010][1010][2];
int main() {
  cin >> n >> m;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= m; j++) {
      cin >> mp[i][j];
    }
  }
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= n; j++) {
      dp[i][j][0] = 0xc000000000000000;
      dp[i][j][1] = 0xc000000000000000;
    }
  }
  dp[1][1][0] = mp[1][1];
  dp[1][1][1] = mp[1][1];
  for (ll i = 1; i <= m; i++) {
    for (ll j = 1; j <= n; j++) {
      if (i != 1) {
        dp[j][i][0] = max(dp[j][i - 1][0], dp[j][i - 1][1]) + mp[j][i];
        dp[j][i][1] = max(dp[j][i - 1][0], dp[j][i - 1][1]) + mp[j][i];
      }
    }
    for (ll j = 1; j <= n; j++) {
      if (j != 1) {
        dp[j][i][0] = max(dp[j][i][0], dp[j - 1][i][0] + mp[j][i]);
      }
    }
    for (ll j = n; j >= 1; j--) {
      if (j != n) {
        dp[j][i][1] = max(dp[j][i][1], dp[j + 1][i][1] + mp[j][i]);
      }
    }
  }
  cout << max(dp[n][m][0], dp[n][m][1]) << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}