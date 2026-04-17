#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;

signed main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        int cnt[n+1];
        for(int i=0;i<=n;i++)cnt[i]=0;
        for(int i=0;i<m;i++){
            int u,v;cin>>u>>v;
            cnt[u]++,cnt[v]++;
        }
        map<int,int>m;
        for(int i=1;i<=n;i++)m[cnt[i]]++;
        vector<int>v;
        for(auto &[a,b]:m)v.push_back(b);
        sort(v.begin(),v.end());;
        if(v.size()==3)cout<<v[1]<<" "<<v[2]/v[1]<<endl;
        else cout<<v[0]-1<<" "<<v[1]/(v[0]-1)<<endl;
    }
    return 0;
}