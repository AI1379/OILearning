#include<bits/stdc++.h>
using namespace std;
int f[5][5];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,x,y,w;
	char a;
	cin>>n;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>w>>a;
		f[x][y]=w;
		if(a=='U')
		{
			for(int i=4;i>1;i--)
			{
				for(int j=4;j>=1;j--)
				{
					 if(f[i-1][j]!=0&&i-1>0)
					{
						f[i-1][j]+=f[i][j];
						f[i][j]=0;
						i--;
					}
				}
				
			}
			for(int i=4;i>1;i--)
			for(int j=1;j<=4;j++)
				{
					if(f[i-1][j]==0&&i-1>0)
					{
						f[i-1][j]+=f[i][j];
						f[i][j]=0;
					}
				}
		}
		if(a=='D')
		{
			for(int i=1;i<4;i++)
			{
				for(int j=1;j<=4;j++)
				{
					if(f[i+1][j]!=0&&i+1<=4)
					{
						f[i+1][j]+=f[i][j];
						f[i][j]=0;
						i++;
					}
				}
			}
			for(int i=1;i<4;i++)
				for(int j=1;j<=4;j++)
				{
					if(f[i+1][j]==0&&i+1<=4)
					{
						f[i+1][j]+=f[i][j];
						f[i][j]=0;
					}
				}
		}
		if(a=='R')
		{
			for(int i=1;i<=4;i++)
			{
				for(int j=1;j<4;j++)
				{
					if(f[i][j+1]!=0&&j+1<=4)
					{
						f[i][j+1]+=f[i][j];
						f[i][j]=0;
						j++;
					}
					
				}
			}
			for(int i=1;i<=4;i++)
			{
				for(int j=1;j<4;j++)
				{
					if(f[i][j+1]==0&&j+1<=4)
					{
						f[i][j+1]+=f[i][j];
						f[i][j]=0;
					}
					
				}
			}
		}
		if(a=='L')
		{
			for(int i=4;i>=1;i--)
			{
				for(int j=4;j>1;j--)
				{
					if(f[i][j-1]!=0&&j-1>0)
					{
						f[i][j-1]+=f[i][j];
						f[i][j]=0;
						j--;
					}
					
				}
			}
			for(int i=4;i>=1;i--)
			{
				for(int j=4;j>1;j--)
				{
					if(f[i][j-1]==0&&j-1>0)
					{
						f[i][j-1]+=f[i][j];
						f[i][j]=0;
					}
					
				}
			}
		}
			for(int i=1;i<=4;i++)
		{
			for(int j=1;j<=4;j++)
			{
			 cout<<f[i][j]<<" ";
			}
			cout<<endl;
		}	
		cout<<endl;
		}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
		 cout<<f[i][j]<<" ";
		}
		cout<<endl;
	}	
	return 0;
}
