#include<bits/stdc++.h>
#define int long long
const int inf=1e8;
using namespace std;
void read(int &x)
{
	int s=0,t=1; char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') t=-1; c=getchar(); }
	while(c>='0'&&c<='9') { s=s*10+c-'0'; c=getchar(); }
	x=s*t; return ;
}
int n;
double x1,yy,x2,y2,k,b,a1,a2,a3;
double maxx=-inf,minn=inf;
int maxxx=-inf,minnn=inf,ans,num,ax=-inf;
map < int , int > mp;
signed main()
{
	freopen("intersect.in","r",stdin);
	freopen("intersect.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
	{
		cin>>x1>>yy>>x2>>y2;
		if(x1==x2&&yy==y2)
		{
			double ccc=x1*yy;
			mp[(int)(ccc*100)]++;
			mp[(int)(ccc*100+1)]--;
			maxxx=max(maxxx,(int)(ccc*100));
			minnn=min(minnn,(int)(ccc*100));
			continue;
		}
		k=(yy-y2)/(x1-x2)*1.0;
		b=yy-k*x1;
		a1=x1*yy; maxx=max(maxx,a1); minn=min(minn,a1);
		a2=x2*y2; maxx=max(maxx,a2); minn=min(minn,a2);
		double c=-b/2/k;
		if(x1<=c&&c<=x2)
			a3=k*c*c+b*c,
			maxx=max(maxx,a3),
			minn=min(minn,a3);
		mp[(int)(minn*100)]++;
		mp[(int)(maxx*100+1)]--;
		maxxx=max(maxxx,(int)(maxx*100));
		minnn=min(minnn,(int)(minn*100));
	}
	cout<<minnn-1<<" "<<maxxx+1<<endl;
	for(int i=minnn-1;i<=maxxx+1;i++)
	{
		num+=mp[i];
		if(i==0) continue;
		printf("%d %d\n",i,num);
		if(num>ax) ax=num,ans=i;
		if(num==ax&&abs(i)>abs(ans)) ax=num,ans=i;
		if(num==ax&&abs(i)==abs(ans)&&i<0) ax=num,ans=i;
	}
	printf("%.2lf\n",(double)1.0*ans/100);
	return 0;
}
/*
input:
5 3 34 34
1 4 1
9 4 2
5 3 3
1 3 3
5 3 2
3 4 5
6 7 5
5 3 8
*/
