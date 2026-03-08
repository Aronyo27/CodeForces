#include<bits/stdc++.h>
#define int long long 
using namespace std;

signed main(){
    int n,m;cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);        
    }
    queue<int>q;
    vector<int>indegree(n+1,0);
    for(int i=1;i<=n;i++){
        for(int it:adj[i])indegree[it]++;
    }
    for(int i=1;i<=n;i++){
        if(indegree[i]==0)q.push(i);
    }
    vector<int>ans;
    while(!q.empty()){
        int temp=q.front();q.pop();
        ans.push_back(temp);        
        for(int it:adj[temp]){
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }
    }
    if(ans.size()!=n){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(int it:ans)cout<<it<<" ";
    cout<<endl;
    return 0;
}