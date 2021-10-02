#include <bits/stdc++.h>
using namespace std;
#include "./Define.h"
#include "./HeapSort.hpp"
int tmp[n];
int ans[n];

void BubbleSort() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
}

void SelectionSort() {
  int minIdx;
  for (int i = 0; i < n; i++) {
    minIdx = i;
    for (int j = i + 1; j < n; j++)
      if (a[j] < a[minIdx]) minIdx = j;
    swap(a[i], a[minIdx]);
  }
}

void InsertSort(int left, int right) {
  int i, j, key;
  for (i = left + 1; i <= right; i++) {
    key = a[i];
    j = i - 1;
    while (j >= left && a[j] > key) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
  return;
}
void InsertSort() { InsertSort(0, n - 1); }

void ShellSort() {  // O(n^1.5)复杂度
  int delta = 1;
  while (delta < n / 3) {
    delta = delta * 3 + 1;
  }  // 处理步长
  for (; delta >= 1; delta /= 3) {
    for (int i = delta; i < n; i++) {
      // 注意：动图里看起来是每组分别排序，一组排完排另一组，但是在代码实现里一般写在一块
      for (int j = i; j >= delta && a[j] < a[j - delta]; j -= delta) {
        swap(a[j], a[j - delta]);
      }
    }
  }
}

inline int choosePiovt(int left, int right) {
  int x = a[left], y = a[right], z = a[(left + right) / 2];
  if ((y <= x && x <= z) || (z <= x && x <= y))
    return left;
  else if ((x <= y && y <= z) || (z <= y && y <= x))
    return right;
  else if ((x <= z && z <= y) || (y <= z && z <= x))
    return (left + right) / 2;
}

void QuickSort(int left, int right) {
  if (right - left < 1) return;
  if (right - left <= ins) {
    InsertSort(left, right);  // 序列小的时候用插入排序更快
    return;
  }

  int i = left, j = right - 1, key = choosePiovt(left, right), pivot = a[key];
  swap(a[key], a[right]);

  while (i < j) {
    while (a[i] < pivot && i < j) i++;
    while (a[j] >= pivot && i < j) j--;
    if (i < j) swap(a[i], a[j]);
  }

  if (a[i] >= pivot)
    swap(a[i], a[right]);
  else
    swap(a[++i], a[right]);

  QuickSort(left, i - 1);
  QuickSort(i + 1, right);
  return;
}
void QuickSort() { QuickSort(0, n - 1); }

void test(void (*mySort)(void)) {
  bool check = true;
  clock_t start, end;
  start = clock();
  mySort();
  end = clock();
  for (int i = 0; i < n; i++) {
    if (a[i] != ans[i]) {
      check = false;
      break;
    }
  }
  cout << ((double)(end - start) * 1000.000 / CLK_TCK) << "ms, ";
  if (check)
    cout << "Accept" << endl;
  else {
    cout << "Wrong Answer" << endl;
    // for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    // cout << endl;
    // for (int i = 0; i < n; i++) cout << a[i] << ' ';
    // cout << endl;
  }
  for (int i = 0; i < n; i++) a[i] = tmp[i];
}

int main() {
  srand(time(NULL));

  for (int k = 1; k <= 10; k++) {
    cout << "----------" << endl;
    cout << "Test " << k << " Started" << endl;
    // for (int i = n; i > 0; i--) a[n - i] = i;
    for (int i = 0; i < n; i++) a[i] = rand() % MAXA;
    for (int i = 0; i < n; i++) ans[i] = tmp[i] = a[i];
    // for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << endl;

    clock_t start, end;
    start = clock();
    sort(ans, ans + n);
    end = clock();
    cout << "std::sort: " << ((double)(end - start) * 1000.000 / CLK_TCK)
         << "ms" << endl;

    if (n <= 10000) {
      test(BubbleSort);
      test(SelectionSort);
      test(InsertSort);
      test(ShellSort);
    }
    test(QuickSort);
    test(HeapSort);

    cout << "Test " << k << " Finished" << endl;
    cout << "----------" << endl << endl;
  }

  system("pause");
  return 0;
}