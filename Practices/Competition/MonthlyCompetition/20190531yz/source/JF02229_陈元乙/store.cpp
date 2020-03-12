#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("store.in","r",stdin);
	freopen("store.out","w",stdout);
	long long T,a,b,c,ans;
	cin>>T;
	while (T--)
	{
		scanf("%d%d%d",&a,&b,&c);
		ans=(a+b+c)/3;
		printf("%d\n",ans);
	}
	return 0;
}
