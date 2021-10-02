#include <bits/stdc++.h>

#include "./Define.h"

#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

using std::swap;

class heap {
 private:
  int h[n + 1];
  int _size;
  void up(int pos);
  void down(int pos);

 public:
  heap() { _size = 0; }
  int top() { return h[1]; }
  void push(int val) {
    h[++_size] = val;
    up(_size);
  }
  int pop() {
    int res = h[1];
    swap(h[1], h[_size--]);
    down(1);
    return res;
  }
};

void heap::up(int pos) {
  while (pos > 1 && h[pos] < h[pos / 2]) {
    swap(h[pos], h[pos / 2]);
    pos /= 2;
  }
}

void heap::down(int pos) {
  int minIdx;
  while (pos * 2 <= _size) {
    minIdx = pos * 2;
    if (minIdx + 1 <= _size && h[minIdx + 1] < h[minIdx]) minIdx++;
    if (h[pos] < h[minIdx]) break;
    swap(h[pos], h[minIdx]);
    pos = minIdx;
  }
}

void HeapSort() {
  heap h;
  for (int i = 0; i < n; i++) h.push(a[i]);
  for (int i = 0; i < n; i++) a[i] = h.pop();
}

#endif