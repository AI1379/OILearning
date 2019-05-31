#include<bits/stdc++.h>
using namespace std;
double n,k;
double ans[4];
int main(){
	freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
	cin>>n>>k;
	double t=n/sqrt(2)*2;
	int p=1;
	for(int i=1;i<=k;i++){
		t=sqrt(2*pow(t/2,2));
		for(int j=1;j<=4;j++){
			if(p==4) p=1;
			ans[p]+=t;
			p++;
		}
	}
	for(int i=1;i<=3;i++){
		cout<<fixed<<setprecision(3)<<ans[i]<<" "; 
	}
	return 0;
}
