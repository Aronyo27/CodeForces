#include<bits/stdc++.h>
#define int long long 
using namespace std;


signed main(){
    int _;cin>>_;
    while(_--){
        int n;cin>>n;
        string s;cin>>s;
        string s1=s;sort(s1.begin(),s1.end());
        if(s==s1){
            cout<<"Bob"<<endl;continue;
        }
        vector<int>pos;
        for(int i=0;i<n;i++)if(s1[i]!=s[i])pos.push_back(i);
        cout<<"Alice"<<endl;
        cout<<pos.size()<<endl;
        for(auto &i:pos)cout<<i+1<<" ";
        cout<<endl;
    }
    return 0;
}