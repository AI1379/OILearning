#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("store.in","r",stdin);
	freopen("store.out","w",stdout);
	int T,a,b,c,ans;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(c<a&&c<b){
			ans+=c;
			a-=c;
			b-=c;
			if(a!=0&&b!=0)
			{
				printf("%d\n",ans+(a+b)/3);
			}
			else {
				printf("%d\n",ans);
			}
		}
		else if(c>a||c>b)
		{
			printf("%d\n",min(a,b));
		}
		else if(c>a&&c>b)
		{
			int num=min(a,b),sum=max(a,b);
			sum/=2;
			printf("%d",max(num,sum));
		}
	}
	return 0;
}
