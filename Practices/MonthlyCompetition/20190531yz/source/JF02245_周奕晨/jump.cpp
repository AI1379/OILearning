#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,a[1000],sto=0,step=0;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		for(int j=sto;j<a[i]+sto;j++)
		{
			if(a[j]>a[i])
			{
				step++;
				sto=j;
				break;
			}
		}
	}
	cout<<step;
	return 0;
}
