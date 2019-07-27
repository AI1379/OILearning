#include<bits/stdc++.h>
using namespace std;
struct side {
	int to;
	int next;
};
side edge[200001];
int head[100001];
int n,m;
bool visited[100001],in[100001];
queue<int>q;
int main() {
	int i,j,u,v,noe=0,ans=0;
	bool flag;
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=0; i<m; i++) {
		scanf("%d%d",&u,&v);
		noe++;
		edge[++noe].next=head[u];
		edge[noe].to=v;
		head[u]=noe;
		edge[++noe].next=head[v];
		edge[noe].to=u;
		head[v]=noe;
	}
	for(i=1; i<=n; i++) {
		if(!visited[i]) {
			flag=true;
			q.push(i);
			while(!q.empty()) {
				for(j=head[q.front()]; j!=0; j=edge[j].next) {
					if(!visited[edge[j].to]) {
						q.push(edge[j].to);
						visited[edge[j].to]=true;
					} else if(!in[edge[j].to]) flag=false;
				}
				in[q.front()]=true;
				q.pop();
			}
			if(flag) ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
