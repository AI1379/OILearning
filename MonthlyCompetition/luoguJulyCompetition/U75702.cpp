#include<bits/stdc++.h>
using namespace std;
int main(){
    int tmp,i,n,maxx=0;
    queue<int>q;
    vector<int>x;
    vector<int>::iterator it,address;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>tmp;
        x.push_back(tmp);
    }
    for(i=1;i<n/2;i++){
        for(it=x.begin();it!=x.end();it++){
            if(*it>=maxx&&it!=x.end()-1){
                maxx=*it;
                address=it;
            }
        }
        q.push(*it);
        q.push(*(it+1));
        x.erase(it);
        x.erase(it);
    }
    while(!q.empty()){
        cout<<q.front();
        q.pop();
    }
    system("pause");
    return 0;
}