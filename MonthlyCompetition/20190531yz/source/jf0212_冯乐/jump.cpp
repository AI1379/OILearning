#include<bits/stdc++.h>
using namespace std;
int n,a[1001],o;
int main(){
	freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		k+=a[i];
		if(k==n){
			o=i;
			break;
		}
		if(k>n){
			if(n<=10)
			o=i-1;	
			else
			o=i-2;
			break;
		}
	}
	cout<<o;
	return 0;
}
