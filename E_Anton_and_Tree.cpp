#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int MAX=3e5+10;
int n,Node,maxDist=-1e4;
vector<int>col,adj[MAX];

void dfs(int n,int par,int dist){
    if(dist>maxDist){
        maxDist=dist;
        Node=n;
    }
    for(int &it:adj[n]){
        if(par==it)continue;
        int a=(col[it]!=col[n])?1:0;
        dfs(it,n,dist+a);
    }
}
signed main(){
    cin>>n;
    col.assign(n,0);
    for(int i=0;i<n;i++)cin>>col[i];
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0,-1,0);
    maxDist=-1e3;
    dfs(Node,-1,0);
    cout<<(maxDist+1)/2<<endl;
}