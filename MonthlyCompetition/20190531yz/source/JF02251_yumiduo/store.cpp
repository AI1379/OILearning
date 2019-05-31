#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,zong,maxx,ans;
void jiandan()
{
	int to=max(max(a,30),max(b,c));
	for(int j=0;j<=to;j++)
	{
		for(int k=0;k<=to;k++)
		{
			//cout<<i+j+2*k<<" "<<i+2*j+k<<" "<<i<<endl;
			if(c+j+2*k<=a&&c+2*j+k<=b&&c<=c)
			{
				zong=c+j+k;
				maxx=max(c,max(j,k));
				if(zong-maxx>=maxx-1)
				ans=max(ans,zong);
				else
				ans=max(ans,(zong-maxx)*2+1);
			}
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("store.in","r",stdin);
	freopen("store.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d%d%d",&a,&b,&c);
		if(a<=100&&b<=100&&c<=100)
		jiandan();
		else
		cout<<(int)max(c+(int)(min(a,b)-c)/1.5,(int)min(a,b)/1.5+min(a,b)-c);
	}
	return 0;
}
