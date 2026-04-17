#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c; 

signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>a(n,0);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b;
        vector<int>g(n);
        for(int i=0;i<n-1;i++)g[i]=gcd(a[i],a[i+1]);
        int ans=0;
        for(int i=0;i<n;i++){
            int tm=0;
            if(i==0|| i==n-1)tm=(i==0)?g[0]:g[n-2];
            else tm=lcm(g[i-1],g[i]);
            if(tm<a[i])ans++;
        }
        cout<<ans<<endl;        
    }
}