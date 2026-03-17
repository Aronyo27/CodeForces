#include<bits/stdc++.h>
#define ll long long 
using namespace std;


int main(){
    int t;cin>>t;
    while(t--){
        ll k;cin>>k;
        ll l=1,r=2e18+5,ans=0;
        while(l<=r){
            ll m=(l+r)>>1;
            ll on=m-(ll)sqrtl(m);
            if(on>=k)r=m-1,ans=m;
            else l=m+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}