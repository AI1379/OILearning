#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b) {
	return a<b;
}
int main() {
	int fa[160010],fb[160010],f[160010];
	int a,b,c,m,i,x,y,noa=0,nob=0,ans1=0,ans2=0;
	char tmp;
	freopen("T3.in","r",stdin);
	freopen("T3.out","w",stdout);
	memset(fa,0x3f,sizeof(fa));
	memset(fb,0x3f,sizeof(fb));
	cin>>a>>b>>c>>m;
	for(i=0; i<m; i++) {
		cin>>x>>tmp;
		if(tmp=='A')fa[noa++]=x;
		else fb[nob++]=x;
	}
	sort(fa,fa+noa,cmp);
	sort(fb,fb+nob,cmp);
	x=noa;
	y=nob;
	while(x>0&&a>0) {
		ans1++;
		ans2+=fa[noa-x];
		x--;
		a--;
	}
	while(y>0&&b>0) {
		ans1++;
		ans2+=fb[nob-y];
		y--;
		b--;
	}
	int f1,t1,f2,t2,k=0;
	f1=noa-x;
	t1=noa-1;
	f2=nob-y;
	t2=nob-1;
	while(f1<=t1&&f2<=t2) {
		if(fa[f1]>fb[f2]) {
			f[k++]=fa[f1];
			f1++;
		} else {
			f[k++]=fb[f2];
			f2++;
		}
	}
	if(f1<t1) {
		for(i=f1; i<t1; i++)
			f[k++]=fa[i];
	} else {
		for(i=f2; i<t2; i++)
			f[k++]=fb[i];
	}
	if(k>=c) ans1+=c;
	else ans1+=k;
	for(i=0; i<k; i++)
		ans2+=f[i];
	cout<<ans1<<' '<<ans2;
}
