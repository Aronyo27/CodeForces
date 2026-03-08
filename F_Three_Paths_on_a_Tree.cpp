#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int MAXN=2e5+5;
vector<int>adj[MAXN];
int dist1[MAXN],p[MAXN],d,d1,d2,mDist=-1e4;

// void dfs(int node,int par,int dist){
//     if(dist>mDist){
//         mDist=dist;
//         d=node;
//     }
//     for(int &it:adj[node]){
//         if(it==par)continue;
//         dfs(it,node,dist+1);
//     }
// }
int bfs(int st){
    for(int i=0;i<n;i++)dist1[i]=-1,p[i]=-1;
    queue<int>q;
    q.push(st);
    dist1[st]=0;
    int f=st;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int &v:adj[u]){
            if(dist1[v]==-1){
                dist1[v]=dist1[u]+1;
                p[v]=u;
                q.push(v);
                if(dist1[v]>dist1[f])f=v;
            }
        }
    }
    return f;
}

signed main(){
    //int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    //dfs(1,-1,0);
    d1=bfs(0);
    // mDist=-1;
    // dfs(d1,-1,0);
    d2=bfs(d1);
    int diameter=dist1[d2];
    if(diameter==n-1){
        cout<<d1+1<<" "<<d1+2<<" "<<d2+1<<endl;
        return 0;
    }
    vector<int>diam;
    int temp=d2;
    while(temp!=-1){
        diam.push_back(temp);
        temp=p[temp];
    }
    reverse(diam.begin(),diam.end());
    queue<int>q;
    vector<int>dd(n,-1);
    for(int &it:diam){
        dd[it]=0;
        q.push(it);
    }
    int ex=0,d3=d1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int &v:adj[u]){
            if(dd[v]==-1){
                dd[v]=dd[u]+1;
                q.push(v);
                if(dd[v]>ex){
                    ex=dd[v];d3=v;
                }
            }
        }
    }
    pair<int,int>mx={dd[0],0};
    for (int v=1;v<n;v++) {
        mx=max(mx,{dd[v],v});
    }

    cout<<((diam.size())-1+mx.first)<<endl;
    cout<<diam[0]+1 <<" " << mx.second+1 <<" "<< diam.back()+1<<endl;
    return 0;
}
