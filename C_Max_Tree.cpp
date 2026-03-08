#include<bits/stdc++.h>
#define int long long 
using namespace std;

signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>adj[n+1],indegree(n+1,0),ans;
        for(int i=0;i<n-1;i++){
            int a,b,x,y;cin>>a>>b>>x>>y;
            if(x>y){
                adj[b].push_back(a);
                indegree[a]++;
            }else{
                adj[a].push_back(b);
                indegree[b]++;
            }
        }
        queue<int>q;
        for(int i=1;i<=n;i++)
            if(indegree[i]==0)q.push(i);
        while(!q.empty()){
            int t=q.front();q.pop();
            ans.push_back(t);
            for(int&it:adj[t]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        vector<int>finalans(n+1);
        for(int i=0;i<n;i++){
            finalans[ans[i]]=i+1;
        }
        for(int i=1;i<=n;i++)cout<<finalans[i]<<" ";
        cout<<endl;
    }
    return 0;
}