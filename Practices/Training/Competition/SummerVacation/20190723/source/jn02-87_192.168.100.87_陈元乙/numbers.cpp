#include<bits/stdc++.h>
using namespace std;
const long long M=100000007;
long long f[301][301][301];
long long T,m,n;
long long search(int choice,int res,int big)
{
	if (f[choice][res][big])
		return f[choice][res][big];
	if (choice==1)
	{
		return 1;
	}
	for (int i=big;i<=res/choice;i++)
		if (res-i>=i)
			f[choice][res][big]+=search(choice-1,res-i,i),f[choice][res][big]%=M;
		else
			break;
	return f[choice][res][big]%M;
}
int main()
{
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	scanf("%lld",&T);
	for (int i=1;i<=T;i++)
	{
		scanf("%lld%lld",&m,&n);
		printf("%lld\n",search(n,m,0));
	}
	return 0;
}
