#include <bits/stdc++.h>
using namespace std;
long long m, n;
long long oriData[100000];
long long segTree[200010];
long long lazyTag[200010];
void build(long long left, long long right, long long root)
{
    if (left == right)
    {
        segTree[root] = oriData[left];
        return;
    }
    long long mid = (left + right) / 2;
    build(left, mid, root * 2);
    build(mid + 1, right, root * 2 + 1);
    segTree[root] = segTree[root * 2] + segTree[root * 2 + 1];
    return;
}
void pushDown(long long start, long long end, long long mid, long long node)
{
    if (lazyTag[node])
    {
        segTree[node * 2] += lazyTag[node] * (mid - start + 1);
        segTree[node * 2 + 1] += lazyTag[node] * (end - mid);
        lazyTag[node * 2] += lazyTag[node];
        lazyTag[node * 2 + 1] += lazyTag[node];
        lazyTag[node] = 0;
    }
}
long long getSum(long long left, long long right, long long start, long long end, long long node)
{
    if (start <= left && right <= end)
        return segTree[node];
    long long mid = (left + right) / 2;
    pushDown(left, right, mid, node);
    long long res = 0;
    if (start <= mid)
        res += getSum(left, mid, start, end, node * 2);
    if (end > mid)
        res += getSum(mid + 1, right, start, end, node * 2 + 1);
    return res;
}
void update(long long left, long long right, long long start, long long end, long long delta, long long node)
{
    if (start <= left && right <= end)
    {
        segTree[node] += (right - left + 1) * delta;
        lazyTag[node] += delta;
        return;
    }
    long long mid = (left + right) / 2;
    if (left != right)
        pushDown(left, right, mid, node);
    if (start <= mid)
        update(left, mid, start, end, delta, node * 2);
    if (end > mid)
        update(mid + 1, right, start, end, delta, node * 2 + 1);
    segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
    return;
}
int main()
{
    long long i, opt, x, y, k, out;
    memset(lazyTag, 0, sizeof(lazyTag));
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        cin >> oriData[i];
    build(1, n, 1);
    for (i = 0; i < m; i++)
    {
        cin >> opt;
        if (opt == 1)
        {
            cin >> x >> y >> k;
            update(1, n, x, y, k, 1);
        }
        else if (opt == 2)
        {
            cin >> x >> y;
            out = getSum(1, n, x, y, 1);
            cout << out << endl;
        }
    }
    return 0;
}