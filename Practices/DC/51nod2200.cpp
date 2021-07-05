#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
struct person {
  int a, b;
};
int n;
person persons[MAXN];
bool cmp(person x, person y) { return x.a * y.b > y.a * x.b; }
int main() {
  int sum = 0, ans = 0;
#ifdef DEBUG
  freopen("./Practices/DC/51nod_2200_3_in.txt", "r", stdin);
#endif
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d%d",&(persons[i].a),&(persons[i].b));
  sort(persons, persons + n, cmp);
  for (int i = 0; i < n; i++) {
#ifdef DEBUG
    cout << persons[i].a << ' ' << persons[i].b << endl;
#endif
    sum += persons[i].b;
    ans += persons[i].a * sum;
  }
  cout << ans << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}