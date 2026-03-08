#include<bits/stdc++.h>
#define int long long 
using namespace std;

signed main(){
    int n;cin>>n;
    vector<string>s(n);
    //int mx=LLONG_MIN;
    for(int i=0;i<n;i++){
        cin>>s[i];//mx=max(mx,(long long)s[i].size());
    }
    vector<int>adj[26];
    int ans=0;
    for(int i=0;i<n-1;i++){
        bool ok=false;
        for(int j=0;j<min(s[i].size(),s[i+1].size());j++){
            if(s[i][j]!=s[i+1][j]){
                adj[s[i][j]-'a'].push_back(s[i+1][j]-'a');
                ok=true;break;
            }
        }
        if(!ok && s[i].size()>s[i+1].size()){
            ans=1;break;
        }
    }
    if(ans){
        cout<<"Impossible"<<endl;
        return 0;
    }
    queue<int>q;
    vector<int>indegre(26,0);
    for(int i=0;i<26;i++){
        for(int &it:adj[i]){
            indegre[it]++;
        }
    }
    for(int i=0;i<26;i++){
        if(indegre[i]==0)q.push(i);
    }
    vector<int>topo;
    while(!q.empty()){
        int temp=q.front();q.pop();
        topo.push_back(temp);
        for(int &it:adj[temp]){
            indegre[it]--;
            if(indegre[it]==0)q.push(it);
        }
    }
    if(topo.size()!=26)cout<<"Impossible"<<endl;
    else{
        for(int &it:topo)cout<<char(it+'a');
        cout<<endl;
    }
    return 0;
}