//#include<bits/stdc++.h>
#include<cstdio>
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
long long L,R;
int T,ans=0;
void ch(long long i){
	int count=0;
	while(i){
		if(i%2==0)count++;
		i=i/2;
	}
	if(count==1)ans++;
}
int main(){
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>L>>R;
		ans=0;
		for(long long i=L;i<=R;i++){
			ch(i);
		}
		cout<<ans<<endl;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
