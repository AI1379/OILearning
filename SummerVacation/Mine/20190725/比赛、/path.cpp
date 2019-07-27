#include<bits/stdc++.h>
using namespace std;
int t,c;
int f[10001][20001];
void floyd() {
	int k,i,j;
	for (k = 1; k <= t; k++) {
		for (i = 1; i <= t; i++) {
			for (j = 1; j <= t; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
}
int main() {
	int b[15];
	int k,x,y,z,i,s,e,ans=0;
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	cin>>t>>c>>k>>s>>e;
	b[0]=s;
	b[k+1]=e;
	memset(f,0x3f,sizeof(f));
	for(i=1; i<=t; i++)f[i][i]=0;
	for(i=0; i<c; i++) {
		cin>>x>>y>>z;
		f[x][y]=z;
	}
	for(i=0; i<=t; i++) {
		for(int j=0; j<=t; j++)
			cout<<f[i][j]<<' ';
		cout<<endl;
	}
	for(i=1; i<=k; i++)cin>>b[i];
	floyd();
	if(k==0)cout<<f[s][e];
	else {
		for(i=1; i<=k+1; i++)
			ans+=f[b[i-1]][b[i]];
		cout<<ans;
	}
	cout<<endl;
	for(i=0; i<=t; i++) {
		for(int j=0; j<=t; j++)
			cout<<f[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}
