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
long long Data[10]={12,365,8520,12345,67890,32768,15614,7865,99991,100000};
void files()
{
	memset(sinn,0,sizeof(sinn));
	memset(sout,0,sizeof(sout));
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	strcat(sinn,"Name");
	strcat(sout,"Name");
	sprintf(sinn+strlen(sinn),"%d.",T);
	sprintf(sout+strlen(sout),"%d.",T);
	strcat(in,sinn),strcat(in,"in");
	strcat(out,sout),strcat(out,"ans");
}

void MakeData()
{
	int n=Data[T];
	cout<<n<<endl;
}

void Main()
{

}

int main()
{
	srand((unsigned)time(0));
	for(T=0;T<10;T++)
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
