#include<bits/stdc++.h>
using namespace std;
bool arc[100][100];
int main(){
	int i,j,k,m,n,x,y,num,ans;
	memset(arc,false,sizeof(arc));
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>x>>y;
		arc[x][y]=true;
	}
	for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(arc[i][k]&&arc[k][j])
					arc[i][j]=1;
	ans=0;
	for(i=1;i<=n;i++){
		num=0;
		for(j=1;j<=n;j++){
			if(arc[i][j])
				num++;
		}
		if(num>=(n+1)/2)
			ans++;
		num=0;
		for(j=1;j<=n;j++){
			if(arc[j][i])
				num++;
		}
		if(num>=(n+1)/2)
			ans++;
	}
	cout<<ans;
	return 0;
}
