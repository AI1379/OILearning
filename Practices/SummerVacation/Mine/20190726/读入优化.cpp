#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int read()
{
	char ch=getchar(); int x=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-48; ch=getchar();}
	return x;
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=read(); m=read(); //scanf("%d%d",&n,&m);

}
