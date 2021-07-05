#include <cstdio>
int t, k, l, q[10];
long long n, m, ord[100];
long long max(long long x, long long y) { return x > y ? x : y; }
long long gcd(long long x, long long y) {
  return x % y == 0 ? y : gcd(y, x % y);
}
bool dfs(long long a, long long b, int remain, long long min) {
  bool flag = false;

  if (a < 0) return false;

  long long g = gcd(a, b);
  a /= g;
  b /= g;

  if (remain == 1 && a == 1 && b <= ord[l - remain]) {
    ord[l - remain] = b;
    return true;
  }

  if (remain == 1 && a != 1) return false;

  for (register long long i = max(b / a, min + 1);
       i < b * remain / a + (b * remain % a == 0 ? 0 : 1); i++) {
    bool tag = true;

    for (register int j = 0; j < k; j++)
      if (i == q[j]) tag = false;

    if (!tag) continue;

    if (dfs((a * i - b), i * b, remain - 1, i)) {
      ord[l - remain] = i;
      flag = true;
    }
  }

  return flag;
}
int main() {
  for (register int i = 0; i < 1; i++) {
    scanf("%lld %lld", &n, &m);
    for (register int j = 0; j < 100; j++) ord[j] = 10000000000000;
    for (l = 1;; l++)
      if (dfs(n, m, l, 0)) break;
    for (register int j = 0; j < l; j++) printf("%lld ", ord[j]);
    if (i != t - 1) printf("\n");
  }

  return 0;
}