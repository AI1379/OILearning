#include<iostream>
#include<cstdio>
using namespace std;
int a[5][5],c[5];
bool d[5];
int hebing()
{
	for(int i=1;i<=4;i++)
		d[i]=false;
	int all=0;
	for(int i=1;i<=4;i++)
		if(c[i])
		{
			all++;
			d[i]=true;
		}
	for(int i=1;i<=3;i++)
		for(int j=3;j>=i;j--)
			if(d[j]==false)
			{
				swap(d[j],d[j+1]);
				swap(c[j],c[j+1]);
			}
	for(int i=1;i<=all-1;i++)
		if(c[i]==c[i+1])
		{
			c[i]*=2;
			for(int j=i+1;j<=all-1;j++)
				c[j]=c[j+1];
			c[all]=0;
			all--;
		}
/*	cout<<"all=";
	for(int i=1;i<=4;i++)
		cout<<c[i]<<' ';
	cout<<endl;
	cout<<"wei="<<all<<endl;*/
	return all;
}
void print()
{
	int all=16;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			if(a[i][j])
				all--;
	if(all)
		for(int i=1;i<=4;i++)
		{
			for(int j=1;j<=4;j++)
				cout<<a[i][j]<<' ';
			cout<<endl;
		}
	else
		cout<<"Game over!"<<endl;
	cout<<endl;
}
void yi(char fangxiang)
{
	switch(fangxiang)
	{
		case 'U':
		for(int j=1;j<=4;j++)
		{
			for(int k=1;k<=4;k++)
				c[k]=a[k][j];
			int wei=hebing();
			for(int k=1;k<=4;k++)
				a[k][j]=c[k];
		}break;
		
		case 'D':
		for(int j=1;j<=4;j++)
		{
			for(int k=4;k>=1;k--)
				c[5-k]=a[k][j];
			int wei=hebing();
			for(int k=1;k<=4;k++)
				a[k][j]=0;
			for(int k=1;k<=wei;k++)
				a[4-wei+k][j]=c[k];
		}break;
		
		case 'L':
		for(int i=1;i<=4;i++)
		{
			for(int k=1;k<=4;k++)
				c[k]=a[i][k];
			int wei=hebing();
			for(int k=1;k<=4;k++)
				a[i][k]=c[k];
		}break;
		
		case 'R':
		for(int i=1;i<=4;i++)
		{
			for(int k=4;k>=1;k--)
				c[k]=a[i][k];
			int wei=hebing();
			for(int k=1;k<=4;k++)
				a[i][k]=0;
			for(int k=1;k<=wei;k++)
				a[i][4-wei+k]=c[k];
		}break;
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y,num;
		char f;
		cin>>x>>y>>num>>f;
		a[x][y]=num;
		yi(f);
	}
	print();
	return 0;
}
