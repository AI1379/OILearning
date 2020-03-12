#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
char S[MAXN];
int len,ans;
int main(){
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	scanf("%s",S),len=strlen(S);
	for (int i=0;i<len;i++){
		if (S[i]=='a'||S[i]=='e'||S[i]=='i'||S[i]=='o'||S[i]=='u') ans++;
		if (S[i]=='A'||S[i]=='E'||S[i]=='I'||S[i]=='O'||S[i]=='U') ans++;
	}
	printf("%d",ans);
	return 0;
}
