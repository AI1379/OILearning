//Coded by dst
#include<iostream>
#include<cstdio>
using namespace std;
int n,a,b,c,d,x[255],y[255],x0,y0;
char mp[300][300];
int main(){
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&y[i],&x[i]);
		a=min(a,x[i]);
		c=max(c,x[i]);
		b=min(b,y[i]);
		d=max(d,y[i]);
	}
	x0=-a;
	y0=-b;
	a=b=0;
	c+=x0,d+=y0;
	for(i=0;i<=c;i++)
		for(j=0;j<=d;j++)
			mp[i][j]='.';
	for(i=0;i<=c;i++)
		mp[i][y0]='|';
	for(i=0;i<=d;i++)
		mp[x0][i]='-';
	mp[x0][y0]='+';
	for(i=1;i<=n;i++)
		mp[x[i]+x0][y[i]+y0]='*';
	for(i=c;i>=0;i--)
		printf("%s\n",mp[i]);
	return 0;
} 
