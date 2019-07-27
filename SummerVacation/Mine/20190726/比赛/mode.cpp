#include<bits/stdc++.h>
using namespace std;
int read()
{
	char ch=getchar(); int x=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-48; ch=getchar();}
	return x;
}
map<int,int>a;
vector<int>anslist;
int main(){
	int x,n,i,maxn=0,ans=0;
	freopen("mode.in","r",stdin);
	freopen("mode.out","w",stdout);
	n=read();
	for(i=0;i<n;i++)
		a[i]=0;
	for(i=0;i<n;i++){
		x=read();
		a[x]++;
	}
	for(i=0;i<n;i++){
		maxn=max(a[i],maxn);
	}
	for(i=0;i<n;i++){
		if(a[i]==maxn){
			ans++;
			anslist.push_back(i);
		}
	}
	cout<<ans<<endl;
	for(vector<int>::iterator it=anslist.begin();it!=anslist.end();it++)
		cout<<(*it)<<' ';
	return 0;
}
