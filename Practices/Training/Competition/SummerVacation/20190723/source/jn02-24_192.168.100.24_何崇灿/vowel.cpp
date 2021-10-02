#include<bits/stdc++.h>
using namespace std;
char n[1000002];
int ans=0;
int main()
{
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	scanf("%s",n);
	for(int i=0;i<strlen(n);i++)
	{
		if(n[i]=='a'||n[i]=='e'||n[i]=='i'||n[i]=='o'||n[i]=='u')
		    ans++;
		if(n[i]=='A'||n[i]=='E'||n[i]=='I'||n[i]=='O'||n[i]=='U')
		    ans++;
	}
	cout <<ans;
	return 0;
}













