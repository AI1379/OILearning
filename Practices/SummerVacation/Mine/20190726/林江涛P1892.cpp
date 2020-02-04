#include<bits/stdc++.h> 
using namespace std;
long long father[1010];
void init(long long n){
	for(long long i=1;i<=n;i++)
		father[i]=i;
	return ;
}
long long root(long long x){
	if(father[x]!=x)
		father[x]=root(father[x]);
	return father[x];
}
void merge(long long x,long long y){
	long long a=root(x),b=root(y);
	father[b]=a;
	return ;
}
bool judge(long long x,long long y){
	long long a=root(x),b=root(y);
	return a==b;
}
int main(){
	long long n,m,i,enemy[1010],p,q,ans=0;
	char c;
	memset(enemy,0,sizeof(enemy));
	cin>>n>>m;
	init(n);
	for(i=1;i<=m;i++){
		cin>>c>>p>>q;
		if(c=='F')merge(p,q);
		else{
			if(enemy[p]==0)enemy[p]=root(q);
			else merge(enemy[p],q);
			if(enemy[q]==0)enemy[q]=root(p);
			else merge(enemy[q],p);
		}
	}
	for(i=1;i<=n;i++)
		if(father[i]==i)
			ans++;
	cout<<ans;
	return 0;
}
