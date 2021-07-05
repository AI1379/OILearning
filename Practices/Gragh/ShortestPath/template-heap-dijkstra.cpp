//原文地址https://www.cnblogs.com/jvruo/p/10337445.html

#include <bits/stdc++.h>
#define N 2510 //点数
#define M 6210 //边数
using namespace std;
int heap[N], dis[N], pos[N];
//heap为堆、dis[i]表示源点到i的距离
//pos[i]表示i号点在堆中的位置、即heap[pos[i]]=i;
int frt[N], nxt[M << 1], v[M << 1], w[M << 1];
//邻接链表存图
int n, m, tot, p, t;
inline int swap(int &x, int &y)
{
    x ^= y, y ^= x, x ^= y;
} //手写的交换函数
inline void add(int x, int y, int z)
{
    v[++tot] = y;
    w[tot] = z;
    nxt[tot] = frt[x];
    frt[x] = tot;
} //加一条x到y长度为z的边
inline void siftdown(int x)
{ //维护堆，将堆中第i号点往下移
    int i, j, k;
    while (x <= n >> 1)
    {
        i = heap[x];
        j = heap[x << 1];
        k = heap[x << 1 | 1];
        if (x << 1 | 1 <= n) //如果当前点有两个儿子
        {
            if (dis[i] > dis[j] || dis[i] > dis[k])
            {                        //当前点比儿子打，说明需要维护
                if (dis[j] < dis[k]) //将较小儿子与父亲交换
                    swap(heap[x], heap[x << 1]),
                        swap(pos[i], pos[j]), x <<= 1;
                else
                    swap(heap[x], heap[x << 1 | 1]),
                        swap(pos[i], pos[k]), x = x << 1 | 1;
            }
            else
                return; //当前点已经是最小的了
            //因此不需要维护，直接跳出
        }
        else if (dis[i] > dis[j]) //若当前节点只有1个儿子
            swap(heap[x], heap[x << 1]),
                swap(pos[i], pos[j]), x <<= 1;
    }
}
inline void siftup(int x)
{ //维护堆，将堆中第i号点往上移
    while (x > 1)
    {
        if (dis[heap[x]] < dis[heap[x >> 1]]) //若父亲比自己打
            swap(pos[heap[x]], pos[heap[x >> 1]]), swap(heap[x], heap[x >> 1]), x >>= 1;
        //需要维护，交换
        else
            return; //不需要维护，跳出
    }
}
inline int pop()
{ //弹出堆顶元素并维护
    int t = heap[1];
    pos[t] = 0;
    heap[1] = heap[n];
    n--;
    pos[heap[1]] = 1;
    siftdown(1);
    return t;
}
void dijkstra()
{
    dis[p] = 0;
    tot = n;
    swap(heap[p], heap[1]);
    swap(pos[heap[p]], pos[heap[1]]);
    //初始化
    while (n)
    {
        int k = pop(); //取堆顶元素
        for (int i = frt[k]; i; i = nxt[i])
            if (dis[v[i]] > dis[k] + w[i])
                dis[v[i]] = dis[k] + w[i], siftup(pos[v[i]]);
        //进行松弛操作并维护堆
    }
}
int main()
{
    int x, y, z;
    memset(dis, 0x7f, sizeof(dis));
    //初始化
    cin >> n >> m >> p >> t;
    for (int i = 1; i <= n; i++)
        heap[i] = i, pos[i] = i; //初始化
    while (m--)
    {
        cin >> x >> y >> z;
        add(x, y, z); //建图
    }
    dijkstra(); //调用最短路算法
    cout << dis[t];
    //愉快输出答案
    return 0;
}