#include<bits/stdc++.h>
using namespace std;
int n,t[101];
int a,b,s;
int main()
{
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		s=1;
		cin >> a>>b;
		for(int j=a+1;j>a-b+2;j--)
		{
			s*=j;
		}
		for(int v=b-1;v>=1;v--)
		{
			s/=v;
		}
		   
		t[i]=s/2;
	}
	for(int i=1;i<=n;i++) cout<<t[i];
	return 0;
}
