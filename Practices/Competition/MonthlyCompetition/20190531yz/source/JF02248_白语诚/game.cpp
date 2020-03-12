#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m[5][5],n,x,y,num,sum;
char f;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	while(n--)//前行后列 
	{
		cin>>x>>y>>num>>f;
		m[x][y]=num;
		sum++;
		if(f=='U')
		{
			for(ll i=1;i<=4;i++)//列 y
			{
				for(ll j=2;j<=4;j++)//行 x
				{
					if(m[j][i]==0)continue;
					for(ll k=j-1;k>=1;k--)
					{
					if(m[j][i]==m[k][i]&&m[j][i]!=0)
					{
					m[k][i]+=m[j][i],m[j][i]=0,sum--;
					break;
					}
					else if(m[k][i]!=m[j][i]&&m[k][i]!=0)
					{
						m[k+1][i]=m[j][i];
						if(k+1!=j)
						m[j][i]=0;
						break;
					}
					else if(k==1)m[k][i]=m[j][i],m[j][i]=0;
				}
				}
			}
		}
		if(f=='D')
		{
			for(ll i=1;i<=4;i++)//列 y
			{
				for(ll j=3;j>=1;j--)//行 x
				{
					if(m[j][i]==0)continue;
				for(ll k=j+1;k<=4;k++)
					{
					if(m[j][i]==m[k][i]&&m[j][i]!=0)
					{
					m[k][i]+=m[j][i],m[j][i]=0,sum--;
					break;
					}
					else if(m[k][i]!=m[j][i]&&m[k][i]!=0)
					{
						m[k-1][i]=m[j][i];
						if(k-1!=j)
						m[j][i]=0;
						break;
					}
						else if(k==4)m[k][i]=m[j][i],m[j][i]=0;
				}
			}
		}
	}
		if(f=='L')
		{
			for(ll i=1;i<=4;i++)// 行x
			{
				for(ll j=2;j<=4;j++)//列 y
				{
					if(m[i][j]==0)continue;
					for(ll k=j-1;k>=1;k--)
					{
					if(m[i][j]==m[i][k]&&m[i][j]!=0)
					{
					m[i][k]+=m[i][k],m[i][j]=0,sum--;
					break;
					}
					else if(m[i][k]!=m[i][j]&&m[i][k]!=0)
					{
						m[i][k+1]=m[i][j];
						if(k+1!=j)
						m[i][j]=0;
						break;
					}
					else if(k==1)m[i][k]=m[i][j],m[i][j]=0;
				}
				}
			}
		}
		if(f=='R')
		{
			for(ll i=1;i<=4;i++)// 行x
			{
				for(ll j=3;j>=1;j--)//列 y
				{
					if(m[i][j]==0)continue;
					for(ll k=j+1;k<=4;k++)
					{
					if(m[i][j]==m[i][k]&&m[i][j]!=0)
					{
					m[i][k]+=m[i][k],m[i][j]=0,sum--;
					break;
					}
					else if(m[i][k]!=m[i][j]&&m[i][k]!=0)
					{
						m[i][k-1]=m[i][j];
						if(k-1!=j)
						m[i][j]=0;
						break;
					}
						else if(k==4)m[i][k]=m[i][j],m[i][j]=0;
				}
				}
			}
		}
	/*	for(int i=1;i<=4;i++)
     {
       for(int j=1;j<=4;j++)
      cout<<m[i][j]<<' ';
      cout<<endl;
      }*/
		if(sum==16)
		{
		cout<<"Game over!";
		return 0;
	   }
}
for(ll i=1;i<=4;i++)
{
for(ll j=1;j<=4;j++)
cout<<m[i][j]<<' ';
cout<<endl;
}
return 0;
}
