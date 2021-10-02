#include <bits/stdc++.h>
using namespace std;
struct node {
  int val, id;
};
int n;
node a[30];
bool cmp(node a, node b) { return a.val < b.val; }
int b[30];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].val;
    a[i].id = i;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    if (i == n) b[a[i].id] = a[1].val;
    else b[a[i].id] = a[i + 1].val;
  }
  for (int i = 1; i <= n; i++) {
    cout << b[i] << ' ';
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}