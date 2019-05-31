#include<bits/stdc++.h>
using namespace std;
int n,p[10][10],x,y,v,k;
char a;
//void l(){
//	for(int i=1;i<=4;i++)
//	{
//		for(int j=1;j<=3;j++)
//		{
//			if(p[i][j]==p[i][j+1]) {
//				p[i][j]*=2;
//				p[i][j+1]=0;
//			}
//			else while(!p[i][j]&&p[i][j+1]){
//				p[i][j]=p[i][j+1];
//				p[i][j+1]=0;
//				j--;
//			}
//		}
//	}
//}
//void r(){
//	for(int i=1;i<=4;i++)
//	{
//		for(int j=4;j>=2;j--)
//		{
//			if(p[i][j]==p[i][j-1]) {
//				p[i][j]*=2;
//				p[i][j-1]=0;
//			}
//			else while(!p[i][j]&&p[i][j-1]){
//				p[i][j]=p[i][j-1];
//				p[i][j-1]=0;
//				j++;
//			}
//		}
//		
//	}
//}
//void u(){
//	for(int i=1;i<=4;i++)
//	{
//		for(int j=1;j<=4;j++)
//		{
//			if(p[i][j]==p[i+1][j]) {
//				p[i][j]*=2;
//				p[i+1][j]=0;
//			}
//			else while(!p[i][j]&&p[i+1][j]){
//				p[i][j]=p[i+1][j];
//				p[i+1][j]=0;
//				i++;
//			}
//		}
//		
//	}
//}
//void d(){
//	for(int i=4;i>=1;i--)
//	{
//		for(int j=1;j<=4;j++)
//		{
//			if(p[i][j]==p[i-1][j]) {
//				p[i][j]*=2;
//				p[i-1][j]=0;
//			}
//			else while(!p[i][j]&&p[i-1][j]){
//				p[i][j]=p[i-1][j];
//				p[i-1][j]=0;
//				i--;
//			}
//		}
//		
//	}
//}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
//	for(int i=1;i<=4;i++)
//	for(int j=1;j<=4;j++) p[i][j]=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>v>>a;
//		p[x][y]=v;
//		if(a=='L') l();
//		else if(a=='R') r();
//		else if(a=='U') u();
//		else d();
	}
	cout<<"Game over!"<<endl;
//	for(int i=1;i<=4;i++)
//	for(int j=1;j<=4;j++)
//	{
//		if(p[i][j]==0) k=1;
//	}
//    if(!k){
//    	cout<<"Game over!"<<endl;
//    	exit(0);
//	}
//	else {
//		for(int i=1;i<=4;i++)
//	    {
//		for(int j=1;j<=4;j++) 
//	    cout<<p[i][j]<<" ";
//	    cout<<endl;
//	    }
//	}
	return 0;
}
