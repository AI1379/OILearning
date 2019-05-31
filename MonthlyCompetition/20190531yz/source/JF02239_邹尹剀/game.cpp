#include<bits/stdc++.h>
using namespace std;
int n,a[5][5],x,y,v;
char f;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>x>>y>>v>>f;
		a[x][y]=v;
		if(f=='L')
		{
			for(int j=1; j<=4; j++)
		    {
			    for(int k=1; k<=3; k++)
			    {
			    	if(a[j][k]==a[j][k+1])
			    	{
			    		a[j][k]*=2;
			    		a[j][k+1]=0;
					}
				}
		    }
		    for(int j=1; j<=4; j++)
		    {
		    	for(int k=4; k>=2; k--)
		    	{
		    		if(a[j][k-1]==0)
					{
						a[j][k-1]=a[j][k];
						a[j][k]=0;
					}
				}
			}
		}
		if(f=='R')
		{
			for(int j=1; j<=4; j++)
			{
				for(int k=4; k>=2; k--)
				{
					if(a[j][k]==a[j][k-1])
			    	{
			    		a[j][k]*=2;
			    		a[j][k-1]=0;
					}
				}
			}
			for(int j=1; j<=4; j++)
		    {
		    	for(int k=1; k<=3; k++)
		    	{
		    		if(a[j][k+1]==0)
					{
						a[j][k+1]=a[j][k];
						a[j][k]=0;
					}
				}
			}
		}
		if(f=='D')
		{
			for(int j=1; j<=4; j++)
			{
				for(int k=4; k>=2; k--)
				{
					if(a[k][j]==a[k-1][j])
			    	{
			    		a[k][j]*=2;
			    		a[k-1][j]=0;
					}
				}
			}
			for(int j=1; j<=4; j++)
		    {
		    	for(int k=1; k<=3; k++)
		    	{
		    		if(a[k+1][j]==0)
					{
						a[k+1][j]=a[k][j];
						a[k][j]=0;
					}
				}
			}
		}
		if(f=='U')
		{
			for(int j=1; j<=4; j++)
			{
				for(int k=1; k<=3; k++)
				{
					if(a[k][j]==a[k+1][j])
			    	{
			    		a[k][j]*=2;
			    		a[k+1][j]=0;
					}
				}
			}
			for(int j=1; j<=4; j++)
		    {
		    	for(int k=4; k>=2; k--)
		    	{
		    		if(a[k-1][j]==0)
					{
						a[k-1][j]=a[k][j];
						a[k][j]=0;
					}
				}
			}
		}
	}
	int sum=0;
	for(int i=1; i<=4; i++)
	{
		for(int j=1; j<=4; j++)
		if(a[i][j]>0) sum++;
	}
	if(sum==16)
	{
		cout<<"Game over!";
		return 0;
	}
	for(int i=1; i<=4; i++)
	{
		for(int j=1; j<=4; j++)
		cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0; 
} 
