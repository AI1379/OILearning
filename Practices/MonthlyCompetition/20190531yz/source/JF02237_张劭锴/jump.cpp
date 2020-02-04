#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,ans=0,s=1,maxx=0,z;
	cin>>n;
	for(int u=1;u<=n;u++) cin>>a[u];
	while(s<n){
		if(s+a[s]>n){
			ans++;
			break;
		}
		if(s+a[s]+a[s+a[s]]>=n){
			ans+=2;
			break;
		} 
		for(int i=s+1;i<=s+a[s];i++){
			if(a[i]>=maxx){
				maxx=a[i];
				z=i;
			}
		}
		if(a[s]>=maxx) s+=a[s],ans++;
		else s=z+a[z],ans+=2;
	}
	cout<<ans;
	return 0;
} 
