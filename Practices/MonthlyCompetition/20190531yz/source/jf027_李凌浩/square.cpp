#include<bits/stdc++.h>
using namespace std;
int n,k;double a,b,c,m;
int main(){
	freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
	cin>>n>>k;
	m=n;
	for(int i=1;i<=4*k;i++){
		if(i%4==1&&i>4){
			m=sqrt(m/2.0*m);
		}
		if(i%3==1){
			a+=m;
		}
		if(i%3==2){
			b+=m;
		}
		if(i%3==0){
			c+=m;
		}
	}
	printf("%.3f %.3f %.3f",a,b,c);
	return 0;
}
