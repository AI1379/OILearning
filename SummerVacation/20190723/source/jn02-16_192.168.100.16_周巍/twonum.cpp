#include<bits/stdc++.h>
using namespace std;
long long m,h1,h2;
int t,a2,x2,y2,a1,x3,y3;
int main()
{
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
    	int flag=0;
    	cin>>m>>h1>>a1>>x3>>y3>>h2>>a2>>x2>>y2;
    	for(int j=1;j<=1000000;j++)
    	{
    		h1=(h1*x3+y3)%m;
    		h2=(h2*x2+y2)%m;
    		if(h1==a1&&h2==a2){
    			cout<<j<<endl;
    			flag=1;
    			break;
			}
		}
		if(!flag)
		cout<<-1<<endl;
	}
	return 0;
}
