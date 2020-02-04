#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int n,m,p,k,t[210],u[210],v[210],dp[210],q;
int a[210],b[210],c[210],f[210],ans1,ans2,ans3;
void zob(int x,int y){
	for(int i=p; i>=x*t[y]; i--) dp[i]=min(dp[i-x*t[y]]+x*u[y],dp[i]);
}
void zob1(int x,int y){
	for(int i=ans1; i>=x*a[y]; i--) f[i]=min(f[i-x*a[y]]+x*b[y],f[i]);
}
int main(){
	freopen("z.in","r",stdin);
	freopen("z.out","w",stdout);
	ans1=ans3=inf;
	scanf("%d%d%d%d",&n,&m,&p,&k);
	for(int i=1; i<=n; i++){
		scanf("%d%d%d",&t[i],&u[i],&v[i]);
		q+=(t[i]*v[i]);
	} 
	swap(q,p);
	for(int i=1; i<=p; i++) dp[i]=inf;
	for(int i=1; i<=n; i++){
		int two=1;
		while(two<=v[i]){
			zob(two,i);
			v[i]-=two;
			two<<=1;
		}
		zob(v[i],i);
	}
	for(int i=q; i<=p; i++) ans1=min(ans1,dp[i]);
	printf("%d\n",ans1);
	for(int i=1; i<=m; i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		ans2+=(a[i]*c[i]);
	} 
	swap(ans2,ans1);
	for(int i=1; i<=ans1; i++) f[i]=inf;
	for(int i=1; i<=m; i++){
		int two=1;
		while(two<=c[i]){
			zob1(two,i);
			c[i]-=two;
			two<<=1;
		}
		zob1(c[i],i);
	}
	for(int i=ans2; i<=ans1; i++) ans3=min(ans3,f[i]);
	if(ans3>k){
		cout<<"FAIL"; return 0;
	} 
	printf("%d",ans3);
	return 0;
}
