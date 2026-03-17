#include<bits/stdc++.h>
#define int long long 
using namespace std;

signed main(){
    int _;cin>>_;
    while(_--){
        int n;cin>>n;
        vector<int>a(n+1),pSum(n+1,0);
        for(int i=1;i<=n;i++){
            cin>>a[i];
            pSum[i]=pSum[i-1]+a[i];
        }
        int l=1,r=n;
        while(l<r){
            int m=(l+r)>>1;
            int k=m-l+1;
            cout<<"? "<<k;
            for(int i=l;i<=m;i++){
                cout<<" "<<i;
            }
            cout<<endl;
            int __;cin>>__;
            int ___=pSum[m]-pSum[l-1];
            if(__>___)r=m;
            else l=m+1;
        }cout<<"! "<<r<<endl;
    }
    return 0;
}