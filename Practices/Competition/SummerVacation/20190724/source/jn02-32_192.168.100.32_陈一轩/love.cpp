#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	int t,c=0,tot=0,tmp;
	long long l,r;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		tot=0;
		cin>>l>>r;
		for(int i=l;i<=r;i++)
		{
			tmp=i;
			c=0;
			while(tmp>0)
			{
				if(tmp%2==0)
				{
					c++;
					tmp=tmp/2;
				}
				if(c>1)break;
				if(tmp%2==1)tmp=(tmp-1)/2;
			}
			if(c==1)tot++;		
		}
		cout<<tot<<endl;
	}
	return 0;
}
