#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > lHeap;
priority_queue<int, vector<int>, less<int> > gHeap;
int n, w;
void ins(int x, int p) {
  if (lHeap.empty() || x < lHeap.top()) {
    gHeap.push(x);
  } else {
    lHeap.push(x);
  }
  int num = max(1, p * w / 100);
  while (lHeap.size() < num && !gHeap.empty()) {
    lHeap.push(gHeap.top());
    gHeap.pop();
  }
  while (lHeap.size() > num) {
    gHeap.push(lHeap.top());
    lHeap.pop();
  }
}
int main() {
  int x;
  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    ins(x, i);
    cout << lHeap.top() << ' ';
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}