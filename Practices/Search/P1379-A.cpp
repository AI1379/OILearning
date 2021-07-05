// A* Algorithm
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
struct node {
  ull state;
  int dis;
  int weight;
  bool operator<(const node &a) const { return weight > a.weight; }
};
const int rule[9][4] = {{1, 3, 0, 0},  {-1, 1, 3, 0},  {-1, 3, 0, 0},
                        {-3, 3, 1, 0}, {-1, 1, -3, 3}, {-3, -1, 3, 0},
                        {-3, 1, 0, 0}, {-3, -1, 1, 0}, {-3, -1, 0, 0}};
map<ull, bool> vis;
const ull goal = 123804765;
ull nodeswap(node opt, int pos1, int pos2) {
  node ans = opt;
  ull val1 = ans.state, val2 = ans.state;
  ull pow1 = 1, pow2 = 1;
  for (int i = 0; i < 8 - pos1; i++) val1 /= 10, pow1 *= 10;
  for (int i = 0; i < 8 - pos2; i++) val2 /= 10, pow2 *= 10;
  val1 %= 10;
  val2 %= 10;
  ans.state = ans.state - val1 * pow1 + val2 * pow1 - val2 * pow2 + val1 * pow2;
  return ans.state;
}
int getnumbypos(ull opt, int pos) {
  ull res = opt;
  for (int i = 0; i < 8 - pos; i++) res /= 10;
  res %= 10;
  return (int)(res);
}
int match(ull argm) {
  ull opt1 = argm, opt2 = goal;
  int res = 0;
  for (int i = 0; i < 9; i++) {
    if (opt1 % 10 == opt2 % 10) res++;
    opt1 /= 10;
    opt2 /= 10;
  }
  return res;
}
priority_queue<node> q;
int main() {
  ull in;
  cin >> in;
  q.push({in, 0, 0});
  node head = {in, 0, 0};
  vis[head.state] = true;
  while (!q.empty()) {
    head = q.top();
    ull tmp = head.state;
    if (tmp == goal) {
      cout << head.dis << endl;
#ifdef DEBUG
      system("pause");
#endif
      return 0;
    }
    int pos0 = 8;
    while (tmp % 10 != 0) tmp /= 10, pos0--;
    for (int i = 0; i < 4; i++) {
      if (rule[pos0][i] == 0) break;
      node newnode;
      newnode.dis = head.dis + 1;
      newnode.state = nodeswap(head, pos0, pos0 + rule[pos0][i]);
      newnode.weight = newnode.dis + match(newnode.state);
      if (vis[newnode.state]) continue;
      vis[newnode.state] = true;
      q.push(newnode);
    }
    q.pop();
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}