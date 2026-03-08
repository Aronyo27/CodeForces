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

vector<int> bfs(int st){
    vector<int>dist(n+2,-1);
    queue<int>q;
    q.push(st);
    dist[st]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int &it:adj[u]){
            if(dist[it]==-1){
                dist[it]=dist[u]+1;
                q.push(it);
            }
        }
    }
    return dist;
}

signed main(){
    cin>>n;
    if(n==1){cout<<"1"<<endl;return 0;}
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    dfs(1,0,0);
    int u=fNode;
    maxDist=-1;
    dfs(fNode,0,0);
    int v=fNode;
    //cout<<maxDist<<endl;
    vector<int>du=bfs(u);
    vector<int>dv=bfs(v);
    int d=du[v];
    
    for(int i=1;i<=n;i++){
        cout<<max(d,max(du[i],dv[i])+1)<<endl;
    }
    return 0;
}