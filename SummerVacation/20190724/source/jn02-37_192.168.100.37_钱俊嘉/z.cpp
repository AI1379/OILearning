#include<bits/stdc++.h>
using namespace std;
int n,m,p,k,t[201],u[201],v[201],x[201],y[201],z[201],f1[10001],f2[10001];
const int INF=1<<30;
int main(){
	freopen("z.in","r",stdin);
	freopen("z.out","w",stdout);
	int ans=INF/3;
	f1[0]=0;
	f2[0]=0;
	for(int i=1;i<=10000;i++) f1[i]=INF/3,f2[i]=INF/3;
	cin>>n>>m>>p>>k;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>u[i]>>v[i];
	}
	for(int i=1;i<=m;i++){
		cin>>x[i]>>y[i]>>z[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=10000;j>=t[i];j--){
			for(int o=0;o<=v[i];o++){	
				f1[j]=min(f1[j],f1[j-t[i]*o]+u[i]*o);
			}
		}
	}
	for(int i=p;i<=10000;i++){
		if(f1[i]==0) break;
		else ans=min(ans,f1[i]);
	}
	cout<<ans<<endl;
	for(int i=1;i<=m;i++){
		for(int j=10000;j>=x[i];j--){
			for(int o=0;o<=z[i];o++){
				f2[j]=min(f2[j],f2[j-x[i]*o]+y[i]*o);
			}
		}
	}
	int ans2=INF/3;
	for(int i=ans;i<=10000;i++){
		if(f2[i]==0) break;
		ans2=min(ans2,f2[i]);
	}
	if(ans2>k) cout<<"FAIL";
	else cout<<ans2;
	return 0;
}
