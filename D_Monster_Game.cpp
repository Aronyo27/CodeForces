#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n;
int bs(int idx,vector<int>&a,vector<int>&b){
    int temp=0;
    int t=n-idx-1;
    for(int i=0;i<n;i++){
        int t1=t-b[i];
        if(t1>=0)temp+=(i+1)*t1;
        else break;
    }
    return temp;
}

signed main(){
    int t;cin>>t;
    while(t--){
        //int n;
        cin>>n;
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int j=0;j<n;j++)cin>>b[j];
        sort(a.begin(),a.end());
        vector<int>pf(n+1,0);
        for(int i=0;i<n;i++)pf[i+1]=pf[i]+b[i];
        int ans=0;
        for(int i=0;i<n;i++){
            int x=a[i];
            int cnt=n-i;
            int t=upper_bound(pf.begin(),pf.end(),cnt)-pf.begin()-1;
            ans=max(ans,x*t);
        }
        cout<<ans<<endl;
    }
    return 0;
}