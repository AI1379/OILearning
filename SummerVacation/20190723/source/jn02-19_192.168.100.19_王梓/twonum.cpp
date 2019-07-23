#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxmod=1e6;
const LL maxtime=2e12;
void read(LL &x)
{
	LL s=0,t=1; char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') t=-1; c=getchar(); }
	while(c>='0'&&c<='9') { s=s*10+c-'0'; c=getchar(); }
	x=s*t; return ;
}
LL T,mod,h1,a1,x1,yy,h2,a2,x2,y2,w1,w2,c1,c2,cc1,cc2,wz1,wz2;
LL b1,b2;
bool flag[maxmod+10],flag1;
int main()
{
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	read(T);
	while(T--)
	{
		read(mod);
		read(h1); read(a1);
		read(x1); read(yy);
		read(h2); read(a2);
		read(x2); read(y2);
		//c1表示循环一次需要的时间,cc1表示第一次成功需要的时间
		//cc1+k1*c1=cc2+k2*c2=ans ans_min即为答案 
		//前后比对-start 
		memset(flag,0,sizeof(flag));
		flag1=0; w1=h1; c1=0; cc1=-1; flag[w1]=1;
		while(1)
		{
			w1=(x1*w1%mod+yy)%mod;
			c1++;
			if(flag[w1]) { flag1=1; break; }
			flag[w1]=1;
			if(w1==a1) cc1=c1;
		}
		if(cc1==-1) { printf("-1\n"); continue; }
//		cout<<c1<<" "<<cc1<<endl;
		
		memset(flag,0,sizeof(flag));
		flag1=0; w2=h2; c2=0; cc2=-1; flag[w2]=1;
		while(1)
		{
			w2=(x2*w2%mod+y2)%mod;
			c2++;
			if(flag[w2]) { flag1=1; break; }
			flag[w2]=1;
			if(w2==a2) cc2=c2;
		}
		if(cc2==-1) { printf("-1\n"); continue; }
//		cout<<c2<<" "<<cc2<<endl;
		//前后比对-end
		
		b1=cc1; b2=cc2; wz1=0; wz2=0;
		while(1)
		{
			if(b1==b2) { cout<<b1<<endl; break; }
			if(b1<b2) b1+=c1,wz1++;
			if(b1>b2) b2+=c2,wz2++;
			if(b1>maxtime||b2>maxtime) { printf("-1\n"); break; }
			if(wz1>c2+2||wz2>c1+2) { printf("-1\n"); break; }
		}
	}
	return 0;
}
