#include<iostream>
using namespace std;
long long t,m,a1,x1,ti,y1,fl,a2,x2,tn1,tn2,t1,t2,y2,w1,w2;
int main()
{
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ti=fl=0;
		cin>>m>>w1>>a1>>x1>>y1>>w2>>a2>>x2>>y2;
		while(1)
		{
			if(w1==a1&&w2==a2)break;
			ti++;
			w1=(x1*w1+y1)-(x1*w1+y1)/m*m,w2=(x2*w2+y2)-(x2*w2+y2)/m*m;
			if(ti==12345678)//Ê±¼ä×ã¹»´ó 
			{	fl=1;
				cout<<-1<<endl;
				break;
			}
		}
		if(fl)continue;
		cout<<ti;
	}
	return 0;
}
		
