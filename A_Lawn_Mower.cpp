#include<bits/stdc++.h>
#define int long long 
using namespace std;

signed main(){
    int t;cin>>t;
    while(t--){
        int n,w;cin>>n>>w;
        cout<<n-((n/w))<<endl;
    }
    return 0;
}