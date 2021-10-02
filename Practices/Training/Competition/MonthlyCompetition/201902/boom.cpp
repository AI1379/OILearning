#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
map<int,int>ma;
int n,a[100001],ordered_a[100001]={-2e9},num;
int main(){
	freopen("boom.in","r",stdin);
	freopen("boom.out","w",stdout);
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ordered_a[i]=a[i];
	}
	sort(ordered_a+1,ordered_a+n+1); 
	for(i=1;i<=n;i++)
		if(ordered_a[i]!=ordered_a[i-1])
			ma[ordered_a[i]]=++num;
	for(i=1;i<n;i++)
		printf("%d ",ma[a[i]]);
	printf("%d\n",ma[a[i]]);
	return 0;
}
