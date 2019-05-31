#include<bits/stdc++.h>
using namespace std;
double Ayumi,Mitsuhiko,Genta,now,sqrt2;
int n,k;
int main(){
	int i,j;
	sqrt2=sqrt(2);
	cin>>n>>k;
	k*=4;
	now=(double)(n);
	Ayumi=now;
	Mitsuhiko=0.000;
	Genta=0.000;
	for(i=1;i<k;i++){
		if(i%4==0){
			now=now/sqrt2;
		}
		if(i%3==0)
			Ayumi+=now;
		else if(i%3==1)
			Mitsuhiko+=now;
		else
			Genta+=now;
	}
	printf("%-0.3lf %-0.3lf %-0.3lf",Ayumi,Mitsuhiko,Genta);
	return 0;
}
