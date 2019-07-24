#include<bits/stdc++.h>
using namespace std;
long long t,a[61],num,ans;
long long l,r;
int pk()
{
	long long summ=0,i=1,k=1;
	while(i<=num)
	{
		summ+=a[i]*k;
		k*=2;
		i++;
	}
	if(summ<=r)return 1;
	else return -1;
}
void er(long long x)
{
	num=0;
	do
	{
		a[++num]=x%2;
		x/=2;
    }while(x!=0);
}
int main()
{
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%lld%lld",&l,&r);
		if(l>r)swap(l,r);
		ans=0;
		if(l==1)l=2;
		er(l);
		while(pk()==1)
		{
			long long i=num;
			while(a[i]!=0&&i>1)i--;
			if(i==1)
			{
				a[num]=0;
				a[++num]=1;
				for(long long j=num-2;j>=1;--j)a[j]=1;
			}
			else
			{
			    a[i]=1;a[i-1]=0;
			    for(long long j=i-2;j>=1;--j)a[j]=1;
			}
			ans++;
		}
		printf("%lld\n",ans);
	}
}
