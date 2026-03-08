#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int MAX=3e5+10;
int n;
vector<int>adj[MAX];
int fNode,maxDist;

void dfs(int node,int par,int dist){
    if(dist>maxDist){
        maxDist=dist;
        fNode=node;
    }
    for(int &it:adj[node]){
        if(it==par)continue;
        dfs(it,node,dist+1);
    }
}

signed main(){
    int n;cin>>n;
    if(n==1){
        cout<<"0"<<endl;
        return 0;
    }
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);        
    }
    dfs(1,0,0);
    int st=fNode;
    maxDist=-1e9;
    dfs(fNode,0,0);
    cout<<3*maxDist<<endl;
    return 0;    
}
