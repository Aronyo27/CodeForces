#include<bits/stdc++.h>
#define int long long 
using namespace std;
vector<int>a;
int n;

int check(int val){
    int sm=accumulate(a.begin(),a.end(),0LL)+val;
    int cnt=0;
    for(int i=0;i<n;i++)if(a[i]*2LL*n<sm)cnt++;
    return cnt>n/2;
}

signed main(){
    int t;cin>>t;
    while(t--){
        //int n;
        cin>>n;
        a.assign(n,0);
        for(int i=0;i<n;i++)cin>>a[i];
        if(n<=2){cout<<-1<<endl;continue;}
        int l=0,r=1e18,ans=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(check(m)){
                ans=m;r=m-1;
            }else l=m+1;
        }
        cout<<ans<<endl;      
    }
    return 0;
}