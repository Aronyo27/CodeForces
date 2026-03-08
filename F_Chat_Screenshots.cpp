#include<bits/stdc++.h>
#define int long long 
using namespace std;

signed main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int>adj[n+1],indegree(n+1);
        vector<vector<int>>vec(k,vector<int>(n,0));
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++){
                cin>>vec[i][j];
            }
        }
        for(int i=0;i<k;i++){
            for(int j=1;j<n-1;j++){
                adj[vec[i][j]].push_back(vec[i][j+1]);
                indegree[vec[i][j+1]]++;
            }
        }
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0)q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int temp=q.front();q.pop();
            cnt++;
            for(int &it:adj[temp]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        if(cnt!=n)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}