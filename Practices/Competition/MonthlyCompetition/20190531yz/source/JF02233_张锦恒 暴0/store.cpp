#include<bits/stdc++.h>
using namespace std;

long long T,t,a,b,c;

int main()
{
	freopen("store.in","r",stdin);
	freopen("store.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c;
		if(a>b) t=a,a=b,b=t;
		if(a+b>=5*c)
		{
			if(a<c*2)
			{
				cout<<a;
			}
			else
				cout<<c+(a+b)/3;
		}
		else
		{
			if((a-1)*3<=(b-1)*2)
				cout<<2*a;
			else
			{
				int k=b-a,ans;
				ans+=k*2;
				a-=ans;
				if(a%3==0) ans+=2*a/3;
				else ans+=2*a/3+1;
				cout<<ans; 
			}
		}
		cout<<"\n";
	}
	return 0;
}

/*
7 9 6
6 8 5
5 6 5
4 5 4
3 3 4
2 2 3
0 1 3

6 7 5
5 6 4
4 4 4
3 3 3
2 1 3
1 0 2

6 8 x
5 6 x
4 5 x
3 3 x
2 2 x

a+b>5*n......

6 10 x
5 8 3
4 7 2
3 5 2
2 4 1
1 2 1
0 1 0

5 10 3
4 8 3
3 7 2
2 5 2
1 4 1
0 2 1


4 3 3
2 2 3
1 1 2

3 2 2
1 1 2
0 0 1

4 4 3
3 3 2
1 3 2
0 2 1(3)

2 3 3
1 2 2
0 0 2

5 5 3
4 4 2
3 2 2
2 1 1
0 0 1

3 4 3
2 3 2
1 1 2
0 0 1

4 3 3
2 2 2
0 1 2
*/
