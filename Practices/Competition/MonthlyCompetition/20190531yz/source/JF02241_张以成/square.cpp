#include<bits/stdc++.h>
using namespace std;
double n,k,tn,top,ayu,mit,gen;
int i,t;
int main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	cin>>n>>k;
	tn=n;
	top=4*k-1;
	while(i<=top){
		printf("%10.3f %10.3f %10.3f \n",ayu,mit,gen);
		if(i%4==0&&i!=0){
			tn=sqrt(tn*tn/2);
		}
		if(t==0){
			ayu+=tn;
			t=1;
			i++;
			continue;
		}
		if(t==1){
			mit+=tn;
			t=2;
			i++;
			continue;
		}
		if(t==2){
			gen+=tn;
			t=0;
			i++;
			continue;
		}
	}
	printf("%.3f %.3f %.3f",ayu,mit,gen);
	return 0;
} 
