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
int t[201],u[201],v[201],x[201],y[201],z[201];
int f1[60001],f2[6000001];
int n,m,p,k,ans1=6000001,ans2=60001;
int main(){
	freopen("z.in","r",stdin);
	freopen("z.out","w",stdout);
	for(int i=0;i<=60000;i++){
		f1[i]=6000001;
	}
	for(int j=0;j<=6000000;j++){
		f2[j]=60001;
	}
	cin>>n>>m>>p>>k;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>u[i]>>v[i];
	}
	for(int j=1;j<=m;j++){
		cin>>x[j]>>y[j]>>z[j];
	}
	f1[0]=0;f2[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=p+t[i]*v[i];j>=t[i];j--){
			for(int k=1;k<=min((j/t[i]),v[i]);k++){
				f1[j]=min(f1[j],f1[j-k*t[i]]+u[i]*k);
			}
		}
	}
	for(int j=p;j<=60000;j++){
		ans1=min(ans1,f1[j]);
	}
	cout<<ans1<<endl;
	for(int i=1;i<=m;i++){
		for(int j=ans1+x[i]*z[i];j>=x[i];j--){
			for(int k=1;k<=min((j/x[i]),z[i]);k++){
				f2[j]=min(f2[j],f2[j-k*x[i]]+y[i]*k);
			}
		}
	}
	for(int j=ans1;j<=6000000;j++){
		ans2=min(ans2,f2[j]);
	}
	if(ans2>k)cout<<"FAIL"<<endl;
	else cout<<ans2<<endl;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
