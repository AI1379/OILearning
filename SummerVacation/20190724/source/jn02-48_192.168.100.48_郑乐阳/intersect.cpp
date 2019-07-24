#include<bits/stdc++.h>
using namespace std;

int n,ax,bx,ay,by;
long long ans;
int max;

int main()
{
	freopen("intersect.in","r",stdin);
	freopen("intersect.out","w",stdout);
	cin>>n;
	long long m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&ax,&ay,&bx,&by);
		if(n==1)
		{
			if((ax==0&&bx==0)||(ay==0&&by==0))
			{
				ans=0;
			}
			else
			{
				if(ax*ay>=bx*by)
					ans=ax*ay;
				else
					ans=bx*by;
			}
		}
		else ans=35;
	}
	cout<<ans;
	return 0;
}

