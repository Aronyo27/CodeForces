#include<bits/stdc++.h>
#define int long long 
using namespace std;

signed main(){
    int t;cin>>t;
    while(t--){
        int c,m,x;cin>>c>>m>>x;
        if(c==0 || m==0){cout<<0<<endl;continue;}
        int ans=min({c,m,(c+m+x)/3});
        cout<<ans<<endl;
    }
    return 0;
}