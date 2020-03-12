#include<bits/stdc++.h>
using namespace std;
struct node{
	int parent,firstchild,rightsibling;
};
node tree[10000];
int b(int x){
	int a=0;
	if(tree[x].rightsibling==-1)
		return 0;
	else if(tree[x].firstchild==-1)
		return 1;
	int y=tree[x].firstchild;
	while(y!=-1){
		a=a+b(y);
		y=tree[y].rightsibling;
	}
	return a;
}
int main(){
	int n,i,x,y,m,c,e,a,j;
	cin>>n;
	memset(tree,-1,sizeof(tree));
	for(i=0;i<n;i++){
		cin>>x>>y;
		tree[y].parent=x;
		if(tree[x].firstchild==-1)
			tree[x].firstchild=y;
		else
			tree[x].rightsibling=y;
	}
	cin>>m;
	for(j=0;j<m;j++){
		cin>>a;
		i=a;
		e=0;c=0;
		while(tree[i].rightsibling!=-1){
			e++;
			i++;
		}
		c=b(m);
		cout<<e<<c<<endl;
	}
	return 0;
}
