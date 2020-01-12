#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main() {
	int m,n,i,opt,x;
	freopen("T1.in","r",stdin);
	freopen("T2.out","w",stdout);
	cin>>n>>m;
	memset(a,0,sizeof(a));
	for(i=0;i<n;i++){
		cin>>x;
		a[x]++;
	}
	for(i=0;i<m;i++){
		cin>>opt>>x;
		if(opt==1){
			a[x]--;
		}
		else if(opt==2){
			if(a[x]<=0)cout<<'0'<<endl;
			else cout<<a[x]<<endl;
		}
	}
	return 0;
}
