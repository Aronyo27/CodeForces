#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,k;
const int mx=2e5+10;
vector<int>adj[mx];

void dfs(int node,int par,vector<int>&s){
    for(auto &v:adj[node])if(v!=par){dfs(v,node,s);s[node]+=s[v];}
}

signed main(){
    int _;cin>>_;
    while(_--){
        cin>>n>>k;
        for(int i=0;i<n;i++)adj[i].clear();
        for(int i=0;i<n-1;i++){
            int u,v;cin>>u>>v;u--,v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>s(n,1);
        dfs(0,-1,s);
        int ans=0;
        for(int i=0;i<n;i++){
            ans++;
            if(s[i]>=k)ans+=n-s[i];
            if(n-s[i]>=k)ans+=s[i];
        }
        cout<<ans<<endl;
    }
}