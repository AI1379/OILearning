/*#include<bits/stdc++.h>
using namespace std;
bool arc[510][510],visited[510];
int f;
void DFS(int vex){
	int i;
	if(!visited[vex])
		cout<<vex<<endl;
	visited[vex]=true;
	for(i=1;i<=f;i++){
		if(arc[vex][i]){
			arc[vex][i]=false;
			DFS(i);
		}
	}
}
int main(){
	int x,y,i,j,num,start;
	memset(arc,false,sizeof(arc));
	memset(visited,false,sizeof(visited));
	cin>>f;
	for(i=1;i<=f;i++){
		cin>>x>>y;
		arc[x][y]=true;
		arc[y][x]=true;
	}
	start=1;
	for(i=1;i<f;i++){
		num=0;
		for(j=1;j<=f;j++){
			if(arc[i][j])
				num++;
		}
		if(num%2==0){
			start=i;
			break;
		}
	}
	cout<<start;
	DFS(start);
	return 0;
}*/
#include<iostream>
#include<cstring>
using namespace std;
#define maxn 101
int g[maxn][maxn];               //��ͼ���ڽӾ���洢
int du[maxn];                    //��¼ÿ����Ķȣ����������ıߵ���Ŀ
����int circuit[maxn];               //������¼�ҵ���ŷ��·��·��
����int n,e,circuitpos,i,j,x,y,start;
����void find_circuit(int i)         //�����������ȱ�������Ѱ��ŷ��·
����{
����    int j;
����    for (j = 1; j <= n; j++)
����      if (g[i][j] == 1)          //������һ�����������ĵ����
����       {
����            g[j][i] = g[i][j] = 0; 
����            find_circuit(j);
����        } 
����    circuit[++circuitpos] = i;   //��¼��·��
����}

����int main()
����{
����    memset(g,0,sizeof(g));
����    cin >> n >> e;
����    for (i = 1; i <= e; i++)
����    {
����        cin >> x >> y;
����        g[y][x] = g[x][y] = 1;
����        du[x]++;                    //ͳ��ÿ����Ķ�
����        du[y]++;
����    }
����    start = 1;                      //�������㣬�ʹ���㿪ʼѰ�ң������ҵ��ľ���
����    for (i = 1; i <= n; i++)        //ŷ��·��û�����ʹ�����㿪ʼ��
����       if (du[i]%2 == 1)            //�����ҵ��ľ���ŷ����·��(��Ϊÿһ���㶼��ż��)
              start = i;
����    circuitpos = 0;
����    find_circuit(start);
����    for (i = 1; i <= circuitpos; i++)
����        cout << circuit[i] << ' ';
����    cout << endl;
����    return 0;
����}


