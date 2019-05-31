#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	int n,k,max;
	double ans[3],kk[3];
	cin>>n>>k;
	for(int i=0;i<4;i++) kk[i]=99999;
	for(int i=0;i<4;i++)
	{
		ans[i]=(n/2)*(n/2)*2;
		for(double j=0;j<=ans[i];j+=0.001)
		{
			max=ans[i]-j*j;
			if(max<0) max*=-1;
			if(max<kk[i]) kk[i]=max;
			if(kk[i]==0) 
			{
				ans[i]=j;
				n=ans[i];	
				break;
			}
		}
	}
	for(int i=0;i<4;i++) cout<<4*ans[i]<<" ";
	return 0;
} 
