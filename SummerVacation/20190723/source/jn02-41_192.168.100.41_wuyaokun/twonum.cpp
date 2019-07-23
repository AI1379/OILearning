
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T;
int main()
{
	freopen("twonum.in","r",stdin);
    freopen("twonum.out","w",stdout);
    int m,h1,a1,h2,a2,x1,y1,x2,y2;
    cin>>T;
    while (T--)
    {
        cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
        for(int i=1;i<=20000000;i++)
        {
            if(h1==a1&&h2==a2) {
                cout<<i-1<<endl;
                break;
            }
            h1=(x1*h1+y1)%m;
            h2=(x2*h2+y2)%m;
            if(i==20000000) cout<<-1<<endl;
        }
        /* code */
    }
    
}
