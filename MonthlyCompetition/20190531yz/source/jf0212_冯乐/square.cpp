#include<bits/stdc++.h>
using namespace std;
double n;
int k;
double f;
double a,m,g;
int main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	cin>>n>>k;
	int f=n,l=4*k;
	if(k==1){
		cout<<fixed<<setprecision(3)<<2*n<<"　";
	    cout<<fixed<<setprecision(3)<<n<<"　";
	    cout<<fixed<<setprecision(3)<<n<<"　";
	    return 0;
	}
	for(int i=1;i<=l;i++){
		if(i%4==0){
			n=(n/2)*sqrt(2);
		}
		if(i%3==1)
		a=a+n;
		if(i%3==2)
		m=m+n;
		if(i%3==0)
	    g=g+n;
	}
	cout<<fixed<<setprecision(3)<<m+f/2<<"　";
	cout<<fixed<<setprecision(3)<<a<<"　";
	cout<<fixed<<setprecision(3)<<g<<"　";
	return 0;
}
