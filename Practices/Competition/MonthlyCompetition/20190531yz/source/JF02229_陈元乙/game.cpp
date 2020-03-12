#include<bits/stdc++.h>
using namespace std;
long long  n,X,Y,v,mapp[5][5];
long long  st[5],sttop=-1;
long long  sizest()
{
	return sttop+1;
}
void pushst(long long  x)
{
	sttop++;
	st[sttop]=x;
	return;
}
long long  top1st()
{
	return st[sttop];
}
long long  top2st()
{
	return st[sttop-1];
}
void popst()
{
	sttop--;
	return;
}
void clearst()
{
	memset(st,0,sizeof(st));
	sttop=-1;
	return;
}
char f;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	memset(mapp,0,sizeof(mapp));
	for (long long  i=1;i<=n;i++)
	{
		cin>>X>>Y>>v>>f;
		if (mapp[X][Y]!=0)
		{
			printf("Game over!");
			return 0;
		}
		mapp[X][Y]=v;
		//
		if (f=='L')
		{
			for (long long  j=1;j<=4;j++)
			{
				clearst();
				for (long long  k=4;k>=1;k--)
					if (mapp[j][k]!=0)
						pushst(mapp[j][k]);
				long long  l=0;
				while (l<=4)
				{
					l++;
					if (sizest()<=0)
						break;
					if (sizest()==1)
					{
						mapp[j][l]=top1st();
						l++;
						break;
					}
					long long  left=top1st();
					long long  right=top2st();
					if (left==right)
					{
						mapp[j][l]=left+right;
						popst();
						popst();
					}
					else
					{
						mapp[j][l]=left;
						popst();
					}
				}
				for (long long  k=l;k<=4;k++)
				{
					mapp[j][k]=0;
				}				
			}
		}
		//
		if (f=='R')
		{
			for (long long  j=1;j<=4;j++)
			{
				clearst();
				for (long long  k=1;k<=4;k++)
					if (mapp[j][k]!=0)
						pushst(mapp[j][k]);
				long long  l=5;
				while (l>=1)
				{
					l--;
					if (sizest()<=0)
						break;
					if (sizest()==1)
					{
						mapp[j][l]=top1st();
						l--;
						break;
					}
					long long  left=top1st();
					long long  right=top2st();
					if (left==right)
					{
						mapp[j][l]=left+right;
						popst();
						popst();
					}
					else
					{
						mapp[j][l]=left;
						popst();
					}
				}
				for (long long  k=l;k>=1;k--)
				{
					mapp[j][k]=0;
				}				
			}
		}
		//
		if (f=='D')
		{
			for (long long  j=1;j<=4;j++)
			{
				clearst();
				for (long long  k=1;k<=4;k++)
					if (mapp[k][j]!=0)
						pushst(mapp[k][j]);
				long long  l=5;
				while (l>=1)
				{
					l--;
					if (sizest()<=0)
						break;
					if (sizest()==1)
					{
						mapp[l][j]=top1st();
						l--;
						break;
					}
					long long  left=top1st();
					long long  right=top2st();
					if (left==right)
					{
						mapp[l][j]=left+right;
						popst();
						popst();
					}
					else
					{
						mapp[l][j]=left;
						popst();
					}
				}
				for (long long  k=l;k>=1;k--)
				{
					mapp[k][j]=0;
				}				
			}
		}
		//
		if (f=='U')
		{
			for (long long  j=1;j<=4;j++)
			{
				clearst();
				for (long long  k=4;k>=1;k--)
					if (mapp[k][j]!=0)
						pushst(mapp[k][j]);
				long long  l=0;
				while (l<=4)
				{
					l++;
					if (sizest()<=0)
						break;
					if (sizest()==1)
					{
						mapp[l][j]=top1st();
						l++;
						break;
					}
					long long  left=top1st();
					long long  right=top2st();
					if (left==right)
					{
						mapp[l][j]=left+right;
						popst();
						popst();
					}
					else
					{
						mapp[l][j]=left;
						popst();
					}
				}
				for (long long  k=l;k<=4;k++)
				{
					mapp[k][j]=0;
				}				
			}
		}
	}
	for (long long  i=1;i<=4;i++)
	{
		for (long long  j=1;j<=4;j++)
			printf("%d",mapp[i][j]);
		printf("\n");
	}
	return 0;
}
