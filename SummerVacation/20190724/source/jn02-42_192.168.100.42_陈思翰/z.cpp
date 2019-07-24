#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,p,k,t[105],u[105],v[105],x[105],y[105],z[105],f[105];
	cin>>n>>m>>p>>k;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>u[i]>>v[i];
    }
    for(int j=1;j<=m;j++){
    	cin>>x[j]>>y[j]>>z[j];
	}
	f[1]=1;
    for(int i=1;i<=n;i++){
    	for(int j=p;j>=t[i];j--){
    		for(int k=1;k<=v[i];k++){
    			f[j]=max(f[j],f[j-k*t[i]]+k*u[i]);
			}
		}
	} 
	cout<<f[p]<<endl;
	cout<<"FAIl";            
	return 0;
}
