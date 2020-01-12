//数组开大一点
#include<bits/stdc++.h>
using namespace std;
const int maxn=200;
const int maxp=60000;
const int inf=0x3f3f3f3f;
void read(int &x)
{
	int s=0,t=1; char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') t=-1; c=getchar(); }
	while(c>='0'&&c<='9') { s=s*10+c-'0'; c=getchar(); }
	x=s*t; return ;
}
int n,m,p,k,t,u,v,ans1=inf,ans2=inf;
int f[maxp+10];

void bb01(int x,int y)	//x:energy/momey, y:体积
{
	for(int i=p;i>=x;i--)
		f[i]=min(f[i],f[i-x]+y);
}

void bb02(int x,int y)	//x:energy/momey, y:体积
{
	for(int i=ans1;i>=x;i--)
		f[i]=min(f[i],f[i-x]+y);
}

int main()
{
	freopen("z.in","r",stdin);
	freopen("z.out","w",stdout);
	read(n); read(m); read(p); read(k);
	memset(f,inf,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		read(t), read(u), read(v);
		int po=1;
		while(v>po)
			bb01(t*po,u*po),
			v-=po, po*=2;
		bb01(t*v,u*v);
	}
	for(int i=p;i<=maxp;i++)
		ans1=min(ans1,f[i]);
	printf("%d\n",ans1);
	memset(f,inf,sizeof(f));
	f[0]=0;
	for(int i=1;i<=m;i++)
	{
		read(t), read(u), read(v);
		int po=1;
		while(v>po)
			bb02(t*po,u*po),
			v-=po, po*=2;
		bb01(t*v,u*v);
	}
	for(int i=ans1;i<=k;i++)
		ans2=min(ans2,f[i]);
	if(ans2==inf) printf("FAIL\n");
	else printf("%d\n",ans2);
	return 0;
}
/*
input:
5 3 34 34
1 4 1
9 4 2
5 3 3
1 3 3
5 3 2
3 4 5
6 7 5
5 3 8
*/
