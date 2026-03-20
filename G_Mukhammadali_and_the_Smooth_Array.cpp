#include<bits/stdc++.h>
#define int long long 
using namespace std;
// const int N=8e3+5;
// int n;
// vector<int>a,b;
// int dp[N];

// signed main(){
//     int _;cin>>_;
//     while(_--){
//         cin>>n;
//         a.assign(n+1,0),b.assign(n+1,0);
//         for(int i=0;i<n;i++)cin>>a[i];
//         for(int i=0;i<n;i++)cin>>b[i];
//         fill(dp,dp+n,0);
//         int m=-1e9,total=accumulate(b.begin(),b.end(),0LL);
//         for(int i=0;i<n;i++){
//             dp[i]=b[i];
//             for(int j=0;j<i;j++){
//                 if(a[j]<=a[i]){
//                     dp[i]=max(dp[i],dp[j]+b[i]);
//                 }
//             }
//             m=max(m,dp[i]);
//         }
//         cout<<total-m<<endl;
//     }
//     return 0;
// }

const int N=8e+5;
int t[N*4];
int n;

void update(int v,int tl,int tr,int idx,int val){
    if(tl==tr){
        t[v]=max(t[v],val);return;
    }
    int tm=(tl+tr)>>1;
    if(idx<=tm)update(v<<1,tl,tm,idx,val);else update(v<<1|1,tm+1,tr,idx,val);
    t[v]=max(t[v<<1],t[v<<1|1]);
}
int range(int v,int tl,int tr,int l,int r){
    if(r<tl || l>tr)return 0;
    if(l<=tl && r>=tr)return t[v];
    int tm=(tl+tr)>>1;
    return max(range(v<<1,tl,tm,l,r),range(v<<1|1,tm+1,tr,l,r));
}

signed main(){
    int _;cin>>_;
    while(_--){
        cin>>n;
        vector<int>a(n),c(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>c[i];
        vector<int>cc=a;
        sort(cc.begin(),cc.end());
        cc.erase(unique(cc.begin(),cc.end()),cc.end());
        int total=accumulate(c.begin(),c.end(),0LL);
        int m=cc.size();

        for(int i=0;i<=4*m;i++)t[i]=0;
        int res=0;
        for(int i=0;i<n;i++){
            int pos=lower_bound(cc.begin(),cc.end(),a[i])-cc.begin()+1;
            int cmax=range(1,1,m,1,pos);
            int dp=cmax+c[i];
            update(1,1,m,pos,dp);
            res=max(res,dp);
        }
        cout<<total-res<<endl;  
    }
    return 0;
}