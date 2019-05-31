#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("store.in","r",stdin);
	freopen("store.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		cout<<(a+b+c)/3<<endl;
	}
	return 0;
}
