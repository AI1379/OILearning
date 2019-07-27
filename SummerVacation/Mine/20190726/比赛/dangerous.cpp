#include<bits/stdc++.h>
using namespace std;
int read()
{
	char ch=getchar(); int x=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-48; ch=getchar();}
	return x;
}
int main(){
	int minn=0x7fffff,x,n,i,ans=0;
	freopen("dangerous.in","r",stdin);
	freopen("dangerous.out","w",stdout);
	n=read();
	for(i=0;i<n;i++){
		x=read();
		if(x<minn)
			minn=x;
		ans+=x;
	}
	ans-=minn;
	printf("%d",ans);
	return 0;
}
