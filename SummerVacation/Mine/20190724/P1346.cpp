#include<bits/stdc++.h>
using namespace std;
const int INF=0x7fffff;
//vector<int>path[210][210];
int path[210];
int arc[210][210],len[210];
bool visited[210];
int m,n;
int main(){
	int x,y,w,u,v,i,j,k,minl,end;
	memset(arc,0x7f,sizeof(arc));
	cin>>n>>u;
	for(i=0;i<n;i++){
		cin>>k;
		for(j=0;j<k;j++){
			cin>>x>>y;
			arc[i][x]=0;
			arc[x][i]=0;
			arc[i][y]=1;
			arc[y][i]=1;
		}
	}
	memset(path,0,sizeof(path));
	memset(visited,false,sizeof(visited));
	for(v=0;v<n;v++)
		len[v]=arc[u][i];
	visited[u]=true;
	for(v=1;v<n;v++){
		minl=INFINITY;
		for(w=0;w<n;w++){
			if(!visited[w]&&len[w]<minl){
				k=w;
				minl=len[w];
			}
		}
		visited[k]=true;
		for(w=0;w<n;w++){
			if(!visited[w]&&(minl+arc[k][w]<len[w])){
				len[w]=minl+arc[k][w];
				path[w]=k;
			}
		}
	}
	cout<<len[end];
	return 0;
}
