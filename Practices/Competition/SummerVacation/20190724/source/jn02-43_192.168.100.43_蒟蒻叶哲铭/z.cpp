#include<bits/stdc++.h>
using namespace std;
int p,k,n,m,f[50001],v[501],w[501],s[501],ans=9999999,vv[501],ww[501],ss[501],ff[50001],anss=9999999,sum,summ;
int main()
{
	freopen("z.in","r",stdin);
	freopen("z.out","w",stdout);
	scanf("%d%d%d%d",&n,&p,&m,&k);
	memset(f,999999,sizeof(f));
	memset(ff,999999,sizeof(ff));
	f[0]=0;
	ff[0]=0;
	for(int i=1;i<=n;++i)scanf("%d%d%d",&v[i],&w[i],&s[i]),sum+=v[i]*s[i];
	for(int i=1;i<=n;++i)
	for(int j=sum;j>=0;--j)
	for(int kk=0;kk<=s[i];++kk)if(j>=kk*v[i])f[j]=min(f[j],f[j-kk*v[i]]+kk*w[i]);
	for(int i=sum;i>=m;--i)ans=min(ans,f[i]);
	printf("%d\n",ans);
	for(int i=1;i<=p;++i)scanf("%d%d%d",&vv[i],&ww[i],&ss[i]),summ+=vv[i]*ss[i];
	for(int i=1;i<=p;++i)
	for(int j=summ;j>=0;--j)
	for(int kk=0;kk<=ss[i];++kk)if(j>=kk*vv[i])ff[j]=min(ff[j],ff[j-kk*vv[i]]+kk*ww[i]);
	for(int i=summ;i>=ans;--i)anss=min(ff[i],anss);
	if(anss<=k)printf("%d",anss);
	else printf("FAIL");
	return 0;
}
