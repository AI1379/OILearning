#include <bits/stdc++.h>
#define LoL long long
using namespace std;
int main()
{
	freopen("intersect.in","r",stdin);
	freopen("intersect.out","w",stdout);
	int n;
	double x1,y1,x2,y2;
	cin>>n>>x1>>y1>>x2>>y2;
	double x=x1*1.0*y1,y=x2*1.0*y2;
	if(x*y>0) printf("%.2lf",(abs(x)>abs(y)?x:y));
	else printf("%.2lf",(y<0?y:x));
	return 0;
}
