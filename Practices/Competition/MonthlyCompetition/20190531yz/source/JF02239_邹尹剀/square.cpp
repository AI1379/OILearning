#include<bits/stdc++.h>
using namespace std;
int n,k;
struct node{
	double z,g;
};
node ay,mi,ge,ls;
double ans1,ans2,ans3;
int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	cin>>n>>k;
	ls.z=1.0*n;
	ay.z+=ls.z;
	for(int i=2; i<=4*k; i++)
	{
		if(i%4==1)
		{
			if(ls.z>0)
			{
				ls.g=ls.z/2;
				ls.z=0;
			}
			else if(ls.g>0) ls.z=ls.g;
		}
		if(i%3==1)
		{
			if(ls.z>0) ay.z+=ls.z;
			else if(ls.g>0) ay.g+=ls.g;
		}
		if(i%3==2)
		{
			if(ls.z>0) mi.z+=ls.z;
			else if(ls.g>0) mi.g+=ls.g;
		}
		if(i%3==0)
		{
			if(ls.z>0) ge.z+=ls.z;
			else if(ls.g>0) ge.g+=ls.g;
		}
	}
	double ss=sqrt(2);
	ans1=ay.z+ay.g*ss;
	ans2=mi.z+mi.g*ss;
	ans3=ge.z+ge.g*ss;
	printf("%.3lf %.3lf %.3lf",ans1,ans2,ans3);
	return 0;
} 
