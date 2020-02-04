#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	long long l,ans=0;
	cin>>s;
	l=s.size()-1;
	for(int i=0;i<=l;++i)if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='i'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')ans++;
	printf("%lld",ans);
	return 0;
}
