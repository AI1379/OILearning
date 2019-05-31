#include<bits/stdc++.h>
using namespace std;
const int maxn=5000;
const int inf=0x3f3f3f3f;
void read(int &x)
{
	int s=0,t=1; char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') t=-1; c=getchar(); }
	while(c>='0'&&c<='9') { s=s*10+c-'0'; c=getchar(); }
	x=s*t; return ;
}
int n;
int a[maxn+10];
int f[maxn+10];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	memset(f,inf,sizeof(f));
	f[1]=0;
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			if(j+a[j]>=i)
				f[i]=min(f[i],f[j]+1);
	cout<<f[n]<<endl;
	return 0;
}
