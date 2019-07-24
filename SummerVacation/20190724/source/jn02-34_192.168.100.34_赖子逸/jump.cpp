#include<bits/stdc++.h>
using namespace std;
int h,m,w;
int wx[4]={1,0,-1,0},wy[4]={0,1,0,-1};
int q[90010][2]={0};
int ans=0;
int a[510][510],f,r;
bool b[501][501]={0};
void bfs(int i,int j){
	memset(q,0,sizeof(q));
	b[i][j]=1;
	f=0;r=1;
	q[1][0]=i;q[1][1]=j;
	while(f<r){
		f++;
		for(int y=0;y<4;y++)
			if(a[q[f][0]+wx[y]][q[f][1]+wy[y]]<=a[q[f][0]][q[f][1]]+m&&a[q[f][0]+wx[y]][q[f][1]+wy[y]]>=a[q[f][0]][q[f][1]]-m){
			     r++;
			     q[r][0]=q[f][0]+wx[y];
			     q[r][1]=q[f][1]+wy[y];
			     b[q[f][0]+wx[y]][q[f][1]+wy[y]]=1;
			}
	}
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>h>>w>>m;
	for(int i=1;i<=h;i++)
	    for(int j=1;j<=w;j++)
	        cin>>a[i][j];
	for(int i=1;i<=h;i++)
	    for(int j=1;j<=w;j++)
	        if(b[i][j]==0){
	        	bfs(i,j);
	        	ans+=1;
			}
	cout<<ans;
	return 0;
}
