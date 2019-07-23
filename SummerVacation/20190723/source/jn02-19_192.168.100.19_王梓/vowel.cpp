#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
char s[maxn+10];
int len,ans;
int main()
{
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	cin>>(s+1); len=strlen(s+1);
	for(int i=1;i<=len;i++)
		if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'
		 ||s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
			ans++;
	cout<<ans<<endl;
	return 0;
}
