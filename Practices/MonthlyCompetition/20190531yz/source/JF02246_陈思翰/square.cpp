#include<bits/stdc++.h>
using namespace std;
long double n,a=0,b=0,c=0;
int k,j=1;
int main(){
	freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=k;i++){
    	while(j<=i*4){
    		if(j%3==1)a+=n;
    		else if(j%3==2)b+=n;
    		else if(j%3==0)c+=n;
    		j++;
			}
		n=sqrt(n*n/2.0);
	}
	cout<<fixed<<setprecision(3)<<a<<" "<<b<<" "<<c;
	return 0;
} 
