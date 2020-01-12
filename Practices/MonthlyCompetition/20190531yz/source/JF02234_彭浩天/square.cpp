#include<bits/stdc++.h>
using namespace std;
double td,A=0,M=0,G=0;
int n,k;
int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	scanf("%d%d",&n,&k);
	td=n;
	for(int i=1;i<=k;i++){
		if(i%3==1){
			A+=2*td;
			M+=td;
			G+=td;	
		}
		if(i%3==2){
			A+=td;
			M+=2*td;
			G+=td;	
		}
		if(i%3==0){
			A+=td;
			M+=td;
			G+=2*td;	
		}
		td=sqrt(td*td/2);	
	}
	printf("%.3f %.3f %.3f",&A,&M,&G);
 } 
