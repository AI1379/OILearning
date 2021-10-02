#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define INF 2<<27
#define maxn 5000
using namespace std;
int n,k,m;
struct Edge
{
    int from,to,cap,flow,cost;
};
struct MCMF
{
    int from,n,m,s,t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int inq[maxn];
    int d[maxn];
    int p[maxn];
    int a[maxn];
    void init(int n)
    {
        this->n=n;
        for (int i=0;i<n;i++)
            G[i].clear();
        edges.clear();
    }
    void AddEdge(int from,int to,int cap,int cost)
    {
        edges.push_back((Edge){from,to,cap,0,cost});
        edges.push_back((Edge){to,from,0,0,-cost});
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    //其他成员函数 
    bool BellmanFord(int s,int t,int &flow,int &cost)
{
    for (int i=0;i<=t;i++)
        d[i]=-INF;
    memset(inq, 0,sizeof(inq));
    d[s]=0;inq[s]=1;p[s]=-1;a[s]=INF;
    
    queue<int> Q;
    Q.push(s);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        inq[u]=0;
        for (int i=0;i<G[u].size();i++)
        {
            Edge& e=edges[G[u][i]];
            if (e.cap> e.flow&&d[e.to]<d[u]+e.cost)
            {
                d[e.to]=d[u]+e.cost;
                p[e.to]=G[u][i];
                a[e.to]=min(a[u],e.cap-e.flow);
                if (!inq[e.to])
                {
                    Q.push(e.to);
                    inq[e.to]=1;
                }
            }
        }
    }
    if (d[t]==-INF) return 0;
    flow +=a[t];
    cost +=d[t]*a[t];
    int u=t;
    while (u!=s)
    {
        edges[p[u]].flow+=a[t];
        edges[p[u]^1].flow-=a[t];
        u=edges[p[u]].from;
    }
    return 1;
}
} net;

int mincost(int s,int t)
{
    int flow=0,cost=0;
    while(net.BellmanFord(s,t,flow,cost));
    return cost;
}
int xx[21],yy[21];
int main()
{
    scanf("%d%d",&n,&m);
    int ww=0;
    for (int i=1;i<=n;i++)
		xx[i]=++ww;
	for (int i=1;i<=m;i++)
		yy[i]=++ww;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            scanf("%d",&k);
            net.AddEdge(xx[i],yy[j],1,k);
        }
    for (int i=1;i<=n;i++)
        net.AddEdge(0,xx[i],2,0);  
    for (int i=1;i<=m;i++)
		net.AddEdge(yy[i],n+m+1,2,0);  
    printf("%d",mincost(0,n+m+1));
 
    return 0;
}