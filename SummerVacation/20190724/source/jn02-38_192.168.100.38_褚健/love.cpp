#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
typedef unsigned long long ULL;
using namespace std;

ULL l,r,ans;
int T,lenl,lenr,lent,first_zero_l,first_zero_r,time_zero_r;
int binl[100],binr[100];

int main()
{
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(binl,0,sizeof(binl));
		memset(binr,0,sizeof(binr));
		l=r=ans=lenl=lenr=lent=first_zero_l=first_zero_r=time_zero_r=0;
		scanf("%lld%lld",&l,&r);
		if(r<l) { printf("0\n"); continue; }
		lenl=int(log2(l))+1,lenr=int(log2(r))+1;
		if(lenl<lenr)
		{
			for(int i=lenl+1;i<lenr;i++)
				ans+=ULL(i-1);
			lent=lenl-1;
			while(l)
			{
				binl[lent--]=l%2;
				l/=2;
			}
			for(int i=0;i<lenl;i++)
				if(binl[i]==0) { first_zero_l=i+1;break; }
			if(first_zero_l!=0)
				ans+=(lenl-first_zero_l+1);
			lent=lenr-1;
			while(r)
			{
				binr[lent--]=r%2;
				r/=2;
			}
			for(int i=0;i<lenr;i++)
				if(binr[i]==0){ first_zero_r=i+1;break; }
			if(first_zero_r==0) first_zero_r=lenr+1;
				ans+=(first_zero_r-2);
			for(int i=0;i<lenr;i++)
				if(binr[i]==0) time_zero_r++;
			if(time_zero_r==1) ans++;
			printf("%d\n",ans);
		}
		else
		{
			lent=lenl-1;
			while(l)
			{
				binl[lent--]=l%2;
				l/=2;
			}
			for(int i=0;i<lenl;i++)
				if(binl[i]==0) { first_zero_l=i+1;break; }
			lent=lenr-1;
			while(r)
			{
				binr[lent--]=r%2;
				r/=2;
			}
			for(int i=0;i<lenr;i++)
				if(binr[i]==0){ first_zero_r=i+1;break; }
			if(first_zero_r==0) first_zero_r=lenr+1;
			if(first_zero_l!=0)
				ans+=(first_zero_r-first_zero_l);
			for(int i=0;i<lenr;i++)
				if(binr[i]==0) time_zero_r++;
			if(time_zero_r==1) ans++;
			printf("%d\n",ans);
		}
	}
}
