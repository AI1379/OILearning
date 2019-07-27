#include<bits/stdc++.h>
using namespace std;
queue<int> w[110];
queue<int> c[110];
queue<int> t;
int m,n;
int f[110][110][110];
int main(){
	int tmp[110],x,y,c,i,j,k;
	cin>>n>>m;
	memset(tmp,0,sizeof(tmp));
	for(i=1,j=1;i<=n;i++){
		cin>>x>>y>>c;
		if(tmp[y/x]==0){
			w[j].push(c);
			c[j].push(x*x+y*y);
			tmp[y/x]=j;
			j++;
		}
		else{
			w[tmp[y/x]].push(c);
			c[tmp[y/x]].push(x*x+y*y);
		}
	}
	for(i=1;i<=n;i++){
		for(j=c[i].front();j<=m;j++){
			x=w[i].size();
			f[i][j][1]=f[i-1][j][1];
			for(k=1;k<=x;k++){
				f[i][j][k]=max(f[i][j][k],f[i][j][])
			}
		}
	}
}
