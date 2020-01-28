#include<bits/stdc++.h>
using namespace std;
const int mod1=10000007;
const int mod2=9999997;
const int maxn=1500;
char s1[maxn+10];
char s2[maxn+10];
bool flag1[mod1+10];
bool flag2[mod2+10];
int l1,l2,k,ans;
int main()
{
	cin>>(s1+1); l1=strlen(s1+1);
	cin>>(s2+1); l2=strlen(s2+1);
	for(int i=1;i<=l1;i++)
		for(int j=i;j<=l1;j++)
		{
			int sum1=0,sum2=0;
			for(int k=i;k<=j;k++)
				sum1=(sum1*37%mod1+s1[k])%mod1;
			for(int k=i;k<=j;k++)
				sum2=(sum2*41%mod2+s1[k])%mod2;
			flag1[sum1]=1; flag2[sum2]=1;
		}
	for(int i=1;i<=l2;i++)
		for(int j=i;j<=l2;j++)
		{
			int sum1=0,sum2=0;
			for(int k=i;k<=j;k++)
				sum1=(sum1*37%mod1+s2[k])%mod1;
			for(int k=i;k<=j;k++)
				sum2=(sum2*41%mod2+s2[k])%mod2;
			if(flag1[sum1]&&flag2[sum2])
				ans++,flag1[sum1]=0,flag2[sum2]=0;
		}
	cout<<ans<<endl;
	return 0;
}
