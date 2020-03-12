#include<bits/stdc++.h>
using namespace std;
int a,x,y,f[5][5],op,k1[5];
string b;
bool find(int a)
{
	for(int i=1;i<=4;i++)
	{
		if(k1[i]==a) return false;
	}
	return true;
}
void up()
{
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
			if(f[j][i]!=0)
			{
				for(int k=1;k<=4;k++)
				{
					if(f[k][i]==0)
					{
						f[k][i]=f[j][i];
						f[j][i]=0;
						break;
					}
				}
			}
		}
	}
}
void down()
{
	for(int i=1;i<=4;i++)
	{
		memset(k1,0,sizeof(k1));
		op=1;
		for(int j=1;j<=4;j++)
		{
			if(f[j][i]!=0&&find(j))
			{
				for(int k=4;k>=1;k--)
				{
					if(f[k][i]==0)
					{
						k1[op]=k;op++;
						f[k][i]=f[j][i];
						f[j][i]=0;
						break;
					}
				}
			}
		}
	}
}
void left()
{
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
			if(f[i][j]!=0)
			{
				for(int k=1;k<=4;k++)
				{
					if(f[i][k]==0)
					{
						f[i][k]=f[i][j];
						f[i][j]=0;
						break;
					}
				}
			}
		}
	}
}
void right()
{
	for(int i=1;i<=4;i++)
	{
		memset(k1,0,sizeof(k1));
		op=1;
		for(int j=1;j<=4;j++)
		{
			if(f[i][j]!=0&&find(j))
			{
				for(int k=4;k>=1;k--)
				{
					if(f[i][k]==0)
					{
						k1[op]=k;op++;
						f[i][k]=f[i][j];
						f[i][j]=0;
						break;
					}
				}
			}
		}
	}
}
int main()
{
	//freopen("game.in","r",stdin);
	//freopen("game.out","w",stdout);
	scanf("%d",&a);
	for(int i=1;i<=a;i++) 
	{
		scanf("%d%d",&x,&y);
		scanf("%d",&f[x][y]);
		cin>>b;
		if(b[0]=='U') up();
		else if(b[0]=='D') down();
		else if(b[0]=='L') left();
		else if(b[0]=='R') right();
	}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++) printf("%d ",f[i][j]);
		printf("\n");
	}
		
}
