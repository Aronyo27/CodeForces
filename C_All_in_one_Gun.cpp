#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>a,pSum;
signed main(){
    int _;cin>>_;
    while(_--){
        int n,h,k;cin>>n>>h>>k;
        a.assign(n,0),pSum.assign(n,0);
        int tm=0;
        for(int i=0;i<n;i++){
            cin>>a[i]; 
            tm+=a[i];
            pSum[i]=tm;            
        }
        int sum=pSum[n-1];
        vector<int>pMin(n),sMax(n);
        for(int i=0;i<n;i++){
            pMin[i]=(i==0)?a[i]:min(a[i],pMin[i-1]);
        }
        for(int i=n-1;i>=0;i--){
            sMax[i]=(i==n-1)?a[i]:max(a[i],sMax[i+1]);
        }
        int ans=1e18;
        for(int i=0;i<n;i++){
            int gain=0;
            if(i<n-1)gain=max(0LL,sMax[i+1]-pMin[i]);
            int damage=gain+pSum[i];
            int t;
            if(damage>=h)t=i+1;
            else{
                int need=h-damage;
                int cyc=(need+sum-1)/sum;
                t=cyc*(n+k)+i+1;
            }
            ans=min(ans,t);
        }
        cout<<ans<<endl;   
    }
    return 0;
}