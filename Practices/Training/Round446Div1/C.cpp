#include <bits/stdc++.h>
using namespace std;
struct edge {
  int u, v, w, id;
};
int n, m;
edge edges[500010];
bool cmp(edge a, edge b) { return a.w < b.w; }
int lst[500010];
int mp[500010];
int fa[500010];
int stmp[500010];
int vis[500010];
int sizemst;
int fd(int x, int q) {
  if (stmp[x] != q) {
    stmp[x] = q, fa[x] = x;
  }
  if (fa[x] != x) fa[x] = fd(fa[x], q);
  return fa[x];
}
int main() {
  int q, k, cnt;
  bool flag;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
    edges[i].id = i;
  }
  sort(edges + 1, edges + m + 1, cmp);
  for (int i = 1; i <= m; i++) {
    mp[edges[i].id] = i;
  }
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  cnt = 0;
  for (int i = 1; cnt <= n - 1 && i <= m; i++) {
    if (fd(edges[i].u, 0) != fd(edges[i].v, 0)) {
      fa[fd(edges[i].u, 0)] = fd(edges[i].v, 0);
      sizemst += edges[i].w;
      cnt++;
      // cout << '(' << edges[i].u << ", " << edges[i].v << ") ";
    }
  }
  // cout << " | " << sizemst << endl;
  cin >> q;
  int ans = 0;
  while (q--) {
    cnt = 0;
    ans = 0;
    flag = false;
    cin >> k;
    for (int i = 1; i <= k; i++) {
      cin >> lst[i];
      if (flag) continue;
      vis[lst[i]] = q + 1;
      cnt++;
      if (fd(edges[mp[lst[i]]].u, q + 1) != fd(edges[mp[lst[i]]].v, q + 1)) {
        fa[fd(edges[mp[lst[i]]].u, q + 1)] = fd(edges[mp[lst[i]]].v, q + 1);
        ans += edges[mp[lst[i]]].w;
        // cout << lst[i] << ' ';
      } else {
        flag = true;
      }
    }
    if (flag) {
      cout << "NO" << endl;
      continue;
    }
    for (int i = 1; cnt <= n - 1 && i <= m; i++) {
      if (vis[edges[i].id] == q + 1) continue;
      // cout << edges[i].id << ' ';
      if (fd(edges[i].u, q + 1) != fd(edges[i].v, q + 1)) {
        fa[fd(edges[i].u, q + 1)] = fd(edges[i].v, q + 1);
        ans += edges[i].w;
        cnt++;
      }
    }
    // cout << " | " << ans << ' ';
    if (ans > sizemst) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}