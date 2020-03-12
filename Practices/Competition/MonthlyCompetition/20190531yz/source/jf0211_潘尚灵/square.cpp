#include<bits/stdc++.h>
using namespace std;
int n,k,f=0;
double ayu=0,mit=0,gen=0,a,l;
int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	cin>>n>>k;
	int i,j;
	a=n;
	for(i=1;i<=k;i++)
	{
		for(j=1;j<=4;j++)
		{
			if(f==0)
				ayu+=a;
			else if(f==1)
				mit+=a;
			else if(f==2)
				gen+=a;
			f=(f+1)%3;
		}
		l=a/2;
		a=sqrt(l*l+l*l);
	}
	printf("%.3lf %.3lf %.3lf\n",ayu,mit,gen);
	return 0;
 } 
