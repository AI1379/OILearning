#include<bits/stdc++.h>
using namespace std;
int f[10001],a[5001];
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=5001;
	}
	f[1]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			if(f[i+j]>f[i]+1)f[i+j]=f[i]+1;
		}
	}
	cout<<f[n];
	return 0;
}
