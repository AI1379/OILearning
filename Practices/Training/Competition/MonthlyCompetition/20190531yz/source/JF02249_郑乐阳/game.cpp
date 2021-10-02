#include<bits/stdc++.h>
using namespace std;

int m[10][10],n,x,y,v;
char f;

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int ii=1;ii<=n;ii++)
	{
		scanf("%d%d%d %c",&x,&y,&v,&f);
		m[x][y]=v;
		if(f=='L')
		{
			for(int i=1;i<=4;i++)
			{
				for(int j=1;j<=3;j++)
				{
					if(m[i][j]!=0)
					{
						for(int k=j+1;k<=4;k++)
						{
							if(m[i][j]==m[i][k])
							{
								m[i][j]=2*m[i][j];
								m[i][k]=0;
							}
							else if(m[i][k]!=0)
								break;
						}
					}
				}
			}
			for(int i=1;i<=4;i++)
			{
				for(int j=2;j<=4;j++)
				{
					if(m[i][j]!=0)
					{
						for(int k=j-1;k>=1;k--)
						{
							if(m[i][k]==0)
							{
								if(m[i][k-1]!=0||k==1)
								{
									m[i][k]=m[i][j];
									m[i][j]=0;
								}
							}
							else 
								break;
						}
					}
					
				}
			}
		}
		
		else if(f=='R')
		{
			for(int i=1;i<=4;i++)
			{
				for(int j=4;j>=2;j--)
				{
					if(m[i][j]!=0)
					{
						for(int k=j-1;k>=1;k--)
						{
							if(m[i][j]==m[i][k])
							{
								m[i][j]=2*m[i][j];
								m[i][k]=0;
							}
							else if(m[i][k]!=0)
								break;
						}
					}
				}
			}
			for(int i=1;i<=4;i++)
			{
				for(int j=3;j>=1;j--)
				{
					if(m[i][j]!=0)
					{
						for(int k=j+1;k<=4;k++)
						{
							if(m[i][k]==0)
							{
								if(m[i][k+1]!=0||k==4)
								{
									m[i][k]=m[i][j];
								m[i][j]=0;
								}
							}
							else
								break;
						}
					}
				}
			}
		}
		
		else if(f=='U')
		{
			for(int j=1;j<=4;j++)
			{
				for(int i=1;i<=3;i++)
				{
					if(m[i][j]!=0)
					{
						for(int k=i+1;k<=4;k++)
						{
							if(m[i][j]==m[k][j])
							{
								m[i][j]=2*m[i][j];
								m[k][j]=0;
							}
							else if(m[k][j]!=0)
								break;
						}
					}
				}
			}
			for(int j=1;j<=4;j++)
			{
				for(int i=2;i<=4;i++)
				{
					if(m[i][j]!=0)
					{
						for(int k=i-1;k>=1;k--)
						{
							if(m[k][j]==0)
							{
								if(m[k-1][j]!=0||k==1)
								{
									m[k][j]=m[i][j];
									m[i][j]=0;
								}
								
							}
							else
								break;
						}
					}
					
				}
			}
		}
		
		else if(f=='D')
		{
			for(int j=1;j<=4;j++)
			{
				for(int i=4;i>=2;i--)
				{
					if(m[i][j]!=0)
					{
						for(int k=i-1;k>=1;k--)
						{
							if(m[i][j]==m[k][j])
							{
								m[i][j]=2*m[i][j];
								m[k][j]=0;
							}
							else if(m[k][j]!=0)
								break;
						}
					}
				}
			}
			for(int j=1;j<=4;j++)
			{
				for(int i=3;i>=1;i--)
				{
					if(m[i][j]!=0)
					{
						for(int k=i+1;k<=4;k++)
						{
							if(m[k][j]==0)
							{
								if(m[k+1][j]!=0||k==4)
								{
									m[k][j]=m[i][j];
									m[i][j]=0;
								}
									
							}
							else
								break;
						}
					}
				}
			}
		}
	}
	bool flag=0;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
			if(m[i][j]!=0)
				flag=1;
		}
	}
	if(!flag)
		cout<<"Game over!";
	else
	{
		for(int i=1;i<=4;i++)
		{
			for(int j=1;j<=3;j++)
			{
				printf("%d ",m[i][j]);
			}
			printf("%d\n",m[i][4]);
		}
	}
	return 0;
}
/*
5
1 4 2 L
1 2 2 L 
4 2 4 U
2 3 2 L
2 2 4 R

6
1 3 4 L
2 3 2 U
2 4 2 R
4 1 2 L
3 4 2 L
3 2 2 D
1 3 4 R
1 3 2 U

4
1 1 2 U
1 2 2 U
1 3 2 U
4 4 2 L

4
1 1 2 U
1 2 2 U
1 3 2 U
1 4 2 L

6
1 4 2 D
2 3 4 L
3 4 2 U
4 2 2 R
2 3 4 U
1 1 2 L
*/
