#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	long long n,o;
	short nb=1;//a=1,b=2,c=3
	double a=0.0,b=0.0,c=0.0,len;
	cin>>len;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=4;j++)
		{
			if(nb==1)
			{
				nb=2;
				a+=len;
			}
			else if(nb==2)
			{
				nb=3;
				b+=len;
			}
			else if(nb==3)
			{
				nb=1;
				c+=len;
			}
		}
		len=sqrt((len/2.0)*(len/2.0)+(len/2.0)*(len/2.0));
	}
	cout<<fixed<<setprecision(3)<<a<<" "<<b<<" "<<c<<endl;
	return 0;
 } 
