#include<bits/stdc++.h>
using namespace std;
long long j,a,T,sum,L,R;
int ans[10001];
int main()
{
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	cin>>T;
	for (int i=1;i<=T;i++)
	{
		cin>>L>>R;
		for (j=min(L,R);j<=max(L,R);j++)
		{
			a=j; sum=0;
			while(a!=0)
			{
				if (a%2==0) sum++;
				a/=2;
			}
			if (sum==1) ans[i]++;
		}
	}
	for (int i=1;i<=T;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
