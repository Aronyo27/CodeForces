#include <bits/stdc++.h>
#define int long long
using namespace std;
     
const int maxn = 200010;
int n, m, k, vis[maxn];
vector<int> V,adj[maxn];

void dfs(int node){
    vis[node]=1;V.push_back(node);
    for(int &it:adj[node]){
        if(!vis[it]){dfs(it);
        V.push_back(node);}
    }
}
signed main(){
    int t=1;//cin>>t;
    while(t--){
        cin>>n>>m>>k;
        for(int i=0;i<m;i++){
            int x,y;cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1);
        int len=(2*n+k-1)/k;
        for(int i=0;i<k;i++){
            int l=i*len,r=min((int)V.size(),l+len)-1;
            if(l>r)puts("1 1");
            else{
                cout<<r-l+1;
                for(int idx=l;idx<=r;idx++)cout<<" "<<V[idx];
                cout<<endl;
            }
        }
    }
    return 0;
}
    