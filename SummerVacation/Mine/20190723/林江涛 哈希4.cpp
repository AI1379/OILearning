#include<bits/stdc++.h>
using namespace std;
const int MOD=100000007;
const int B=37;
unsigned long long i,j,k,n,hash[1001][1001],ans,len1,len2,tmp,l,r,mid;
string s[1001];
bool judge(int index1,int index2,int pos){
	return hash[index1][pos]==hash[index2][pos];
}
int main(){
	cin>>n;
	for(i=0;i<n;i++)
		cin>>s[i];
	for(i=0;i<n;i++){
		len1=s[i].length();
		for(j=1;j<=len1;j++){
			hash[i][j]=(hash[i][j-1]*B+(unsigned long long)(s[i][j-1]))%MOD;
		}
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			tmp=0;
			len1=s[i].length();
			len2=s[j].length();
			l=0;
			r=max(len1,len2);
			while(l<=r){
				mid=(l+r)/2;
				if(judge(i,j,mid)){
					l=mid+1;
					tmp=mid;
				}
				else
					r=mid-1;
			}
			ans+=(tmp*2);
		}
	}
	cout<<ans;
	return 0;
}
