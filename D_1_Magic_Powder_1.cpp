#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;

bool ok(int val,vector<int>&a,vector<int>&b){
    int sum=0;
    for(int i=0;i<n;i++){
        int t=a[i]*val;
        if(t>b[i])sum+=(t-b[i]);
        if(sum>k)return false;
    }
    return true;
}

signed main(){
    int t=1;//cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        int l=0,r=1e9,ans=0;
        while(l<=r){
            int m=(r-l)/2+l;
            if(ok(m,a,b))ans=m,l=m+1;
            else r=m-1;
        }
        cout<<ans<<endl;
    }
}