#include<cstdio>
#include<cstring>
using namespace std;
const int mod=1e8+7;
int f[310][310][310],n,m,T;
int dfs(int now,int sum,int min)
{
	if(!now)
	{
		if(!sum)
			return 1;
		return 0;
	}
	if(sum<=0&&min!=0)
		return 0;
	if(sum<=0&&!min)
		return 1;
	if(min*now>sum)
		return 0;
	if(f[now][sum][min]!=-1)
		return f[now][sum][min];
	f[now][sum][min]=0;
	for(int j=min;j<=sum;++j)
	{
		int num=dfs(now-1,sum-j,j)%mod;
		f[now][sum][min]=(f[now][sum][min]+num)%mod;
	}
	return f[now][sum][min];
}
int main()
{
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	scanf("%d",&T);
	memset(f,-1,sizeof(f));
	for(int ii=1;ii<=T;++ii)
	{
		scanf("%d%d",&m,&n);
		printf("%d\n",dfs(n,m,0));
	}
	return 0;
}
