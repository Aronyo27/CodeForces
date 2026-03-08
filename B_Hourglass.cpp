#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    int t;cin>>t;
    while(t--){
        int s,m,k;cin>>s>>k>>m;
        int n=m/k;
        int x;
        if(n%2==0)x=s;
        else x=min(s,k);
        int rTime=m%k;
        int ans=x-rTime;
        cout<<max(0LL,ans)<<endl;
    }
    return 0;
}