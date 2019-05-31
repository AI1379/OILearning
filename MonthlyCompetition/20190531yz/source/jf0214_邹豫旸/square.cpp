#include<bits/stdc++.h>
using namespace std;
double a[4],n;
int k,now=1;
int main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=k; i++){
		a[1]+=n,a[2]+=n,a[3]+=n,a[now]+=n;
		now++;
		if(now==4) now=1;
		n=0.5*n*0.5*n*2;
		n=sqrt(n);
	}
	for(int i=1; i<=3; i++) cout<<fixed<<setprecision(3)<<a[i]<<" ";
	return 0;
}
