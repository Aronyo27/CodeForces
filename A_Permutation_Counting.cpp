#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,k;
vector<int>a;

int solve(int val){
    int tm=0;
    for(int &x:a){
        if(val>x)tm+=(val-x);
        if(tm>k)return 0;
    }
    return (tm<=k);
}

signed main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>k;
        a.assign(n,0);
        for(int &x:a)cin>>x;

        int l=0,r=1e12+5,ans=0;
        while(l<=r){
            int m=(l+r)>>1;
            if(solve(m))l=m+1,ans=m;
            else r=m-1;
        }
        int extra=0,tm=0;
        for(int &x:a){
            if(x>ans)extra++;
            if(ans>x)tm+=(ans-x);
        }
        int parbo=k-tm;
        ans=ans*n-n+1+parbo+extra;
        cout<<ans<<endl;
    }
    return 0;
}
