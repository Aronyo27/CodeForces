#include<bits/stdc++.h>
#define int long long 
using namespace std;

signed main(){
    int n,m;cin>>n>>m;
    vector<int>adj[n+1],indegree(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0)q.push(i);
    }
    vector<int>topo;
    while(!q.empty()){
        if(q.size()>=2){
            cout<<"No"<<endl;return 0;
        }
        int temp=q.front();q.pop();
        topo.push_back(temp);
        for(int &it:adj[temp]){
            indegree[it]--;if(indegree[it]==0)q.push(it);
        }
    }
    if(topo.size()!=n){
        cout<<"No"<<endl;
        return 0;
    }
    vector<int>ans(n+1);
    for(int i=0;i<n;i++){
        ans[topo[i]]=i+1;
    }
    cout<<"Yes"<<endl;
    for(int i=1;i<=n;i++)cout<<ans[i]<<" "; 
    return 0;
}