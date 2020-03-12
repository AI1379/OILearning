#include<bits/stdc++.h>
using namespace std;
#define l 1.414214
int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	double n,k,x[4];
	int num=1;
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=4;j++)
		{
			x[num]+=n;
			num++;
			if(num==4)num=1;
		}
		n/=l;
	}
	printf("%.3f %.3f %.3f",x[1],x[2],x[3]);
	return 0;
}
