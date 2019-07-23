#include <bits/stdc++.h>
using namespace std;
char a[1000010];
int main(){
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	int ans=0;
	scanf("%s",a);
	for(int i=0;i<strlen(a);i++){
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U'){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
