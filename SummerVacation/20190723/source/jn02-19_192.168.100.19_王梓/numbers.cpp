#include<bits/stdc++.h>
using namespace std;
const int maxn=300;
const int mod=1e8+7;
void read(int &x)
{
	int s=0,t=1; char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') t=-1; c=getchar(); }
	while(c>='0'&&c<='9') { s=s*10+c-'0'; c=getchar(); }
	x=s*t; return ;
}
int f[maxn+10][maxn+10];
//f[i][j]:i个数字和为j的情况 
//f[i][j]=(有一个0)f[i-1][j]+(没有0)f[i][j-i]
int n,m,T;
int main()
{
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	for(int i=1;i<=maxn;i++) f[i][0]=1;
	for(int i=1;i<=maxn;i++)
		for(int j=1;j<=maxn;j++)
		{
			f[i][j]=f[i-1][j]%mod;
			if(j>=i) f[i][j]=(f[i][j]+f[i][j-i])%mod;
		}
	read(T);
	while(T--)
	{
		read(m); read(n);
		printf("%d\n",f[n][m]%mod);
	}
	return 0;
}
