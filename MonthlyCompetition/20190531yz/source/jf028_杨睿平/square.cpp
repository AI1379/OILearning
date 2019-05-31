#include <bits/stdc++.h>
using namespace std;
int k;
double ay=0,mi=0,ge=0;
int ta;
double now,n;
int main(){
	freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    cin>>n;
    scanf("%d%d",&k);
    ta=0;
    int i,j;
    double t;
    now=n;
    for(i=1;i<=k;i++){
    	for(j=1;j<=4;j++){
    		if(ta==0){
    			ay+=now;
			}else{
				if(ta==1){
					mi+=now;
				}else{
					if(ta==2){
						ge+=now;
					}
				}
			}
			ta=(ta+1)%3;
		}
		t=now/2;
		now=sqrt(t*t+t*t);
	}
	printf("%.3f ",ay);
	printf("%.3f ",mi);
	printf("%.3f",ge);
	return 0;
} 
