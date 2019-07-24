#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=2000;
void read(LL &x)
{
	LL s=0,t=1; char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') t=-1; c=getchar(); }
	while(c>='0'&&c<='9') { s=s*10+c-'0'; c=getchar(); }
	x=s*t; return ;
}
LL love[maxn];
LL pow2[100];
LL len,T;
LL num,l,r;
int main()
{
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	love[++len]=0; pow2[0]=1;
	for(LL i=1;i<=60;i++)
		pow2[i]=pow2[i-1]*2;
	for(LL i=1;i<=59;i++)
	{
		num=pow2[i+1]-1;
		for(LL j=0;j<i;j++)
			if(num-pow2[j]>0)
				love[++len]=num-pow2[j];
	}
	sort(love+1,love+len+1);
	read(T);
	while(T--)
	{
		LL ans=0;
		read(l); read(r);
		for(LL i=1;i<=len;i++)
		{
			LL k=love[i];
			if(k>r) break;
			if(k>=l&&k<=r) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
input1:
4
5 10
2015 2015
1 1000000000000000000
520520520 131413141314
output1:
2
1
493
111
*/
