#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n;
bool _1(int b){
    int __=(b*(b-1))/2;return __<=n;
}
signed main(){
    int _;cin>>_;
    while(_--){
        cin>>n;
        int l=1,r=2e9,ans=1;

        while(l<=r){
            int m=(r-l)/2+l;
            if(_1(m)){
                ans=m;l=m+1;
            }else r=m-1;
        }
        int f=ans*(ans-1)/2;
        int ans1=n-f;
        cout<<ans1+ans<<endl;
    }
    return 0;
}