//Q3:z.Coded by Yjq.
#include<bits/stdc++.h>
using namespace std;
struct Swt{
	int ti;
	int ui;
	int vi;
}swt[202];
struct Bx{
	int xi;
	int yi;
	int zi;
}bx[202];
int n,m,p,k,f[50004]; 
int main(){
	freopen("z.in","r",stdin);
	freopen("z.out","w",stdout);
	memset(f,0x3f3f3f3f,sizeof(f));
	cin>>n>>m>>p>>k;
	for(int i=1;i<=n;i++){
		cin>>swt[i].ti>>swt[i].ui>>swt[i].vi;
	}
	for(int i=1;i<=m;i++){
		cin>>bx[i].xi>>bx[i].yi>>bx[i].zi;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=swt[i].vi;j++){
			for(int k=p;k>=swt[i].ti;k--){
				f[k]=min(f[k],f[k-swt[i].ti]+swt[i].ui);
			}
		}
	}
	cout<<f[p]<<endl;
	memset(f,0x3f3f3f3f,sizeof(f));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=bx[i].zi;j++){
			for(int a=k;a>=bx[i].yi;k--){
				f[a]=min(f[a],f[a-swt[i].ti]+swt[i].ui);
			}
		}
	}
	cout<<f[k]<<endl;
	return 0;
}
