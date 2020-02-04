#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	double ans1=0,ans2=0,ans3=0;
	int a,b,c;
	int n;
	double k;
	double ba[2000];
	scanf("%d%lf",&n,&k);
	ba[0]=n;
	for(int i=1;i<k;i++){
		ba[i]=sqrt(ba[i-1]*ba[i-1])/sqrt(2);
	}
	for(int i=0;i<k;i++){
		ans1+=ba[i];
		ans2+=ba[i];
		ans3+=ba[i];
		if(i%3==0){
			ans3+=ba[i];
		}else if(i%3==1){
			ans2+=ba[i];
		}else{
			ans1+=ba[i];
		}
	}
	printf("%.3lf %.3lf %.3lf",ans3,ans2,ans1);
	return 0;
} 
