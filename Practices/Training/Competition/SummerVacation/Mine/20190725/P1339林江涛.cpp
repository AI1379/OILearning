#include<bits/stdc++.h>
using namespace std;
int t,c,ts,te;
int arc[2510][2510];
int main(){
	priority_queue<pair<int,int> >q;
	int d[2510];
	int re,rs,ci,i,x,y,z,inf;
	bool visited[2510];
	memset(arc,0x7f,sizeof(arc));
	memset(d,0x7f,sizeof(d));
	memset(visited,0,sizeof(visited));
	inf=d[0];
	cin>>t>>c>>ts>>te;
	for(i=0;i<c;i++){
		cin>>rs>>re>>ci;
		arc[rs][re]=ci;
		arc[re][rs]=ci;
	}
	d[ts]=0;
	q.push(make_pair(0,ts));
	while(!q.empty()){
		x=q.top().second;
		q.pop();
		if(visited[x])
			continue;
		visited[x]=true;
		for(i=1;i<=t;i++){
			if(arc[x][i]!=inf){
				y=i;
				z=arc[x][i];
				if(d[y]>d[x]+z){
					d[y]=d[x]+z;
					q.push(make_pair(-d[y],y));
				}
			}
		}
	}
	cout<<d[te];
	return 0;
}
