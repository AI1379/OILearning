#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack> 
#include <ctime>

using namespace std;

char sinn[100],sout[100],in[100],out[100];
long long T;
void file()
{
	memset(sinn,0,sizeof(sinn));
	memset(sout,0,sizeof(sout));
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	strcat(sinn,"Math");
	strcat(sout,"Math");
	sprintf(sinn+strlen(sinn),"%02d.",T);
	sprintf(sout+strlen(sout),"%02d.",T);
	strcat(in,sinn),strcat(in,"in");
	strcat(out,sout),strcat(out,"out");
}
//4294967296
void random()
{
	long long x,y,xx,yy;
	for(int i=1;i<=10;++i)
	{
		x=xx=y=yy=0;
		while(x==xx||y==yy)
		{
			x=rand()%4294967296ll+1;
			y=rand()%4294967296ll+1;
			while(x>0&&y>0)
			{
				if(rand()%1000000==0)x=0;
				if(rand()%1000000==0)y=0;
				while(x==y)
				{
					x=rand()%4294967296ll+1;
					y=rand()%4294967296ll+1;
				}
			}
			xx=rand()%4294967296ll+1;
			yy=rand()%4294967296ll+1;
			while(xx>0&&yy>0)
			{
				if(rand()%1000000==0)xx=0;
				if(rand()%1000000==0)yy=0;
				while(xx==yy)
				{
					xx=rand()%4294967296ll+1;
					yy=rand()%4294967296ll+1;
				}
			}
		}
		if(rand()%2==0&&x!=0)printf("-");
		cout<<x<<' ';
		if(rand()%2==0&&y!=0)printf("-");
		cout<<y<<endl;
		if(rand()%2==0&&xx!=0)printf("-");
		cout<<xx<<' ';
		if(rand()%2==0&&yy!=0)printf("-");
		cout<<yy<<endl;
		//printf("%lld %lld\n",x,y);
	}
}

long long X1,X2,Y1,Y2;
long long k1,k2;
bool fs;

long long gcd(long long a,long long b)
{
	long long r;
	while(b>0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

long long abs_(long long x)
{
	if(x>0)return x;else return -x;
}

void Main()
{
	for(int TTT=1;TTT<=10;++TTT)
	//while()
	{
		cin>>X1>>Y1>>X2>>Y2;
		if(X1==X2||Y1==Y2)
		{
			printf("Error\n");
			continue;
		}
		if(X1!=0)
		{
			swap(X1,X2);
			swap(Y1,Y2);
		}
		k1=Y1;	k2=X2;
		if((k1<0&&k2<0)||(k1>0&&k2>0))fs=1;else fs=0;
		k1=abs_(k1); k2=abs_(k2);
		long long ggg=gcd(k1,k2);
		k1/=ggg; k2/=ggg;
		printf("y=");
		if(fs)printf("-");
		if((k1==1&&k2!=1)||(k1!=1))cout<<k1;
		if(k2!=1)cout<<"/"<<k2;
		printf("x");
		if(Y1==0)printf("\n");
		else 
			if(Y1<0)cout<<Y1<<"\n";else cout<<"+"<<Y1<<"\n";
	}
}

int main()
{
	srand((unsigned)time(0));
	for(T=0;T<20;T++)
	{
		file();
		freopen(in,"w",stdout);
		random();
		fclose(stdout);
		freopen(in,"r",stdin);
		freopen(out,"w",stdout);
		Main();
		fclose(stdin);
		fclose(stdout);
	}
	return 0;
}
