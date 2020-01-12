//Coded by dst
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,m,p,k,ans1,ans2,f[20005],t[205],u[205],v[205],x[205],y[205],z[205];
void upd(int wi,int vi){
	for(int i=20000;i>=wi;i--)
		f[i]=max(f[i],f[i-wi]+vi);
}
int backpack(int n,int p,int w[],int v[],int num[]){
//n物品种类 p要求价值 w代价 v价值 num数量 
	memset(f,0,sizeof(f));
	int i,j,res;
	for(i=1;i<=n;i++){
	 	for(j=1;(j<<1)-1<=num[i];j<<=1)//(j<<1)-1=1+2+4+8+..+j
	 		upd(w[i]*j,v[i]*j);
	 	res=num[i]-j+1;
		upd(w[i]*res,v[i]*res);
	}
	for(i=0;i<=20000;i++)
		if(f[i]>=p)
	 		return i;
	return -1;
} 
inline void print(int x){
	if(x==-1)
		printf("FAIL\n");
	else
		printf("%d\n",x);
}
int main(){
	freopen("z.in","r",stdin);
	freopen("z.out","w",stdout);
	int i;
	scanf("%d%d%d%d",&n,&m,&p,&k);
	for(i=1;i<=n;i++)
		scanf("%d%d%d",&t[i],&u[i],&v[i]);
	for(i=1;i<=m;i++)
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
	ans1=backpack(n,p,u,t,v);
	ans2=backpack(m,ans1,y,x,z);
	if(ans2>k)
		ans2=-1;
	print(ans1);print(ans2);
	return 0;
} 
