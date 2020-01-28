#include<iostream>
#include<cmath> 
#include<cstdio>
#include<cstring>
using namespace std;
int a,b,c,t,ans;
int main()
{
	freopen("store.in","r",stdin);
	freopen("store.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		int t1,t2,t3;
		scanf("%d%d%d",&a,&b,&c);
		t1=min(min(a/4,b/4),c);
		a-=t1*4,b-=t1*4,c-=t1;
		ans+=t1*3;
//		cout<<t1<<endl;
		t2=min(a,b)/3;
		a-=t2*3,b-=t2*3;
//		cout<<t2*2;
		ans+=t2*2;
//		cout<<a<<b<<c; 
		if(a>1&&b>0) ans+=min(t1+1,a/2),a-=2*min(t1+1,a/2),b-=1*min(t1+1,a/2);
		else if(b>1&&a>0) ans+=min(t1+1,b/2),a-=min(t1+1,a/2),b-=2*min(t1+1,a/2);
		if(c&&a&&b) ans+=min(t1+t2+1,c);
		printf("%d\n",ans);
	}
}












//1 999 921 3
