#include<iostream>
using namespace std;
int c[maxn],v[maxn];
int main()
{
    int n,V;
    cin>>n>>V;
   //�����򣬴Ӻ���ǰ���������������ʱ�ǰ�����С�ֵ�����
    for(int i=n;i>=1;i--)
        cin>>c[i]>>v[i];
    for(int i=1;i<=n;i++)
        for(int j=V;j>=c[i];j--)
            f[j]=max(f[j],f[j-c[i]]+v[i]);
    for(int i=n;i>=1;i--)
        if(f[V]==f[V-c[i]]+v[i])//������ͬ��ѡ�����С�����Ϊ��
        {
            cout<<n-i+1<<' ';
            V-=c[i];
        }
	return 0;
}

