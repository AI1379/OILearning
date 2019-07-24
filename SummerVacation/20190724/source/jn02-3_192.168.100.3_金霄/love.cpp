#include<bits/stdc++.h>
using namespace std;

long long n,L,R,ans[10001],k;
bool flag=false,j;

void q(long long  x,long long  y,long long num)
{
	for(long long i=x;i<=y;i++)
	{
		flag=false;
		j=false;
		k=i;
		while(k>=2)
		{
			if(k%2==0&&flag==true)
			{
			j=false;
			break;

			}
				
			else if(k%2==0)
			{
				flag=true;
				j=true;
			}
			k=k/2;
		}
		if(flag==true&&j==true)ans[num]++;
	}
}

int  main()
{
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	cin>>n;
	for(long long  i=1;i<=n;i++)
	{
		cin>>L>>R;
		q(L,R,i);
		cout<<ans[i]<<endl;
	}
	return 0;
}
