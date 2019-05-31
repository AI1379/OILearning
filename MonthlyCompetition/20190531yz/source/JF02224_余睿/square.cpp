#include<iomanip>
#include<iostream>
#include<cstdio>
using namespace std;
#define two 1.4142135623730950488016887242097
long double cen(int i)
{
	long double j=2;
	for(int k=i;k>=1;k-=2)
		j=j/2.0;
	if(i%2==1)
		return j;
	else
		return j/two;
}
int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	int n,k;
	cin>>n>>k;
	long double a,b,c;
	a=b=c=0;
	int now=1;
	for(int i=1;i<=k;i++)
	{
		long double shuzhi=cen(i);
		switch(now)
		{
			case 1:a+=shuzhi;break;
			case 2:b+=shuzhi;break;
			case 3:c+=shuzhi;break;
		}
		a+=shuzhi;
		b+=shuzhi;
		c+=shuzhi;
		now++;
		if(now==4)
			now=1;
	}
	cout<<fixed<<setprecision(3)<<a*n<<' ';
	cout<<fixed<<setprecision(3)<<b*n<<' ';
	cout<<fixed<<setprecision(3)<<c*n<<endl;
	return 0;
}
