#include <bits/stdc++.h>
using namespace std;
int lowbit(int x) { return x & -x; }
int main() {
  int x;
  cin >> x;
  if (x % 2 != 0) {
    cout << -1 << endl;
    return 0;
  }
  stack<int> ans;
  while (x > 0) {
    ans.push(lowbit(x));
    x -= lowbit(x);
  }
  while (!ans.empty()) {
    cout << ans.top() << ' ';
    ans.pop();
  }
  return 0;
}