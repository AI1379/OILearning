//#include<bits/stdc++.h>
#include<cstdio>
#include<string>
#include<iostream>
//#include<>
using namespace std;
inline int read(){
	register int x;register char c(getchar());register bool k;
	//while((c<'0'||c>'9')&&c^'-')if((c=getchar())==EOF)exit(0);
	if(c^'-')x=c-'0',k=1;else x=0,k=0;
	for(c=getchar();c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+c-'0';
	return k?x:((~x)+1);
}
int main(){
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	string str;
	int ans=0;
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
			ans++;
	}
	printf("%d",ans);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
