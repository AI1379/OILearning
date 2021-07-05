#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
double a, b, c, d;
double cal(double x) {
  return (x * x * x * (a)) + (x * x * (b)) + (x * (c)) + (d);
}
int main() {
  double l, r, mid;
  double yl, yr;
  int num = 0;
  scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
  for (double i = -100.000000; i < 100.000000; i++) {
    l = i;
    r = i + 1.000000;
    yl = cal(l);
    yr = cal(r);
    if (yl == 0) {
      printf("%0.2lf ", l);
      num++;
      continue;
    }
    if (yl * yr < 0) {
      while (fabs(l - r) >= eps) {
        mid = (l + r) / 2.000000;
        if (yr * cal(mid) <= 0)
          l = mid;
        else
          r = mid;
      }
      printf("%.2lf ", r);
      num++;
      if (num == 3) break;
    }
  }
  cout << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}