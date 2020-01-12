#include<bits/stdc++.h>
using namespace std;
int  main(){
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	bool a[201][201]={0},b=0,c=0;
	int x1=0,x2=211,y1=211,y2=0,n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int X,Y;
		cin>>X>>Y;
		    a[X+100][Y+100]=1;
		if(X<0&&100+X<x2)x2=100+X;
		else if(X>0&&X+100>x1) x1=100+X;
		if(Y<0&&100+Y<y1)y1=Y+100;
		else if(Y>0&&Y+100>y2) y2=Y+100;
	}
	for(int i=y2;i>=y1;i--){
		if(x2>100){
			cout<<'|';
			b=1;
			for(int j=1;j<x2-100;j++)
			    cout<<'.';
		}
		for(int j=x2;j<=x1;j++){
			if(x1<0&&!c){
				i++;
				cout<<'-';
				if(j==x1){
					cout<<endl;
					c=1;
				}
			}
		    else if(a[j][i])
			    cout<<'*';
			else if(i==100&&j==100)
			    cout<<'+';
			else if(i==100)
			    cout<<'-';
			else if(j==100)
			    cout<<'|';
			else 
			    cout<<'.';    
	    }
	    if(y2<=100){
	    	for(int j=1;j<100-y2;j++)
	    	    cout<<'.';
		    cout<<'|';
		}
	    cout<<endl;
	}
	return 0;
}
