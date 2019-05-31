#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	int n,k,t=0;
	double a=0,b=0,c=0,tn=0;
	cin>>n>>k;
	tn=n;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=3;j++){
			switch(t){
				case 0:a+=tn;break;
				case 1:b+=tn;break;
				case 2:c+=tn;break;
			}
			t++;
			t%=3;
		}
		tn=tn*sqrt(2)/2;
	}
	printf("%.3lf %.3lf %.3lf",a,b,c);
	return 0;
}
