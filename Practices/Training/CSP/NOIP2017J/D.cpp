#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500010;
int n, d, k;
pair<int, int> mp[MAXN];
int dp[MAXN];
int judge(int g) {
  int x, y;
  x = max(d - g, 1);
  y = d + g;
  deque<int> q;
  queue<int> waitq;
  int diff;
  int ans = 0;
  q.push_back(0);
  for (int i = 1; i <= n; i++) {
    dp[i] = -0x3fffffff;
    if (!q.empty()) diff = (mp[i].first - mp[q.front()].first);
    while (!q.empty() && diff > y) {
      q.pop_front();
      if (!q.empty()) diff = (mp[i].first - mp[q.front()].first);
    }
    while (!waitq.empty()) {
      diff = (mp[i].first - mp[waitq.front()].first);
      if (diff < x) {
        break;
      }
      while (!q.empty() && dp[q.back()] < dp[waitq.front()]) {
        q.pop_back();
      }
      q.push_back(waitq.front());
      waitq.pop();
    }
    dp[i] = dp[q.front()] + mp[i].second;
    waitq.push(i);
    // if (dp[i] >= k) return true;
    ans = max(ans, dp[i]);
  }
#ifdef DEBUG
  cout << ans << endl;
#endif
  return ans >= k;
  // return false;
}
int main() {
  int l, r;
  l = 0;
  r = 0;
  int sum = 0;
  cin >> n >> d >> k;
  for (int i = 1; i <= n; i++) {
    cin >> mp[i].first >> mp[i].second;
    if (mp[i].second > 0) sum += mp[i].second;
    r = max(r, mp[i].first);
  }
  if (sum < k) {
    cout << -1 << endl;
#ifdef DEBUG
    system("pause");
#endif
    return 0;
  }
  r = max(r, d);
  int mid;
  while (l < r) {
    mid = (l + r) / 2;
#ifdef DEBUG
    cout << "(" << l << ", " << r << ") " << mid << endl;
#endif
    if (judge(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (!judge(r)) {
    cout << -1 << endl;
  } else {
    cout << r << endl;
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}