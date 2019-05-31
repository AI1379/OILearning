#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	int n,k;
	long double a=0,b=0,c=0;
	cin>>n>>k;
	long double len=n;
	for(int i=1;i<=(4*k);i++)
	{
		if(i%4==1&&i!=1)
		{
			len/=2;
			len=len*len*2;
			len=sqrt(len);
		}
		 if(i%3==1)
		{
			a+=len;
		}
		else if(i%3==2)
		{
			b+=len;
		}
		else if(i%3==0)
		{
			c+=len;
		}
	}
	cout<<fixed<<setprecision(3)<<a<<" "<<b<<" "<<c;
	return 0;
 } 
