/* -------------------------------------------------------------
 * 题目描述
 * 如题，已知一个数列，你需要进行下面两种操作：
 *   1.将某区间每一个数加上x
 *   2.求出某区间每一个数的和
 * 
 * 输入格式
 * 第一行包含两个整数N、M，分别表示该数列数字的个数和操作的总个数。
 * 第二行包含N个用空格分隔的整数，其中第i个数字表示数列第i项的初始值。
 * 接下来M行每行包含3或4个整数，表示一个操作，具体如下：
 * 操作1： 格式：1 x y k 含义：将区间[x,y]内每个数加上k
 * 操作2： 格式：2 x y 含义：输出区间[x,y]内每个数的和
 * 
 * 输出格式
 * 输出包含若干行整数，即为所有操作2的结果。
 * -------------------------------------------------------------
 */

#include <bits/stdc++.h>
using namespace std;
long long n,odata[100005],segt[270000],lazy1[270000].lazy2;
void build(long long l, long long r, long long p)
{
  if (l == r)
  {
    segt[p] = odata[l];
    return;
  }
  long long m = (l + r) >> 1;
  build(l, m, p << 1), build(m + 1, r, (p << 1) | 1);
  segt[p] = segt[p << 1] + segt[(p << 1) | 1];
}
void update1(long long l, long long r, long long c, long long s, long long t, long long p) //c:num will be added; p:num of node
{
  if (l <= s && t <= r) //in, Change [l,r]
  {
    segt[p] += (t - s + 1) * c, lazy1[p] += c; //lazy1 tag
    return;
  }
  long long m = (s + t) >> 1;
  if (lazy1[p])
  {
    segt[p << 1] += lazy1[p] * (m - s + 1);
    segt[(p << 1) | 1] += lazy1[p] * (t - m);
    lazy1[p << 1] += lazy1[p];
    lazy1[(p << 1) | 1] += lazy1[p];
  }
  lazy1[p] = 0;
  if (l <= m)
    update1(l, r, c, s, m, p << 1);
  if (r > m)
    update1(l, r, c, m + 1, t, (p << 1) | 1);
  segt[p] = segt[p << 1] + segt[(p << 1) | 1];
}
void update2(long long l, long long r, long long c, long long s, long long t, long long p) //c:num will be added; p:num of node
{
  if (l <= s && t <= r) //in, Change [l,r]
  {
    segt[p] += (t - s + 1) * c, lazy1[p] += c; //lazy1 tag
    return;
  }
  long long m = (s + t) >> 1;
  if (lazy1[p])
  {
    segt[p << 1] += lazy1[p] * (m - s + 1);
    segt[(p << 1) | 1] += lazy1[p] * (t - m);
    lazy1[p << 1] += lazy1[p];
    lazy1[(p << 1) | 1] += lazy1[p];
  }
  lazy1[p] = 0;
  if (l <= m)
    update2(l, r, c, s, m, p << 1);
  if (r > m)
    update2(l, r, c, m + 1, t, (p << 1) | 1);
  segt[p] = segt[p << 1] + segt[(p << 1) | 1];
}
int main()
{
}