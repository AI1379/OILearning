#include<bits/stdc++.h>
using namespace std;
long long n,a,b,xax,yax,xin,yin;
int A[1000][1000];
int main()
{
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a>>b;
		A[a+100][b+100]=i;
	//	cout<<A[a+100][b+100]<<endl;
		xax=max(xax,a);
		xin=min(xin,a);
		yax=max(yax,b);
		yin=min(yin,b);
	}
	for(int i=yax;i>=yin;--i)
	{
		for(int j=xin;j<=xax;++j)
		{
			if(A[j+100][i+100]!=0)
			{
				cout<<"*";
			}
			else if(i==0&&j==0)
			{
				cout<<"+";
			}
			else if(i==0&&j!=0)
			{
				cout<<"-";
			}
			else if(i!=0&&j==0)
			{
				cout<<"|";
			}
			else
			{
				cout<<".";
			}
		}
		cout<<endl;
	}
	return 0;
}
