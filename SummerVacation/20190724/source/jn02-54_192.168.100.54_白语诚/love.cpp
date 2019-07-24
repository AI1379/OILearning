#include<bits/stdc++.h>
using namespace std;
int t;
long long ans,l,r,num=1,n,biao[1000];
int main()
{
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>l>>r;
		ans=0;
		num=1;
		for(int i=0;;i++)
		{
			if(num>=2*r)
			{
			n=i;
			biao[i]=num;
			break;
			}
			biao[i]=num;
			num=num*2;
	}
     	for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				if(l<=biao[i]-biao[j]-1&&biao[i]-biao[j]-1<=r)
				{
					long long di=biao[i]-1;
					if(di>2*biao[j])
					{
					ans++;
			        }
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
