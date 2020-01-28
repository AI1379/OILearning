//Coded by dst 
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int m,n,p,q,fct[100]={1},ans=2e9;
int calc(int x,int y){
	int res;
	for(res=0;x>fct[res]*y;res++);
	return res;
}
int main(){
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	for(int i=1;i<=30;i++)
		fct[i]=fct[i-1]<<1;
	scanf("%d%d%d%d",&m,&n,&p,&q);
	if(m>=p&&n>=q)
		ans=calc(m,p)+calc(n,q);
	if(m>=q&&n>=p)
		ans=min(ans,calc(m,q)+calc(n,p));
	if((m<p||n<q)&&(m<q||n<p))
		printf("-1");
	else
		printf("%d",ans);
	return 0;
} 
