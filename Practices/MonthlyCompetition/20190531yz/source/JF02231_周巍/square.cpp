#include<bits/stdc++.h>
using namespace std;
double n,k,s1,s2,s3;
int cnt;
int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
    	for(int j=1;j<=4;j++)
        {
    	    cnt++;
    	    if(cnt%3==1) s1+=n;
    	    else if(cnt%3==2) s2+=n;
    	    else s3+=n;
	    }
	    n=sqrt(pow((n/2),2)*2);
	}
    printf("%.3lf %.3lf %.3lf\n",s1,s2,s3);
    return 0;
 } 

