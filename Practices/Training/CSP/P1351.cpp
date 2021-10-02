#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
const int MAXM = 200010;
const int INF = 2147483647;
struct edge
{
    int to;
    int next;
};
edge edges[MAXM];
int numOfEdges = 0;
int adj[MAXN], weight[MAXN];
void addEdge(long long u, long long v)
{
    numOfEdges++;
    edges[numOfEdges].to = v, edges[numOfEdges].next = adj[u];
    adj[u] = numOfEdges;
}
int n;
int main()
{
    int i, x, y;
    cin >> n;
    for (i = 1; i <= n - 1; i++)
    {
        cin >> x >> y;
        addEdge(x, y);
        addEdge(y, x);
    }
    for (i = 1; i <= n; i++)
        cin >> weight[i];
    
}