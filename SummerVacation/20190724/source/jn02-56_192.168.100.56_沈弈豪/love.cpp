#include<bits/stdc++.h>
using namespace std;
long long a,b,t,numa,numb,num,ans,A[100],B[100];
int main()
{
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		numa=0;numb=0;num=0;ans=0;
		cin>>a>>b;
		while(a>0)
		{
			A[++numa]=a%2;
			a/=2;
		}
		while(b>0)
		{
			B[++numb]=b%2;
			b/=2;
		}
		//	cout<<numb<<" ";
		//cout<<endl;
		ans=((numa-1)+(numb-1))*(numb-numa+1)/2;
		num=0;
//		cout<<"     ";
		for(int i=1;i<=numb;++i)
		{
			if(B[i]==0)
			num++;
//			cout<<B[i]<<" ";
		}
		if(num>1)
		ans=ans-numb+1;
		else
		{
			num=numb;
			while(B[num]==1)
			{
				num--;
			}
			ans=ans-num+1;	
		}
//		cout<<num<<" ";
		num=numa;
		while(A[num]==1)
		{
			num--;
		}
		ans=ans-numa+num+1;
//		cout<<num<<" ";
		cout<<ans<<endl;
	}
}
