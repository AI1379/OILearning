#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,a[5005],f[10005];
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	memset(f,127/3,sizeof(f));
	f[0]=f[1]=0;
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=a[i];j++)
			f[i+j]=min(f[i+j],f[i]+1);
	printf("%d",f[n]);
	return 0;
} 
