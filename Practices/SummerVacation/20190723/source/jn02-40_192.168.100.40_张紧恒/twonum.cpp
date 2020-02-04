#include <bits/stdc++.h>
#define LoL long long
using namespace std;

LoL zz1,zz2,st1,st2,st,zz;

LoL gcd(LoL s1,LoL z1,LoL s2,LoL z2)
{
	//cout<<s1<<" "<<z1<<" "<<s2<<" "<<z2<<endl;
	LoL i=1;
	LoL a1=s1,a2=s2;
	if(s1==s2)
		return a1;
	if(s1!=s2&&z1==z2)
		return -1;
	while(a1!=a2)
	{
		i++;
		if(a1<a2) a1+=z1;
		else a2+=z2;
		//if(a1>=9801000000&&a1<=9801209999)
		//cout<<a1<<" "<<a2<<endl;
		if(i>=50000000)
		{
			a1=-1;//cout<<"@!%$";
			break;
		}
	}
	return a1;
}

LoL xz(LoL h,LoL x,LoL y,LoL m,LoL a)
{
	LoL b[100001];
	memset(b,0,sizeof(b));
	for(int i=1 ; i<=500001 ; i++)
	{
		h=(h*x+y)%m;
		if(b[h]==0)
			b[h]=i;
		else
		{
			zz=i-h;
			//cout<<h<<" "<<i<<" "<<h-i;
			break;
		}
	}
//	cout<<zz;
	if(b[a]==0) return -1;
	else {st=b[a];return 0;}
}

void mc()
{
	LoL m,h1,a1,x1,y1,h2,a2,x2,y2;
	cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
	if(xz(h1,x1,y1,m,a1)==-1) {cout<<-1;return;}
	else st1=st,zz1=zz;
	if(xz(h2,x2,y2,m,a2)==-1) {cout<<-1;return;}
	else st2=st,zz2=zz;
	cout<<gcd(st1,zz1,st2,zz2);
	return;
}

int main()
{
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	int n;
	cin>>n;
	while(n--)
	{
		mc();
		cout<<endl;
	}
	return 0;
}
