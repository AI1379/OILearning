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
int T;
long long Data[20]={10ll,50ll,110ll,1000ll,100000ll,9000000ll,500000000ll,700000000ll,5000000000ll,10000000000ll,100000000000ll,1000000000000ll,10000000000000ll,100000000000000ll,1000000000000000ll,10000000000000000ll,100000000000000000ll,500000000000000000ll,700000000000000000ll,1000000000000000000ll};
void files()
{
	memset(sinn,0,sizeof(sinn));
	memset(sout,0,sizeof(sout));
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	strcat(sinn,"Outing");
	strcat(sout,"Outing");
	sprintf(sinn+strlen(sinn),"%02d.",T);
	sprintf(sout+strlen(sout),"%02d.",T);
	strcat(in,sinn),strcat(in,"in");
	strcat(out,sout),strcat(out,"ans");
}

void MakeData()
{
	long long n=Data[T];
	cout<<n<<" "<<rand()%999500+500<<endl;
}
 
long long pow_mod(long long a,long long n,long long m)
{
	if (n==0) return 1;
	if (n==1) return a%m;
	long long x=pow_mod(a,n/2,m);
	long long ans=(long long)x*x%m;
	if (n%2) ans=ans*a%m;
	return (long long)ans;
}

long long n,k;  
long long w;

int Main() 
{
    cin>>n>>k;
    w=pow_mod(n,n,k)-n%k+1;
    for (;w<0;w+=k);
    cout<<w%k<<endl;
	return 0; 
}



int main()
{
	srand((unsigned)time(0));
	for(T=0;T<20;T++)
	{
		files();
		freopen(in,"w",stdout);
		MakeData();
		fclose(stdout);
		freopen(in,"r",stdin);
		freopen(out,"w",stdout);
		Main();
		fclose(stdin);
		fclose(stdout);
	}
	return 0;
}
