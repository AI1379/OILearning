#include<bits/stdc++.h>
//#include<cstdio>
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
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int m,a1,h1,x1,y1,a2,h2,x2,y2;
		bool f=true;
		cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
		int i=0;
		while(i<m*m){
			h1=(h1*x1+y1)%m;
			h2=(h2*x2+y2)%m;
			i++;
			if(h1==a1&&h2==a2){
				f=false;
				cout<<i<<endl;
				break;
			}
		}
		if(f)cout<<-1<<endl;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
