#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
const int inf=999999999;
using namespace std;
int n;
int l=inf,r=-inf,h=-inf,d=inf;
int yx,yy;
int main()
{
	freopen("coordinates.in","r",stdin);
    freopen("coordinates.out","w",stdout);
    int x[401],y[401];
    char a[401][401];
    cin>>n;
    for(int i=1;i<=400;i++)
     for(int j=1;j<=400;j++)
     {
         a[i][j]='.';
     }
    
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
        if(x[i]<l) l=x[i];
        if(x[i]>r) r=x[i];
        if(y[i]<d) d=y[i];
        if(y[i]>h) h=y[i];
    }
    
    yx=-l+1,yy=h+1;
//     cout<<l<< ' '<<r<<' '<<d<<' '<<h<<endl;
    // cout<<yx<<' '<<yy<<endl;
    for(int i=1;i<=r-l+1;i++)
    {
    	a[yy][i]='-';
	}
	for(int i=0;i<=h-d+1;i++)
    {
    	a[i][yx]='|';
	}
	
    for(int i=0;i<=n;i++)
    {

        a[abs(yy-y[i])][x[i]+yx]='*';
    }   
    a[yy][yx]='+';
//	cout<<yx<<yy<<endl;
	for(int i=min(yy,1);i<=max(h-d+1,yy);i++,cout<<endl)
	for(int j=min(yx,1);j<=max(r-l+1,yx);j++)
	{
		cout<<a[i][j];
	}
    // system("pause");
}

-
 */

// 0 0  -> 11 6
// -4 2->  7 4
// 8 -3 -> 19 9
