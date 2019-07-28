#include<bits/stdc++.h>
using namespace std;
struct line{
	int num;
	int x1,y1;
	int x2,y2;
};
bool cmp(line l1,line l2){
	int a,b,c,d;
	if(min(max(l1.x1,l1.x2),max(l2.x1,l2.x2))<max(min(l1.x1,l1.x2),min(l2.x1,l2.x2)))
		return l1.num<l2.num;
	if(l2.x1<=l1.x2&&l1.x2<=l2.x2&&l1.x1<l1.x2){
		a=l2.x2-l2.x1;
		b=l2.y1-l2.y2;
		c=l1.x2-l2.x1;
		d=b*c/a;
		if(l2.y1<=l2.y2)
			return l1.y2<=l2.y1+d;
		else
			return l1.y2<=l2.y1-d;
	}
	if(l2.x1<=l1.x1&&l1.x1<=l2.x2&&l1.x1<l1.x2){
		a=l2.x2-l2.x1;
		b=l2.y1-l2.y2;
		c=l1.x1-l2.x1;
		d=b*c/a;
		if(l2.y1<=l2.y2)
			return l1.y1<=l2.y1+d;
		else
			return l1.y1<=l2.y1-d;
	}
}
line lines[5000];
int n;
int main(){
	int i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>lines[i].x1>>lines[i].y1>>lines[i].x2>>lines[i].y2;
		lines[i].num=i+1;
	}
	sort(lines,lines+n,cmp);
	for(i=0;i<n;i++)
		cout<<lines[i].num<<' ';
	system("pause");
	return 0;
}
