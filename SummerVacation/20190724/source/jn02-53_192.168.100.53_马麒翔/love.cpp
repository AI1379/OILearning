#include<bits/stdc++.h>
using namespace std;
int ans=0;
int main()
{
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	int T;
	cin>>T;
	for(long long i=1;i<=T;i++)
	{
		long long l,r;
		cin>>l>>r;
		if(l>r)
		{
			cout<<0<<endl;
			break;
		}
		long long t=l,lenl=0;
		while(t!=0)
		{
			t/=2;
			lenl++;
		}
		t=r;
		long long lenr=0;
		while(t!=0)
		{
			t/=2;
			lenr++;
		}
//		cout<<lenl<<" "<<lenr<<endl; OK
		for(long long ii=lenl;ii<=lenr;ii++)
		{
			for(long long j=2;j<=ii;j++)
			{
				long long q=1;
				long long sum=0;
				for(long long k=ii;k>=1;k--)
				{
					if(k==j)
					{
						q*=2;
						continue;
					 } 
					 else
					 {
					 	sum+=q;
					 	q*=2;
					 }
//					 cout<<q<<endl; OK
//					 system("pause");
				}
				
//				cout<<sum<<endl;OK
				if(sum>=l && sum<=r)
				{
//					cout<<sum<<endl;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
