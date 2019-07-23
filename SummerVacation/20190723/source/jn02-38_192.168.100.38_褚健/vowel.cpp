#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

char s[1000010];
int ans;

int main()
{
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	gets(s);
	int k=strlen(s);
	for(int i=0;i<k;i++) if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U') ans++;
	printf("%d",ans);
}
