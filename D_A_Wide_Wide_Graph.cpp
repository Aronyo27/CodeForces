#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e5+5;
vector<int>adj[MAXN];
int dist1[MAXN],dist2[MAXN],d1,d2,mDist=-1e4;

void dfs(int node,int par,int dist){
    if(dist>mDist){
        mDist=dist;
        d1=node;
    }
    for(int &it:adj[node]){
        if(it==par)continue;
        dfs(it,node,dist+1);
    }
}
void bfs(int node,int n,int *dist){
    for(int i=1;i<=n;i++)dist[i]=-1;
    dist[node]=0;
    queue<int>q;q.push(node);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int &it:adj[u]){
            if(dist[it]==-1){
                dist[it]=dist[u]+1;
                q.push(it);
            }
        }
    }
}

signed main(){
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,-1,0);
    bfs(d1,n,dist1);
    d2=1;
    for(int i=1;i<=n;i++){
        if(dist1[i]>dist1[d2])d2=i;
    }   
    bfs(d2,n,dist2);
    vector<int>f(n);
    for(int i=1;i<=n;i++){
        f[i-1]=max(dist1[i],dist2[i]);
    }
    sort(f.begin(),f.end());
    int p=0;
    for(int i=1;i<=n;i++){
        while(p<n&&f[p]<i)p++;
        if(p==n)cout<<n<<" ";
        else cout<<min(n,p+1)<<" ";
    }
    cout<<endl;
}