#include<bits/stdc++.h>
using namespace  std;
char A[10000000];
long long ans;
int main()
{
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	cin>>A;
	for(int i=0;i<strlen(A);++i)
	{
		if(A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u'||A[i]=='A'||A[i]=='E'||A[i]=='I'||A[i]=='O'||A[i]=='U')
		ans++;
	 } 
	 cout<<ans;
	 return 0;
} 
