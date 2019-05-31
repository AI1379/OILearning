#include<bits/stdc++.h>
using namespace std;
double n,a1,a2,a3;
long long k,i;
int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	cin>>n>>k;
	for (i=1;i<=k;i++)
	{
		if (i%3==1)
		{
			a1+=n;
			a2+=n;
			a3+=n;
			a1+=n; 
			n=sqrt(0.5*n*n);
			continue;
		}
		if (i%3==2)
		{
			a1+=n;
			a2+=n;
			a3+=n;
			a2+=n;
			n=sqrt(0.5*n*n);
			continue;
		}
		if (i%3==0)
		{
			a1+=n;
			a2+=n;
			a3+=n;
			a3+=n;
			n=sqrt(0.5*n*n);
			continue;
		}
	}
	cout<<fixed<<setprecision(3)<<a1;
	cout<<" ";
	cout<<fixed<<setprecision(3)<<a2;
	cout<<" ";
	cout<<fixed<<setprecision(3)<<a3;
	return 0;
} 
