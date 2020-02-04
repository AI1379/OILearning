#include<bits/stdc++.h>
using namespace std;
int father[30010];
int num[30010];
int front[30010];
void init(int n){
	for(int i=1;i<=n;i++){
		father[i]=i;
		num[i]=1;
		front[i]=0;
	}
	return ;
}
int root(int x){
	int fn;
	if(father[x]==x)
		return father[x];
	fn=root(father[x]);
	front[x]+=front[father[x]];
	father[x]=fn;
	return father[x];
}
void merge(int x,int y){
	int a=root(x),b=root(y);
	front[b]+=num[a];
	father[b]=a; 
	num[a]+=num[b];
	num[b]=0;
	return ;
}
bool judge(int x,int y){
	int a=root(x),b=root(y);
	return a==b;
}
int main(){
	int t,m,n;
	char opt;
	init(30000);
	cin>>t;
	while(t--){
		cin>>opt>>m>>n;
		if(opt=='M'){
			merge(n,m);
		}
		else if(opt=='C'){
			if(judge(m,n)){
				cout<<abs(front[m]-front[n])-1<<endl;
			}
			else{
				cout<<"-1"<<endl;
			}
		}
	}
	system("pause");
	return 0;
}
