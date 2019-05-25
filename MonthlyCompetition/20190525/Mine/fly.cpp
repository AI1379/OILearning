#include<bits/stdc++.h>
using namespace std;
int ditu[1001][2];
int f[2][100001];
int m,n,k;
int main(){
	int i,j,p;
	bool flag;
	memset(ditu,true,sizeof(ditu));
	memset(f,0,sizeof(f));
	freopen("fly.in","r",stdin);
	freopen("fly.out","w",stdout);
	cin>>m>>n>>k;
	for(i=1;i<=k;i++){
		cin>>ditu[i][0]>>ditu[i][1];
	}
	f[1][1]=1;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(i==1&&j==1)
				continue;
			flag=true;
			for(p=1;p<=k;p++){
				if(ditu[p][0]==i&&ditu[p][1]==j){
					flag=false;
				}
			}
			if(flag)
				f[1][j]=(f[0][j]+f[1][j-1])%998244353;
		}
		for(j=0;j<=n;j++){
			f[0][j]=f[1][j];
			f[1][j]=0;
		} 
	}
	cout<<f[0][n];
	return 0;
}
