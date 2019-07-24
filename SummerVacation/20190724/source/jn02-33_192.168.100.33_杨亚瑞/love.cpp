#include<bits/stdc++.h>
using namespace std;int t[100000];
bool act(long long x)
{
	long long b=x;int count=0;
	while(b>0)
	{
	   if(b%2==0)
	   {
	   	count++;
	   }
	   b/=2;	
	   if(count>1)
	   	break;
	}
	return(count==1);
}
int main()
{
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	int n;int ans;int u=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ans=0;
		int L,R;
		cin>>L>>R;
		for(int i=L;i<=R;i++)
		{
			if(act(i))
			ans++;
		}
		t[u]=ans;
		u++;
	}
	for(int j=1;j<=n;j++)
	{
		cout<<t[j]<<endl;
	}
	return 0;
}
