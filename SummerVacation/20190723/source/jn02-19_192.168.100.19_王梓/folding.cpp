#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
void read(int &x)
{
	int s=0,t=1; char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') t=-1; c=getchar(); }
	while(c>='0'&&c<='9') { s=s*10+c-'0'; c=getchar(); }
	x=s*t; return ;
}
int a,b,a2,b2,ans=inf;
int main()
{
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	read(a); read(b); read(a2); read(b2);
	if(a>=a2&&b>=b2)
	{
		int a1=a,b1=b,num=0;
		while(a1>a2) a1=(a1+1)/2,num++;
		while(b1>b2) b1=(b1+1)/2,num++;
		ans=min(ans,num);
	}
	if(b>=a2&&a>=b2)
	{
		swap(a,b);
		int a1=a,b1=b,num=0;
		while(a1>a2) a1=(a1+1)/2,num++;
		while(b1>b2) b1=(b1+1)/2,num++;
		ans=min(ans,num);
	}
	if(ans==inf) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
