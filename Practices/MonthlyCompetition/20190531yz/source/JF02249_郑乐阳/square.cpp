#include<bits/stdc++.h>
using namespace std;

double a,m,g,p1,x2;
int n,k;

int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	cin>>n>>k;
	p1=n;
	x2=sqrt(0.5)*n;
	for(int i=1;i<=k*4;i++)
	{
		if(i%3==1)
		{
			if((i-1)%8<=3)
			{
				a+=p1;
				if(i%8==4)
					p1/=2;
			}
			else
			{
				a+=x2;
				if(i%8==0)
					x2/=2;
			}
		}
		else if(i%3==2)
		{
			if((i-1)%8<=3)
			{
				m+=p1;
				if(i%8==4)
					p1/=2;
			}
			else
			{
				m+=x2;
				if(i%8==0)
					x2/=2;
			}
		}
		else
		{
			if((i-1)%8<=3)
			{
				g+=p1;
				if(i%8==4)
					p1/=2;
			}
			else
			{
				g+=x2;
				if(i%8==0)
					x2/=2;
			}
		}
	}
	printf("%.3f %.3f %.3f",a,m,g);
	return 0;
}
