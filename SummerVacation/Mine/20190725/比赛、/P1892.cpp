#include<bits/stdc++.h> 
using namespace std;
int father[1010];
int init(int n){
	for(int i=1;i<=n;i++)
		father[i]=i;
	return 0;
}
int root(int x){
	if(father[x]!=x)
		father[x]=root(x);
	return father[x];
}
void merge(int x,int y){
	int a=root(x),b=root(y);
	father[b]=a;
	return ;
}
bool judge(int x,int y){
	int a=root(x),b=root(y);
	return x==y;
}
int main(){
	int n,m,i,enemy[1010],p,q,cnt[1010],ans=0;
	char c;
	memset(cnt,0,sizeof(cnt));
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>c>>p>>q;
		if(x=='F')merge(p,q);
		else{
			if(enemy[p]==0)enemy[p]=root(q);
			else merge(enemy[p],q);
			if(enemy[q]==0)enemy[q]=root(p);
			else merge(enemy[q],p);
		}
	}
	for(i=1;i<=n;i++)
		cnt[find(i)]++;
	for(i=1;i<=n;i++)
		if(cnt[i])
			ans++;
	cout<<ans;
	return 0;
}
