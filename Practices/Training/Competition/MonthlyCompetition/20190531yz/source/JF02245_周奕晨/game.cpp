#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,x,y,v,a[4][4]={0},game[4],flag=0;
	char f;
	cin>>n;
	for(int hhh=0;hhh<n;hhh++)
	{
		flag=0;
		for(int lll=0;lll<4;lll++)
		{
			for(int rrr;rrr<4;rrr++)
			{
				if(a[lll][rrr]==0)
				{
					flag=1;
				}
			}
		}
		if(flag==0)
		{
			for(int lll=0;lll<4;lll++)
			{
				for(int rrr;rrr<4;rrr++)
				{
					cout<<a[lll][rrr]<<" ";
				}
				cout<<endl; 
			}
			return 0;
		}
		cin>>x>>y>>v>>f;
		a[x-1][y-1]=v;
		
		 
		if(f=='U')
		{
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<4;j++)
				{
					game[j]=a[i][j];
				}
				for(int k=0;k<4;k++)
				{
					if(game[k]==0)
					{
						game[k]=game[k+1];
						game[k+1]=0;	
					}	
				} 
				for(int d=0;d<3;d++)
				{
					if(game[d]==game[d+1])
					{
						game[d]=game[d]*2;	
					}	
					for(int z=d+1;d+1<=2;z++)
					{
						game[z]=game[z+1];
					}
					game[3]=0;
				} 
				for(int byy=0;byy<4;byy++)
				{
					a[i][byy]=game[byy];
				}
			}
		}
		
		
		if(f=='D')
		{
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<4;j++)
				{
					game[j]=a[i][j];
				}
				for(int k=0;k<4;k++)
				{
					if(game[k]==0)
					{
						game[k]=game[k+1];
						game[k+1]=0;	
					}	
				} 
				for(int d=0;d<3;d++)
				{
					if(game[d]==game[d+1])
					{
						game[d]=game[d]*2;	
					}	
					for(int z=d+1;d+1<=2;z++)
					{
						game[z]=game[z+1];
					}
					game[3]=0;
				} 
				for(int byy=0;byy<4;byy++)
				{
					a[i][byy]=game[byy];
				}
			}
		}
		
		
		if(f=='L')
		{
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<4;j++)
				{
					game[j]=a[i][j];
				}
				for(int k=0;k<4;k++)
				{
					if(game[k]==0)
					{
						game[k]=game[k+1];
						game[k+1]=0;	
					}	
				} 
				for(int d=0;d<3;d++)
				{
					if(game[d]==game[d+1])
					{
						game[d]=game[d]*2;	
					}	
					for(int z=d+1;d+1<=2;z++)
					{
						game[z]=game[z+1];
					}
					game[3]=0;
				} 
				for(int byy=0;byy<4;byy++)
				{
					a[i][byy]=game[byy];
				}
			}
		}
		
		
		if(f=='R')
		{
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<4;j++)
				{
					game[j]=a[i][j];
				}
				for(int k=0;k<4;k++)
				{
					if(game[k]==0)
					{
						game[k]=game[k+1];
						game[k+1]=0;	
					}	
				} 
				for(int d=0;d<3;d++)
				{
					if(game[d]==game[d+1])
					{
						game[d]=game[d]*2;	
					}	
					for(int z=d+1;d+1<=2;z++)
					{
						game[z]=game[z+1];
					}
					game[3]=0;
				} 
				for(int byy=0;byy<4;byy++)
				{
					a[i][byy]=game[byy];
				}
			}
		}
	}
	//return 0;
}
