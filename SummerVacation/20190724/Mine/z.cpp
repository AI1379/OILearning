#include<bits/stdc++.h>
using namespace std;
int t[210],u[210],v[210],x[210],y[210],z[210];
int n,m,p;
bool judge(int s){
	int f[110][110];
	int i,j,k=1;
	memset(f,0,sizeof(f));
	for(i=1;i<=n;i++){
		for(j=0;j<=s;j++){
			for(k=0;k<=v[i];k++){
				f[i][j]=max(f[i][j],f[i][j-k*u[i]]+k*t[i]);
			}
		}
	}
	cout<<f[n][s]<<endl;
	return f[n][s]>=p;
}return f[n][s]>=p;
}
int main(){
	int l,r,mid,i,j,k,ans1;
	l=0;
	r=0;
	cin>>n>>m>>p>>k;
	for(i=1;i<=n;i++){
		cin>>t[i]>>u[i]>>v[i];
		r+=(u[i]*v[i]);
	}
	while(l<r){
		cout<<l<<' '<<r<<endl;
		mid=(l+r)/2;
		if(judge(mid))r=mid;
		else l=mid+1;
	}
	cout<<r;
	for(i=1;i<=n;i++){
		cin>>t[i]>>u[i]>>v[i];
		r+=(u[i]*v[i]);
	}
	while(l<r){
		cout<<l<<' '<<r<<endl;
		mid=(l+r)/2;
		if(judge(mid))r=mid;
		else l=mid+1;
	}
	return 0;
}
