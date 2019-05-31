#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[5000],f[5000];
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		f[i]=2147483647;
	}
	for(int i=0;i<n;i++){
		t=a[i]+i;
		for(int j=i+1;j<=t;j++){
			f[j]=min(f[j],f[i]+1);
		}
	}
	cout<<f[n-1];
	return 0;
}
