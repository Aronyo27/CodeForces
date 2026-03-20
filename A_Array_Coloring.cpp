#include<bits/stdc++.h>
using namespace std;

int main(){
    int _;cin>>_;
    while(_--){
        int n;cin>>n;
        vector<int>b(n),m,q;
        vector<pair<int,int>>a;
        int c=1;
        for(int i=0;i<n;i++){
            cin>>b[i];
            // if(c==0)c=1;
            // else c=0;
            c=1-c;
            a.push_back({b[i],c});
            m.push_back(c);
        }
        sort(a.begin(),a.end());
        for(auto  &i:a)q.push_back(i.second);
        // for(auto i:m)cout<<i<<" ";
        // cout<<endl;
        // for(int i:q)cout<<i<<" ";cout<<endl;
        bool ok=true;
        for(int i=1;i<n;i++){
            if(q[i]==q[i-1])ok=false;
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;               
    }
    return 0;
}