#include <bits/stdc++.h>
#define LL long long
using namespace std;

struct node {
  int x, y, z;
} e[500010];

struct query {
  int x, y, id;
};

int father[500010], ret[500010], n, m, qu;
stack<pair<int, int>> s;
vector<query> v[500010];
vector<pair<int, int>> g[500010];

int fd(int x) {
  if (father[x] < 0) {
    return x;
  } else {
    return fd(father[x]);
  }
}

bool cmp(query a, query b) { return a.id < b.id; }

void work(int x, int y) {
  int fx = fd(x), fy = fd(y);
  if (fx == fy) {
    return;
  }
  if (father[fx] <= father[fy]) {
    father[fx] += father[fy];
    father[fy] = fx;

  } else {
    father[fy] += father[fx];
    father[fx] = y;
  }
}

void solve(int cnt, int x, int y) {
  while (!s.empty()) {
    s.pop();
  }
  for (int i = x; i <= y; ++i) {
    int fx = fd(v[cnt][i].x), fy = fd(v[cnt][i].y);

    if (fx == fy) {
      ret[v[cnt][i].id] = 1;
    } else if (father[fx] <= father[fy]) {
      s.push(make_pair(fy, father[fy]));
      father[fy] = fx;
    } else {
      s.push(make_pair(fx, father[fx]));
      father[fx] = fy;
    }
  }
  while (!s.empty()) {
    father[s.top().first] = s.top().second;
    s.pop();
  }
}

int main() {
  memset(father, -1, sizeof(father));

  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].z);
    g[e[i].z].push_back(make_pair(e[i].x, e[i].y));
  }

  scanf("%d", &qu);
  for (int i = 1; i <= qu; i++) {
    int opnum;
    scanf("%d", &opnum);
    for (int j = 1; j <= opnum; j++) {
      int x;
      scanf("%d", &x);
      v[e[x].z].push_back({e[x].x, e[x].y, i});
    }
  }

  for (int i = 1; i <= 500000; i++) {
    sort(v[i].begin(), v[i].end(), cmp);
  }

  for (int i = 1; i <= 500000; i++) {
    for (int j = 0; j < g[i - 1].size(); j++) {
      work(g[i - 1][j].first, g[i - 1][j].second);
    }

    int sz = v[i].size();
    if (sz == 0) {
      continue;
    }
    int now = 0;
    while (now < sz) {
      int j = now;
      while (j + 1 < sz && v[i][j + 1].id == v[i][j].id) {
        j++;
      }
      solve(i, now, j);
      now = j + 1;
    }
  }

  for (int i = 1; i <= qu; i++) {
    printf("%s\n", ret[i] ? "NO" : "YES");
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}