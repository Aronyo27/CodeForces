#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mx=1e9;
int n,m,k;

bool sol(int x){
    int pRow=(m/(x+1))*x+m%(x+1);
    return pRow*n>=k;
}

signed main(){
    int _;cin>>_;
    while(_--){
        //int n,m,k;
        cin>>n>>m>>k;
        int l=0,r=m,ans=m;
        while(l<=r){
           int mid=(l+r)>>1;
           if(sol(mid))r=mid-1,ans=mid;
           else l=mid+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}